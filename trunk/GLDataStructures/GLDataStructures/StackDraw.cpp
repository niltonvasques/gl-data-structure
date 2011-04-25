#include "StackDraw.h"

StackDraw::StackDraw() : Shape(Color(255,0,0)){
	this->blockWidth = DEFAULT_BLOCK_WIDTH;
	this->blockHeight = DEFAULT_BLOCK_HEIGHT;
	this->originalBlockWidth = this->blockWidth;
	this->originalBlockHeight = this->blockHeight;
	this->xPosition = 0;
}


StackDraw::StackDraw(GLint xPosition_,GLuint blockWidth_, GLuint blockHeight_,Color color_) :Shape(color_) {
	this->blockWidth = blockWidth_;
	this->blockHeight = blockHeight_;
	this->originalBlockWidth = this->blockWidth;
	this->originalBlockHeight = this->blockHeight;
	this->xPosition = xPosition_;
}

//StackDraw::StackDraw(Stack<GLuint> *stack_){
//	//this->stack = stack_;
//}

StackDraw::~StackDraw(){
	GLuint x;
	while(!squareStack.isEmpty()){
		delete(pop(x));
	}
}

int StackDraw::push(GLuint content_){
	this->stack.push(content_);

	SquareShape *squareContent = NULL;
	SquareShape *pick = NULL;
	this->squareStack.pick(pick);
	char *str = (char*) malloc(sizeof(char)*10);
	itoa(content_,str,10);
	if(pick == NULL){
		squareContent = new SquareShape(Rect(this->xPosition,-99,this->blockWidth,this->blockHeight),this->color);
		StringShape *strShape = new StringShape(str,Color(0,0,0),Point(this->xPosition+2,-99+blockHeight/2));
		this-stringStack.push(strShape);
		this->squareStack.push(squareContent);
	}else{
		Rect rect = pick->getRect();
		squareContent = new SquareShape(Rect(rect.x,rect.y+rect.height+1,this->blockWidth,this->blockHeight),this->color);
		StringShape *strShape = new StringShape(str,Color(0,0,0),Point(rect.x+2,rect.y+rect.height+rect.height/2));
		this-stringStack.push(strShape);
		this->squareStack.push(squareContent);
		calcBetterBlockSize(rect,PUSH);
	}
	return 1;
}

SquareShape *StackDraw::pop(GLuint &value){
	this->stack.pop(value);
	StringShape *strShape = NULL;
	this->stringStack.pop(strShape);
	delete(strShape);
	SquareShape *square = NULL;
	this->squareStack.pop(square);
	SquareShape *pick = NULL;
	this->squareStack.pick(pick);
	if(pick != NULL){
		calcBetterBlockSize(pick->getRect(),POP);
	}
	return square;
}

#define RATIO_REDUCE_SIZE 8

void StackDraw::calcBetterBlockSize(Rect rectTopStack,MODE m){
	const GLfloat LIMIAR = ((GLfloat) originalBlockHeight / originalBlockWidth );
	const GLuint MIN_BLOCK_WIDTH = 6;
	const GLuint MIN_BLOCK_HEIGHT = (LIMIAR * (GLfloat) MIN_BLOCK_WIDTH) ; 
	GLuint ratioHeight = ((GLfloat)blockHeight/RATIO_REDUCE_SIZE < 2 ? 2 : (GLfloat)blockHeight/RATIO_REDUCE_SIZE);
	GLuint ratioWidth = ((GLfloat)blockWidth/RATIO_REDUCE_SIZE < 2 ? 2 : (GLfloat)blockWidth/RATIO_REDUCE_SIZE);
	if(m == PUSH){
		if((rectTopStack.y + (int)this->blockHeight) > (QUADRANT_SIZE - this->blockHeight)){
			if(blockHeight == MIN_BLOCK_HEIGHT || blockWidth == MIN_BLOCK_WIDTH) return;
			if( (blockHeight-ratioHeight) > MIN_BLOCK_HEIGHT && (blockWidth-ratioWidth) > MIN_BLOCK_WIDTH){
				blockWidth	= (blockWidth  - ratioWidth);
				blockHeight = (LIMIAR * (GLfloat)blockWidth); 				
			}else{
				blockWidth	= MIN_BLOCK_WIDTH;
				blockHeight = MIN_BLOCK_HEIGHT; 				
			}			
			resizeBlocksStack();
		}
	}
	if(m == POP){
		if(rectTopStack.y <= (QUADRANT_SIZE/2) ){
			if(blockHeight == originalBlockHeight || blockWidth == originalBlockWidth) return;
			if( (blockHeight + ratioHeight) < originalBlockHeight && (blockWidth+ratioWidth) < originalBlockWidth){
				blockWidth	= (blockWidth + ratioWidth);
				blockHeight = (LIMIAR * (GLfloat)blockWidth); 				
			}else{
				blockWidth	= originalBlockWidth;
				blockHeight = originalBlockHeight; 				
			}
			resizeBlocksStack();
		}
	}
}
	

void StackDraw::resizeBlocksStack(){
	Stack<SquareShape*> stackSqr;
	Stack<StringShape*> strStack;
	while(!this->squareStack.isEmpty()){
		SquareShape *sqr = NULL;
		this->squareStack.pop(sqr);
		stackSqr.push(sqr);

		StringShape *str = NULL;
		this->stringStack.pop(str);
		strStack.push(str);
	}
	bool isFirst = true;
	while(!stackSqr.isEmpty()){
		SquareShape *sqr = NULL;
		stackSqr.pop(sqr);
		SquareShape *pick = NULL;
		squareStack.pick(pick);

		StringShape *str = NULL;
		strStack.pop(str);
		this->stringStack.push(str);
		if(pick == NULL){
			sqr->setRect(Rect(this->xPosition,-99,this->blockWidth,this->blockHeight));
			str->setPoint(Point(this->xPosition+2,-99+blockHeight/2));
		}else{
			Rect rect = pick->getRect();		
			sqr->setRect(Rect(rect.x,rect.y+rect.height+1,this->blockWidth,this->blockHeight));
			str->setPoint(Point(rect.x+2,rect.y+rect.height+rect.height/2));
		}
		this->squareStack.push(sqr);
	}
}

void StackDraw::Draw(){
	Stack<SquareShape*> stackSqr;
	Stack<StringShape*> strStack;
 	while(!this->squareStack.isEmpty()){
		SquareShape *sqr = NULL;
		this->squareStack.pop(sqr);
		stackSqr.push(sqr);
		
		StringShape *str = NULL;
		this->stringStack.pop(str);
		strStack.push(str);
	}
	while(!stackSqr.isEmpty()){
		SquareShape *sqr = NULL;
		stackSqr.pop(sqr);
		sqr->Draw();
		this->squareStack.push(sqr);

		StringShape *str = NULL;
		strStack.pop(str);
		str->Draw();
		this->stringStack.push(str);

	}
}
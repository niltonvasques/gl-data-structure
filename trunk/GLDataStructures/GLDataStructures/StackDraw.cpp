#include "StackDraw.h"

StackDraw::StackDraw(){
	this->blockWidth = DEFAULT_BLOCK_WIDTH;
	this->blockHeight = DEFAULT_BLOCK_HEIGHT;
}

StackDraw::StackDraw(GLuint blockWidth_, GLuint blockHeight_) {
	this->blockWidth = blockWidth_;
	this->blockHeight = blockHeight_;
}

//StackDraw::StackDraw(Stack<GLuint> *stack_){
//	//this->stack = stack_;
//}

StackDraw::~StackDraw(){
	GLuint x;
	while(!squareStack.isEmpty()){
		delete(CDisplay::getInstance()->removeShapeN(pop(x)));
	}
}

int StackDraw::push(GLuint content_){
	this->stack.push(content_);

	SquareShape *squareContent = NULL;
	SquareShape *pick = NULL;
	this->squareStack.pick(pick);
	if(pick == NULL){
		squareContent = new SquareShape(Rect(0,-99,this->blockWidth,this->blockHeight));
		this->squareStack.push(squareContent);
	}else{
		Rect rect = pick->getRect();
		squareContent = new SquareShape(Rect(rect.x,rect.y+rect.height+1,this->blockWidth,this->blockHeight));
		this->squareStack.push(squareContent);
		if((rect.y + (int)this->blockHeight) > (QUADRANT_SIZE - this->blockHeight)){
			printf(" rect y  %d blockHeight %d\n rect.y+height %d",rect.y,this->blockHeight,(rect.y + this->blockHeight));
			resizeBlocksStack();
		}
	}
	CDisplay::getInstance()->addShape(squareContent);
	CDisplay::getInstance()->redraw();
	return 1;
}

SquareShape *StackDraw::pop(GLuint &value){
	this->stack.pop(value);
	SquareShape *square = NULL;
	this->squareStack.pop(square);
	return square;
}
#define MIN_BLOCK_WIDTH  4
#define MIN_BLOCK_HEIGHT 2
#define RATIO_REDUCE_SIZE 8
void StackDraw::resizeBlocksStack(){
	if(blockHeight == MIN_BLOCK_HEIGHT || blockWidth == MIN_BLOCK_WIDTH) return;
	GLuint oldHeight = this->blockHeight;
	GLuint oldWidth = this->blockWidth;
	this->blockHeight -= ((GLfloat)blockHeight/RATIO_REDUCE_SIZE > MIN_BLOCK_HEIGHT ?
		(GLfloat)blockHeight/RATIO_REDUCE_SIZE  :	MIN_BLOCK_HEIGHT); 
	this->blockWidth -= ((GLfloat)blockWidth/RATIO_REDUCE_SIZE > MIN_BLOCK_WIDTH ? 
		(GLfloat)blockWidth/RATIO_REDUCE_SIZE	:	MIN_BLOCK_WIDTH);
	Stack<SquareShape*> stackSqr;
	while(!this->squareStack.isEmpty()){
		SquareShape *sqr = NULL;
		this->squareStack.pop(sqr);
		stackSqr.push(sqr);
	}
	bool isFirst = true;
	while(!stackSqr.isEmpty()){
		SquareShape *sqr = NULL;
		stackSqr.pop(sqr);

		SquareShape *pick = NULL;
		squareStack.pick(pick);
		if(pick == NULL){
			sqr->setRect(Rect(0,-99,this->blockWidth,this->blockHeight));
		}else{
			Rect rect = pick->getRect();		
			sqr->setRect(Rect(rect.x,rect.y+rect.height+1,this->blockWidth,this->blockHeight));
		}
		this->squareStack.push(sqr);
	}
}
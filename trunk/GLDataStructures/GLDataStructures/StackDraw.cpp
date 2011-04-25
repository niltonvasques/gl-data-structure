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
	}else{
		Rect rect = pick->getRect();
		squareContent = new SquareShape(Rect(rect.x,rect.y+rect.height+3,this->blockWidth,this->blockHeight));
	}
	this->squareStack.push(squareContent);
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
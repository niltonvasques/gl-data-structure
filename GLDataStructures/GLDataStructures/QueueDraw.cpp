#include "QueueDraw.h"

QueueDraw::QueueDraw(Color color_): Shape(color_){
	this->blockWidth = DEFAULT_BLOCK_WIDTH;
	this->blockHeight = DEFAULT_BLOCK_HEIGHT;
	this->originalBlockWidth = this->blockWidth;
	this->originalBlockHeight = this->blockHeight;
	this->xPosition = 0;
}

QueueDraw::~QueueDraw(){
	while(!shapesQueue.isEmpty()){
		SquareShape *sqr = NULL;
		shapesQueue.remove(sqr);
		delete(sqr);
	}
}

GLint QueueDraw::insert(GLint value){
	SquareShape *squareContent = NULL;
	SquareShape *tail = NULL;
	if(shapesQueue.isEmpty())
		squareContent = new SquareShape(Rect(100 - blockWidth-1,0,this->blockWidth,this->blockHeight),this->color);
	else{
		shapesQueue.pickTail(tail);
		squareContent = new SquareShape(Rect(tail->getRect().x-blockWidth-2,0,this->blockWidth,this->blockHeight),this->color);
	}
	shapesQueue.insert(squareContent);
	return 1;
}

GLint QueueDraw::remove(GLint &ref){
	SquareShape *temp = NULL;
	shapesQueue.remove(temp);
	delete(temp);
	return 1;
}

void QueueDraw::Draw(){
	Queue<SquareShape*> temp;
	while(!shapesQueue.isEmpty()){
		SquareShape* sqr = NULL;
		shapesQueue.remove(sqr);
		sqr->Draw();
		temp.insert(sqr);
	}
	while(!temp.isEmpty()){
		SquareShape* sqr = NULL;
		temp.remove(sqr);
		shapesQueue.insert(sqr);
	}
}

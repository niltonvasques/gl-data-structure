#include <stdio.h>
#include "SquareShape.h"

SquareShape::SquareShape(Point x_,unsigned int width, unsigned int height, Color color) : Shape(color){
	setRect(Rect(x_.x,x_.y,width,height));
}

SquareShape::SquareShape(Rect rect_ , Color color) : Shape(color){
	setRect(rect_);
}


SquareShape::~SquareShape(){

}

void SquareShape::setRect(Rect rect_){
	this->rect = rect_;
	adjustPoints();
}

void SquareShape::adjustPoints(){
	this->a.x = rect.x;
	this->a.y = rect.y + rect.height;
	this->b.x = rect.x;
	this->b.y = rect.y;
	this->c.x = rect.x + rect.width;
	this->c.y = rect.y;
	this->d.x = rect.x + rect.width;
	this->d.y = rect.y + rect.height;
}

Rect SquareShape::getRect(){
	return this->rect;
}

void SquareShape::Draw(){
	//printf("DrawSquare \n   a: x %d y %d\n   b: x %d y %d\n    c: x %d  y: %d\n   d: x %d  y: %d\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);
	glColor3ub(color.red,color.green,color.blue);
	glBegin(GL_QUADS);
		glVertex2i(a.x,a.y);//Primeiro vertice
		glVertex2i(b.x,b.y);//Segund vertice
		glVertex2i(c.x,c.y);//Terceiro vertice
		glVertex2i(d.x,d.y);//Quarto vertice
	glEnd();

}
#include <stdio.h>
#include "SquareShape.h"

SquareShape::SquareShape(Point x_,unsigned int width, unsigned int height, Color color){
	this->a.x = x_.x;
	this->a.y = x_.y + height;
	this->b.x = x_.x;
	this->b.y = x_.y;
	this->c.x = x_.x + width;
	this->c.y = x_.y;
	this->d.x = x_.x + width;
	this->d.y = x_.y + height;
	this->color = color;
}

SquareShape::SquareShape(Rect rect , Color color){
	SquareShape(Point(rect.x,rect.y),rect.width,rect.height,color);
}


SquareShape::~SquareShape(){

}

void SquareShape::Draw(){
	printf("DrawSquare \n   a: x %d y %d\n   b: x %d y %d\n    c: x %d  y: %d\n   d: x %d  y: %d\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);
	glColor3ub(color.red,color.green,color.blue);
	glBegin(GL_QUADS);
		glVertex2i(a.x,a.y);//Primeiro vertice
		glVertex2i(b.x,b.y);//Segund vertice
		glVertex2i(c.x,c.y);//Terceiro vertice
		glVertex2i(d.x,d.y);//Quarto vertice
	glEnd();

}
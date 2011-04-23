#include "PointShape.h"
#include <stdio.h>

PointShape::PointShape(Point a_,GLfloat ptSize_,Color color_) : Shape(color_){
	this->a = a_;
	this->ptSize = ptSize_;

}
PointShape::PointShape(Point a_,Color color_) : Shape(color_){
	this->a = a_;
	this->ptSize = 1.0f;
}

PointShape::~PointShape(){

}

void PointShape::setPoint(Point a_){
	this->a = a_;
}

void PointShape::Draw(){
	printf("Chamado\n");	
	glColor4ub(this->color.red,this->color.green,this->color.blue,this->color.alpha);
	glPointSize(this->ptSize);
	glBegin(GL_POINTS);
	glVertex2iv(this->a.vet);
	glEnd();
}
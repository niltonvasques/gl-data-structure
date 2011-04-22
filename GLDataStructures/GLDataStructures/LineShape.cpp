#include "LineShape.h"

LineShape::LineShape(Point a_, GLint width_, Color color_) : Shape(color_){
	this->a = a_;
	this->b = Point(a_.x + width_,a_.y);
}
LineShape::LineShape(Point a_, Point b_, Color color_) : Shape(color_){
	this->a = a_;
	this->b = b_;
}

LineShape::~LineShape(){

}

void LineShape::setPoint(Point a_, Point b_){
	this->a = a_;
	this->b = b_;
}

void LineShape::Draw(){
	glColor4ub(this->color.red,this->color.green,this->color.blue,this->color.alpha);
	glBegin(GL_LINES);
	glVertex2i(this->a.x,this->a.y);
	glVertex2i(this->b.x, this->b.y);
	glEnd();
}
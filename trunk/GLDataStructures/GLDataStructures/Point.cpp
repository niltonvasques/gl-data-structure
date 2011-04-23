#include "Point.h"

Point::Point(void){

}

Point::Point(GLint x_, GLint y_){
	x = x_;
	y = y_;
	this->vet[0] = x_;
	this->vet[1] = y_;
}

Point::~Point(){

}
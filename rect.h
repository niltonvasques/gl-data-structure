#ifndef RECT_H
#define RECT_H
#include "Point.h"

class Rect : public Point{
	
public:
	Rect(){Rect(0,0,0,0);}
	Rect(int x_, int y_,int width_,int height_) : Point(x_,y_){
		this->width = width_;
		this->height = height_;
	}
	virtual ~Rect(){};

	int width;
	int height;

};

#endif
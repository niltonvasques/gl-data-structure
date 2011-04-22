#ifndef LINE_SHAPE_H
#define LINE_SHAPE_H

#include "Shape.h"

class LineShape : public Shape {

public:
	LineShape(Point a_, GLint width_s,Color color = Color(255,0,0));
	LineShape(Point a_, Point b_,Color color = Color(255,0,0));
	virtual ~LineShape();

	virtual void Draw();

	void setPoint(Point a_, Point b_);

private:
	Point a;
	Point b;
};

#endif
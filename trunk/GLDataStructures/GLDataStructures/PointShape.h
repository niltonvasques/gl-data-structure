#ifndef POINT_SHAPE_H
#define POINT_SHAPE_H

#include "Shape.h"

class PointShape : public Shape {

public:
	PointShape(Point a,GLfloat ptSize,Color color_ = Color(255,0,0));
	PointShape(Point a,Color color_ = Color(255,0,0));
	virtual ~PointShape();

	virtual void Draw();
	
	void setPoint(Point a_);

private:
	Point a;
	GLfloat ptSize;

};
#endif
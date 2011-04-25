#ifndef STRING_SHAPE_H
#define STRING_SHAPE_H

#include <GL/glut.h>
#include "Shape.h"

class StringShape : public Shape{
	
public:
	StringShape(char* string_,Color color_,Point xyStart_);
	virtual ~StringShape();

	virtual void Draw();

	void setPoint(Point xyStart_);


private: 
	char* string;
	Point xyStart;
	
};


#endif
#ifndef TEST_SHAPE_H
#define TEST_SHAPE_H
#include <GL/glut.h>
#include "Shape.h"

class TestShape : public Shape {

public:
	TestShape();
	virtual ~TestShape();
	virtual void Draw();
};

#endif
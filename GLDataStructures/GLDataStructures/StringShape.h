#ifndef STRING_SHAPE_H
#define STRING_SHAPE_H

#include <GL/glut.h>
#include "Shape.h"

#define DEFAULT_LINE_WIDTH 1
class StringShape : public Shape{
	
public:
	StringShape(char* string_,Color color_,Point xyStart_,GLuint fontSize = 10);
	virtual ~StringShape();

	virtual void Draw();

	void setPoint(Point xyStart_);

	void setAntiAlias(bool enabled);

enum LineWidth{
	TESTE,TESTE2
	};
private: 
	char* string;
	Point xyStart;
	GLfloat fontSizeFloat;
	bool antiAlias;
	
};


#endif
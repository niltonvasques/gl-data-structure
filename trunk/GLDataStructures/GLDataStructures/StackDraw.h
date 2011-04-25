#ifndef STACK_DRAW_H
#define STACK_DRAW_H

#include "Display.h"
#include <GL/glut.h>
#include "SquareShape.h"
#include "StringShape.h"
#include "stack.h"

class StackDraw : public Shape{
#define DEFAULT_BLOCK_WIDTH  20	
#define	DEFAULT_BLOCK_HEIGHT 10
	enum {
		PUSH,POP
	}typedef MODE;
public:
	StackDraw();
	StackDraw(GLint xPosition_,GLuint blockWidth_, GLuint blockHeight_,Color color_);
	//StackDraw(Stack<GLuint> *stack);
	virtual ~StackDraw();
	
	virtual void Draw();
	int push(GLuint content_);
	SquareShape *pop(GLuint &value);

private:
	Stack<SquareShape*> squareStack;
	Stack<StringShape*> stringStack;
	Stack<GLuint> stack;
	GLuint blockWidth;
	GLuint blockHeight;
	GLuint originalBlockWidth;
	GLuint originalBlockHeight;
	GLint xPosition;
	void resizeBlocksStack();
	void calcBetterBlockSize(Rect rect,MODE m);

};
#endif
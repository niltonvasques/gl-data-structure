#ifndef STACK_DRAW_H
#define STACK_DRAW_H

#include "Display.h"
#include <GL/glut.h>
#include "SquareShape.h"
#include "stack.h"

class StackDraw{
#define DEFAULT_BLOCK_WIDTH  20	
#define	DEFAULT_BLOCK_HEIGHT 10
	enum {
		PUSH,POP
	}typedef MODE;
public:
	StackDraw();
	StackDraw(GLuint blockWidth_, GLuint blockHeight_);
	//StackDraw(Stack<GLuint> *stack);
	virtual ~StackDraw();

	int push(GLuint content_);
	SquareShape *pop(GLuint &value);

private:
	Stack<SquareShape*> squareStack;
	Stack<GLuint> stack;
	GLuint blockWidth;
	GLuint blockHeight;
	GLuint originalBlockWidth;
	GLuint originalBlockHeight;
	void resizeBlocksStack();
	void calcBetterBlockSize(Rect rect,MODE m);

};
#endif
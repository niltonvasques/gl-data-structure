/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do ínicio da implementação: 20/04/2011
  Data da última modificação: 16/05/2011

  Implementação da classe StackDraw que é responsavel representar graficamente
  a estrutura de pilha.
-----------------------------------------------------------------------------*/
#ifndef STACK_DRAW_H
#define STACK_DRAW_H

#include "Display.h"
#include <GL/glut.h>
#include "SquareShape.h"
#include "StringShape.h"
#include "stack.h"
#include "Animation.h"

class StackDraw : public Shape, public AnimationListener{
#define DEFAULT_BLOCK_WIDTH  20	
#define	DEFAULT_BLOCK_HEIGHT 10
#define RATIO_REDUCE_SIZE 8
#define MIN_BLOCK_WIDTH 10
enum {
	PUSH,POP
}typedef MODE;
public:
	StackDraw();
	StackDraw(GLint xPosition_,GLuint blockWidth_, GLuint blockHeight_,Color color_);
	//StackDraw(Stack<GLuint> *stack);
	virtual ~StackDraw();
	
	virtual void Draw();
	virtual int animation();
	virtual void onAnimationFinish(Shape *shape);

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
	SquareShape* lastSquarePoped;

};
#endif
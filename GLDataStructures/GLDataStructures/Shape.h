/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do ínicio da implementação: 18/04/2011
  Data da última modificação: 19/04/2011

  Implementação de estruturas geométricas em OPENGL usando Orientação Objetos
  para encapsular as rotinas da GL.
-----------------------------------------------------------------------------*/
#ifndef SHAPE_H
#define SHAPE_H
#include <GL/glut.h>

class Shape {

public:
	void Draw(void);	

private:
	virtual void GlutDraw() = 0;
	static void drawShape();
	static void registerDisplayFunc(Shape *p);
	static Shape *shape;
	static bool functionRegisted;
};

#endif
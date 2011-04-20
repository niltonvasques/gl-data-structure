/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do ínicio da implementação: 18/04/2011
  Data da última modificação: 19/04/2011

  Implementação da forma geométrica triângulo em OPENGL usando Orientação Objetos
  para encapsular as rotinas da biblioteca.
-----------------------------------------------------------------------------*/
#ifndef TRIANGLE_SHAPE_H
#define TRIANGLE_SHAPE_H

#include <GL/glut.h>
#include "Shape.h"
#include "Point.h"

class TriangleShape :
	public Shape
{

public:
	TriangleShape(void);
	TriangleShape(Point x_,Point y_,Point z_);
	virtual ~TriangleShape(void);

private:
	virtual void GlutDraw();
	Point a,b,c;

};
#endif /*Fim da classe de desenho de formas */
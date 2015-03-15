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
#ifndef SQUARE_SHAPE_H
#define SQUARE_SHAPE_H

#include <GL/glut.h>
#include "Shape.h"
#include "rect.h"
#include "color.h"
#include "Point.h"

class SquareShape :
	public Shape
{

public:
	SquareShape(Point x_,unsigned int width, unsigned int height , Color color = Color(255, 0, 0));
	SquareShape(Rect rect , Color color = Color(255, 0, 0));
	virtual ~SquareShape(void);
	
	virtual void Draw();
	virtual int animation();

	void adjustPoints();
	void setRect(Rect rect);
	Rect getRect();

private:
	Point a,b,c,d;
	Rect rect;

};
#endif /*Fim da classe de desenho de formas */
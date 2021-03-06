/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do �nicio da implementa��o: 18/04/2011
  Data da �ltima modifica��o: 19/04/2011

  Implementa��o da forma geom�trica tri�ngulo em OPENGL usando Orienta��o Objetos
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
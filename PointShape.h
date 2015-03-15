/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do �nicio da implementa��o: 18/04/2011
  Data da �ltima modifica��o: 24/04/2011

  Implementa��o da classe Ponto que referencia um ponto em um plano cartesiano
  tendo como linha horizontal X, e linha vertical Y.
-----------------------------------------------------------------------------*/
#ifndef POINT_SHAPE_H
#define POINT_SHAPE_H

#include "Shape.h"

class PointShape : public Shape {

public:
	PointShape(Point a,GLfloat ptSize,Color color_ = Color(255,0,0));
	PointShape(Point a,Color color_ = Color(255,0,0));
	virtual ~PointShape();

	virtual void Draw();
	
	void setPoint(Point a_);

private:
	Point a;
	GLfloat ptSize;

};
#endif
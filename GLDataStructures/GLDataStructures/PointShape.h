/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do ínicio da implementação: 18/04/2011
  Data da última modificação: 24/04/2011

  Implementação da classe Ponto que referencia um ponto em um plano cartesiano
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
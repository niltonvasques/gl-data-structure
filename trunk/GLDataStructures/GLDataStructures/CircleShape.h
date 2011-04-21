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
#ifndef CIRCLE_SHAPE_H
#define CIRCLE_SHAPE_H

#include <GL/glut.h>
#include "Shape.h"
#include "color.h"
#include "Point.h"

class CircleShape :
	public Shape
{

public:
	CircleShape(Point center_,GLuint radius_, Color color = Color(255, 0, 0));
	virtual ~CircleShape(void);

	void setCenter(Point center_);
	void setRadius(GLuint radius_);
	

private:
	virtual void Draw();
	Point center;
	GLuint radius;

};
#endif /*Fim da classe de desenho de formas */
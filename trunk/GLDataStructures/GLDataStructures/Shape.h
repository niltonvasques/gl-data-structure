/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do �nicio da implementa��o: 18/04/2011
  Data da �ltima modifica��o: 19/04/2011

  Implementa��o de estruturas geom�tricas em OPENGL usando Orienta��o Objetos
  para encapsular as rotinas da GL.
-----------------------------------------------------------------------------*/
#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glut.h>
#include "utils.h"

class Shape {

public:
	Shape(Color color_){
		setColor(color_);
	}
	virtual void Draw() = 0;

	void setColor(Color color_) { this->color = color_;};
protected:
	Color color;
};


#endif
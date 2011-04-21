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
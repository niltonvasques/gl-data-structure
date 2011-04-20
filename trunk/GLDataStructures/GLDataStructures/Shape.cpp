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
#include "Shape.h"
#include <stdio.h>

Shape *Shape::shape = NULL;
bool Shape::functionRegisted = false;
void Shape::Draw(){
	if(Shape::functionRegisted){
		Shape::shape = this;
		Shape::drawShape();
	}else Shape::registerDisplayFunc(this);
}

//STATICS METHODS
void Shape::registerDisplayFunc(Shape *p){
	Shape::shape = p;
	glutDisplayFunc(drawShape);
	Shape::functionRegisted = true;
}

void Shape::drawShape(){
	printf("passando\n");
	if(Shape::shape != NULL)
		Shape::shape->GlutDraw();
}
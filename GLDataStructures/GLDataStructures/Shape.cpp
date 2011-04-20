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
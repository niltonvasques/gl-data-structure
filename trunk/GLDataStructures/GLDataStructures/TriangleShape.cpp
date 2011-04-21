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
#include <stdio.h>
#include <stdlib.h>
#include "TriangleShape.h"

TriangleShape::TriangleShape(Point x_,unsigned int width, unsigned int height, Color color){
	this->a = x_;
	this->b.x = x_.x + width / 2 ;
	this->b.y = (x_.y + height);
	this->c.x = (x_.x + width);
	this->c.y = x_.y;
	this->color = color;
}

TriangleShape::~TriangleShape(){

}

void TriangleShape::Draw(){
	//printf("DrawTriangulo a: x %d y %d   b: x %d y %d    c: x %d  y: %d\n",a.x,a.y,b.x,b.y,c.x,c.y);
	glColor3ub(color.red,color.green,color.blue);
	glBegin(GL_TRIANGLES);
		glVertex2f(a.x,a.y);//Primeiro vertice
		glVertex2f(b.x,b.y);//Segund vertice
		glVertex2f(c.x,c.y);//Terceiro vertice
	glEnd();

}
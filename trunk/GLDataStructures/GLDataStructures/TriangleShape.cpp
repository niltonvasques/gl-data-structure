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
#include <stdio.h>
#include <stdlib.h>
#include "TriangleShape.h"

TriangleShape::TriangleShape(Point x_, Point y_, Point z_, Color color){
	this->a = x_;
	this->b = y_;
	this->c = z_;
	this->color = color;
}

TriangleShape::~TriangleShape(){

}

void TriangleShape::Draw(){
	printf("DrawTriangulo\n");
	//glClearColor(0,1,0,0);
	glColor3ub(color.red,color.green,color.blue);
	glBegin(GL_TRIANGLES);
		glVertex2f(a.x,a.y);//Primeiro vertice
		glVertex2f(b.x,b.y);//Segund vertice
		glVertex2f(c.x,c.y);//Terceiro vertice
	glEnd();

}
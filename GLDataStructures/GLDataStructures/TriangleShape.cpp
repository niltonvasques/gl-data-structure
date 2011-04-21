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

TriangleShape::TriangleShape(Point x_,GLuint width_, GLuint height_, Color color_) : Shape(color_){
	this->width = width_;
	this->height = height_;
	setPoint(x_);
}

TriangleShape::~TriangleShape(){

}

void TriangleShape::setPoint(Point point){
	this->a = point;
	this->b.x = point.x + this->width / 2 ;
	this->b.y = (point.y + this->height);
	this->c.x = (point.x + this->width);
	this->c.y = point.y;
}

void TriangleShape::Draw(){
	//printf("DrawTriangulo a: x %d y %d   b: x %d y %d    c: x %d  y: %d\n",a.x,a.y,b.x,b.y,c.x,c.y);
	glColor4ub(color.red,color.green,color.blue,color.alpha);
	glBegin(GL_TRIANGLES);
		glVertex2f(a.x,a.y);//Primeiro vertice
		glVertex2f(b.x,b.y);//Segund vertice
		glVertex2f(c.x,c.y);//Terceiro vertice
	glEnd();

}
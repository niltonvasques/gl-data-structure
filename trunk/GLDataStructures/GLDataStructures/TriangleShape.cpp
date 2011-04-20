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
#include "TriangleShape.h"

TriangleShape::TriangleShape(void){
	this->a = Point(1,1);
	this->b = Point(1,1);
	this->c = Point(1,1);
}

TriangleShape::TriangleShape(Point x_, Point y_, Point z_){
	this->a = x_;
	this->b = y_;
	this->c = z_;
}

TriangleShape::~TriangleShape(){

}

void TriangleShape::GlutDraw(){
	//glClearColor(0,1,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255,0,0);
	glBegin(GL_TRIANGLES);
		glVertex2f(a.x,a.y);//Primeiro vertice
		glVertex2f(b.x,b.y);//Segund vertice
		glVertex2f(c.x,c.y);//Terceiro vertice
	glEnd();
	glFlush();
}
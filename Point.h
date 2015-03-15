/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do ínicio da implementação: 18/04/2011
  Data da última modificação: 19/04/2011

  Implementação da classe Point que recebe como argumento no construtor as 
  coordenadas cartesianas do mesmo.
-----------------------------------------------------------------------------*/
#ifndef POINT_H
#define POINT_H

#include <GL/glut.h>

class Point{
	
public:
	Point(void);
	Point(int x_, int y_);
	virtual ~Point(void);

	GLint vet[2];
	GLint x;
	GLint y;
};

#endif
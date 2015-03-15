/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do �nicio da implementa��o: 18/04/2011
  Data da �ltima modifica��o: 19/04/2011

  Implementa��o da classe Point que recebe como argumento no construtor as 
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
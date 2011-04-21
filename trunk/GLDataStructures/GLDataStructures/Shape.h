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

class Shape {

public:
	virtual void Draw() = 0;
};


#endif
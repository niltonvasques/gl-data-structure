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
#include "Point.h"

Point::Point(void){

}

Point::Point(GLint x_, GLint y_){
	x = x_;
	y = y_;
	this->vet[0] = x_;
	this->vet[1] = y_;
}

Point::~Point(){

}
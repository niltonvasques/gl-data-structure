/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autors: Nilton Vasques 
  Data do �nicio da implementa��o: 13/05/2011
  Data da �ltima modifica��o: 16/05/2011

  Implementa��o da classe Animation respons�vel por animar um componente na tela
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include "Animation.h"

Animation::Animation(Shape *shape_){
	animListener = NULL;
	shape = shape_;
}

Animation::~Animation(){
	if(animListener != NULL) animListener->onAnimationFinish(shape);
}

void Animation::setAnimationListener(AnimationListener *listener){
	this->animListener = listener;
}

int Animation::update(){
	return shape->animation();
}

void Animation::stop(){

}
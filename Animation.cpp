/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autors: Nilton Vasques 
  Data do ínicio da implementação: 13/05/2011
  Data da última modificação: 16/05/2011

  Implementação da classe Animation responsável por animar um componente na tela
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
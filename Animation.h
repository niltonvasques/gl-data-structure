/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autors: Nilton Vasques 
  Data do ínicio da implementação: 13/05/2011
  Data da última modificação: 16/05/2011

  Implementação da classe Animation responsável por animar um componente na tela
-----------------------------------------------------------------------------*/
#ifndef ANIMATION_H
#define ANIMATION_H

#include "Shape.h"

class AnimationListener{

	public:
		virtual void onAnimationFinish(Shape *shape) = 0;
};

class Animation{

public:
	Animation(Shape *shape_);

	~Animation();

	void setAnimationListener(AnimationListener *listener);

	int update();

	void stop();

private:
	Shape *shape;
	AnimationListener *animListener;
};

#endif
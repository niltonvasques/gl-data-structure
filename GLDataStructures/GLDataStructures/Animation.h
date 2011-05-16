/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autors: Nilton Vasques 
  Data do �nicio da implementa��o: 13/05/2011
  Data da �ltima modifica��o: 16/05/2011

  Implementa��o da classe Animation respons�vel por animar um componente na tela
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
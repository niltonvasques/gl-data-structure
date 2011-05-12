#ifndef FADE_ANIMATION_H
#define FADE_ANIMATIO_H

#include "Animation.h"
#include "SquareShape.h"

class FadeAnimation: public Animation{

public:

	FadeAnimation(SquareShape *square_);
	virtual ~FadeAnimation();

	virtual void start();
	virtual void stop();
private:
	SquareShape *square;

};

#endif
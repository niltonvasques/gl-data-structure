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
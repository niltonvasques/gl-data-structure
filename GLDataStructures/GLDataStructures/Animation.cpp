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
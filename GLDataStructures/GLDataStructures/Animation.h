#ifndef ANIMATION_H
#define ANIMATION_H

class Animation{

public:
	virtual ~Animation(){

	}

	virtual int update() = 0;
	virtual void stop() = 0;
};

#endif
#ifndef COLOR_H
#define COLOR_H

class Color{
	
public:
	Color(){Color(255, 255, 255);}
	Color(unsigned char red_, unsigned char green_, unsigned char blue_, unsigned char alpha_ = 255) :
	  red(red_),
	  green(green_),
	  blue(blue_),
	  alpha(alpha_)
	{}

	~Color(){}

	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};

#endif
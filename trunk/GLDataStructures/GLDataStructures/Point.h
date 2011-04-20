#ifndef POINT_H
#define POINT_H

class Point{
	
public:
	Point(void);
	Point(int x_, int y_);
	virtual ~Point(void);

	int x;
	int y;
};

#endif
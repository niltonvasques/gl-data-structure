#ifndef DISPLAY_H
#define DISPLAY_H


#include <map>
#include "Shape.h"

class CDisplay {
public:

	static CDisplay* getInstance();

	void initialize();
	void setKeyboardFunc(void (__cdecl *func)(unsigned char, int, int));
	void addShape(Shape* shape);
	void redraw();
	void run();

private:

	CDisplay();
	~CDisplay();

	static void dispatchDraw();
	static void resizeWindow(GLsizei w, GLsizei h);
	static CDisplay *instance;

	std::map<Shape*, Shape*> shapes;

};

#endif
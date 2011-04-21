#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "keycodes.h"
#include "Display.h"
#include "TriangleShape.h"

void keyPressedListener(unsigned char key, int x, int y);
void resizeWindow(GLsizei w, GLsizei h);
void inicializa();

#define WINDOW_TITLE "GL Studys"
#define INIT_X 700
#define INIT_Y 50

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

void keyboardListener(unsigned char key, int x, int y);

int main(int argc, const char* argv[]){
	CDisplay::getInstance()->initialize();
	CDisplay::getInstance()->setKeyboardFunc(keyboardListener);
	CDisplay::getInstance()->run();
	return 0;
}

void keyboardListener(unsigned char key, int x, int y){
	switch(key){
		case KEY_ESCAPE:
			exit(0);
			break;
		case KEY_KEY_1:{
			TriangleShape *triangle = new TriangleShape(Point(-30,-49),Point(0,49),Point(30,-49), Color(255, 0, 0));
			CDisplay::getInstance()->addShape(triangle);
			CDisplay::getInstance()->redraw();
			break;
		}
		case KEY_KEY_2:{

			TriangleShape *triangle2 = new TriangleShape(Point(-30,-49),Point(-10,0),Point(-20,-49), Color(0, 255, 0));
			CDisplay::getInstance()->addShape(triangle2);
			CDisplay::getInstance()->redraw();
			break;
		}
	}
}


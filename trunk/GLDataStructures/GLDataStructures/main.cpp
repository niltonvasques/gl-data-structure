#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "keycodes.h"
#include "Display.h"
#include "TriangleShape.h"

using namespace std;

void keyboardListener(unsigned char key, int x, int y);

TriangleShape *lastTriangle = NULL;

void setLastTriangle(TriangleShape *triangleSh){
	lastTriangle = triangleSh;
}

int main(int argc, const char* argv[]){
	CDisplay::getInstance()->initialize();
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListener);
	CDisplay::getInstance()->run();
	return 0;
}

void keyboardListener(unsigned char key, int x, int y){
	TriangleShape *triangle = NULL;
	switch(key){
		case KEY_ESCAPE:
			exit(0);
			break;
		case KEY_KEY_1:
			triangle = new TriangleShape(Point(30,49),30,50, Color(255, 0, 0));
			setLastTriangle(triangle);
			CDisplay::getInstance()->addShape(triangle);
			CDisplay::getInstance()->redraw();
			break;
		
		case KEY_KEY_2:
			triangle = new TriangleShape(Point(50,30),10,50, Color(0, 255, 0));
			setLastTriangle(triangle);
			CDisplay::getInstance()->addShape(triangle);
			CDisplay::getInstance()->redraw();			
			break;		

		case KEY_KEY_3:
			//Exemplo da remoção de um shape da tela
			delete(CDisplay::getInstance()->removeShapeN(lastTriangle));
			lastTriangle = NULL;
			CDisplay::getInstance()->redraw();
			break;
		case KEY_KEY_4:
			//Exemplo da remoção de todos os shapes da tela
			std::map<Shape*,Shape*> shapes = CDisplay::getInstance()->removeAllShapesN();
			for(std::map<Shape*,Shape*>::iterator it = shapes.begin(); it != shapes.end() ; it++ ){
				delete(it->second);
			}
			CDisplay::getInstance()->redraw();
			break;
	}
}
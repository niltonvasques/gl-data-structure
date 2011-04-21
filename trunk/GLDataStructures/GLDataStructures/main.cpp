#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "utils.h"
#include "Display.h"
#include "shapes.h"

using namespace std;

void keyboardListener(unsigned char key, int x, int y);

Shape *lastShape = NULL;

int main(int argc, const char* argv[]){
	CDisplay::getInstance()->initialize();
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListener);
	CDisplay::getInstance()->setBackgroundColor(Color());
	CDisplay::getInstance()->run();
	return 0;
}

void keyboardListener(unsigned char key, int x, int y){
	TriangleShape *triangle = NULL;
	SquareShape *square = NULL;
	CircleShape *circle = NULL;
	switch(key){
		case KEY_ESCAPE:
			exit(0);
			break;
		case KEY_KEY_1:
			//Exemplo da adição de um shape a tela
			//triangle = new TriangleShape(Point(30,49),30,50, Color(255, 0, 0));
			//lastShape = triangle;
			circle = new CircleShape(Point(50,50),30);
			CDisplay::getInstance()->addShape(circle);
			//CDisplay::getInstance()->addShape(triangle);
			CDisplay::getInstance()->redraw();
			break;
		
		case KEY_KEY_2:
			//Exemplo da adição de um shape a tela
			square = new SquareShape(Rect(10,20,20,20), Color(0, 255, 0));
			lastShape = square;
			CDisplay::getInstance()->addShape(square);
			CDisplay::getInstance()->redraw();			
			break;		
		case KEY_KEY_3:
			//Exemplo da remoção de um shape da tela
			delete(CDisplay::getInstance()->removeShapeN(lastShape));
			lastShape = NULL;
			CDisplay::getInstance()->redraw();
			break;
		case KEY_KEY_4:{
			//Exemplo da remoção de todos os shapes da tela
			std::map<Shape*,Shape*> shapes = CDisplay::getInstance()->removeAllShapesN();
			for(std::map<Shape*,Shape*>::iterator it = shapes.begin(); it != shapes.end() ; it++ ){
				delete(it->second);
				lastShape = NULL;
			}
			CDisplay::getInstance()->redraw();
			break;
		}
		case KEY_KEY_5:
			//Redimensionando o shape
			CDisplay::getInstance()->setBackgroundColor(Color());
			CDisplay::getInstance()->redraw();
			break;
	}
}
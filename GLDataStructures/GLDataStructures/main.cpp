#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "utils.h"
#include "Display.h"
#include "shapes.h"


using namespace std;

void keyboardListener(unsigned char key, int x, int y);
void drawAnimationPointer();
void deleteShapesDisplay();

int main(int argc, const char* argv[]){
	CDisplay::getInstance()->initialize(); //função que chamas as funções de inicializaçao da glut e desenha a janela.
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListener);//Função que registra a função que será o callback das entradas de teclado
	CDisplay::getInstance()->setBackgroundColor(Color());//Seta a cor de fund
	CDisplay::getInstance()->run();//Inicia o main loop da gl...
	return 0;
}

void keyboardListener(unsigned char key, int x, int y){
	Shape *shape = NULL;
	switch(key){
		case KEY_ESCAPE:
			exit(0);
			break;
		case KEY_KEY_1:
			//Exemplo da adição de um shape a tela
			shape = new CircleShape(Point(0,0),30,Color(0,0,255));
			CDisplay::getInstance()->addShape(shape);
			CDisplay::getInstance()->redraw();
			break;
		
		case KEY_KEY_2:
			//Exemplo da adição de um shape a tela
			//shape = new SquareShape(Rect(10,20,20,20), Color(0, 255, 0));
			shape = new TestShape();
			CDisplay::getInstance()->addShape(shape);
			CDisplay::getInstance()->redraw();			
			break;		
		case KEY_KEY_3:
			//Exemplo da adição de um shape a tela
			drawAnimationPointer();
			break;
		case KEY_KEY_4:{
			//Exemplo da remoção de todos os shapes da tela
			deleteShapesDisplay();
			break;
		}
		case KEY_KEY_5:
			//Pintando o background
			CDisplay::getInstance()->setBackgroundColor(Color(255,255,0));
			CDisplay::getInstance()->redraw();
			break;
	}
}


void drawAnimationPointer(){
	Shape *shape = new LineShape(Point(0,0),Point(-100,0));
	CDisplay::getInstance()->addShape(shape);
	//for(;;){
		for(int x = -100, y = 0; y != -1 || x != -100; ){
			if( x == 100 && y > -100) y--;
			else if(x == -100 && y < 100) y++;
			else if( y == 100 && x < 100) x++;
			else if(y == -100 && x > -100) x--;
			((LineShape*)shape)->setPoint(Point(0,0),Point(x,y));
			CDisplay::getInstance()->redraw();
			sleep(2);
		}
	//}
	delete(CDisplay::getInstance()->removeShapeN(shape));
}

void deleteShapesDisplay(){
	std::map<Shape*,Shape*> shapes = CDisplay::getInstance()->removeAllShapesN();
	int i = 0;
	for(std::map<Shape*,Shape*>::iterator it = shapes.begin(); it != shapes.end() ; it++ ,i++){
		printf("deletandooo....%d\n",i);
		delete(it->second);
	}
	CDisplay::getInstance()->redraw();
}
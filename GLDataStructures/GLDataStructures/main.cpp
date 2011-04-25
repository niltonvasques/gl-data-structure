#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "utils.h"
#include "Display.h"
#include "shapes.h"
#include "stack.h"
#include "StackDraw.h"

using namespace std;

void keyboardListener(unsigned char key, int x, int y);
void deleteShapesDisplay();

StackDraw *stackDraw;
StackDraw *stackDraw2;

int main(int argc, const char* argv[]){
	srand(time(NULL));
	CDisplay::getInstance()->initialize(); //função que chamas as funções de inicializaçao da glut e desenha a janela.
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListener);//Função que registra a função que será o callback das entradas de teclado
	CDisplay::getInstance()->setBackgroundColor(Color(255,255,255));//Seta a cor de fund
	stackDraw = new StackDraw(0,30,20,Color(0,0,255));
	stackDraw2 = new StackDraw(-50,8,8,Color(0,255,0));
	CDisplay::getInstance()->addShape(stackDraw);
	CDisplay::getInstance()->addShape(stackDraw2);
	CDisplay::getInstance()->run();//Inicia o main loop da gl...

	delete(CDisplay::getInstance()->removeShapeN(stackDraw));
	delete(CDisplay::getInstance()->removeShapeN(stackDraw2));
	return 0;
}
void keyboardListener(unsigned char key, int x, int y){
	Shape *shape = NULL;
	switch(key){
		case KEY_ESCAPE:
			//TODO: Bug se os shapes estiverem na stack
			//deleteShapesDisplay();
			exit(0);
			break;
		case KEY_KEY_1:{
			//Adição de um bloco na pilha STACK->PUSH
			stackDraw->push(rand()%100);			
			CDisplay::getInstance()->redraw();
			/*delete(CDisplay::getInstance()->removeShapeN(stackDraw));*/
		}
			break;
		case KEY_KEY_2:{
			//Remoção de um bloco na pilha STACK->POP
			GLuint value;
			delete(stackDraw->pop(value));
			CDisplay::getInstance()->redraw();
			//deleteShapesDisplay();
			break;
		}
		case KEY_KEY_3:{
			//Adição de um bloco na pilha STACK->PUSH
			stackDraw2->push(rand()%99);			
			CDisplay::getInstance()->redraw();
			/*delete(CDisplay::getInstance()->removeShapeN(stackDraw));*/
		}
			break;
		case KEY_KEY_4:{
			//Remoção de um bloco na pilha STACK->POP
			GLuint value;
			delete(stackDraw2->pop(value));
			CDisplay::getInstance()->redraw();
			//deleteShapesDisplay();
			break;
		}
		case KEY_KEY_5:
			//Pintando o background
			CDisplay::getInstance()->setBackgroundColor(Color(255,255,0));
			CDisplay::getInstance()->redraw();
			break;
		case 'a':
			CDisplay::getInstance()->enableAntiAlias();
			break;
	}
}

void deleteShapesDisplay(){
	std::map<Shape*,Shape*> shapes = CDisplay::getInstance()->removeAllShapesN();
	int i = 0;
	for(std::map<Shape*,Shape*>::iterator it = shapes.begin(); it != shapes.end() ; it++ ,i++){
		printf("deletandooo....%d\n",i);
		if(it->second) delete(it->second);
	}
	CDisplay::getInstance()->redraw();
}
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "utils.h"
#include "Display.h"
#include "shapes.h"
#include "stack.h"
#include "StackDraw.h"

using namespace std;

void keyboardListener(unsigned char key, int x, int y);
void deleteShapesDisplay();

StackDraw stackDraw(30,20);

int main(int argc, const char* argv[]){
	CDisplay::getInstance()->initialize(); //função que chamas as funções de inicializaçao da glut e desenha a janela.
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListener);//Função que registra a função que será o callback das entradas de teclado
	CDisplay::getInstance()->setBackgroundColor(Color(255,255,255));//Seta a cor de fund
	CDisplay::getInstance()->run();//Inicia o main loop da gl...
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
			stackDraw.push(10);			
		}
			break;
		case KEY_KEY_2:{
			//Remoção de um bloco na pilha STACK->POP
			GLuint value;
			SquareShape* square = stackDraw.pop(value);
			if(square){
				delete(CDisplay::getInstance()->removeShapeN(square));			
				printf("value %d\n",value);
			}
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
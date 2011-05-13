#include <stdio.h>
#include <time.h>
#include "main_control.h"
#include "StackDraw.h"
#include "QueueDraw.h"

StackDraw *stackDraw = NULL;
QueueDraw *queueDraw = NULL;

void keyboardListenerStack(unsigned char key, int x, int y);
void keyboardListenerQueue(unsigned char key, int x, int y);
void deleteShapesDisplay();

void initGlut(){
	CDisplay::getInstance()->initialize(); //função que chamas as funções de inicializaçao da glut e desenha a janela.
	CDisplay::getInstance()->setBackgroundColor(Color(255,255,255));//Seta a cor de fund
	CDisplay::getInstance()->run();//Inicia o main loop da gl...
}

void stackStartControl(){	
	srand(time(NULL));
	stackDraw = new StackDraw(0,40,40,Color(0,0,255));
	CDisplay::getInstance()->addShape(stackDraw);
	StringShape *string = new StringShape("...Stacks...",Color(0,0,0),Point(-60,75),20);
	string->setAntiAlias(true);
	CDisplay::getInstance()->addShape(string);
	CDisplay::getInstance()->addShape(new StringShape("...Stacks...",Color(255,255,255),Point(-60,75),20));
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListenerStack);//Função que registra a função que será o callback das entradas de teclado
}

void queueStartControl(){
	queueDraw = new QueueDraw(Color());
	StringShape *string = new StringShape("...Queues...",Color(0,0,0),Point(-60,75),20);
	string->setAntiAlias(true);
	CDisplay::getInstance()->addShape(string);
	CDisplay::getInstance()->addShape(new StringShape("...Queues...",Color(255,255,255),Point(-60,75),20));
	CDisplay::getInstance()->addShape(queueDraw);
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListenerQueue);//Função que registra a função que será o callback das entradas de teclado
}

void keyboardListenerStack(unsigned char key, int x, int y){
	Shape *shape = NULL;
	switch(key){
		case KEY_ESCAPE:
			deleteShapesDisplay();
			exit(0);
			break;
		case KEY_KEY_1:{
			stackDraw->push(rand()%100);		
		}
			break;
		case KEY_KEY_2:{
			GLuint value;
			stackDraw->pop(value);
			break;
		}
		case KEY_TAB:
			deleteShapesDisplay();
			queueStartControl();
			break;
	}
}

void keyboardListenerQueue(unsigned char key, int x, int y){
	Shape *shape = NULL;
	switch(key){
		case KEY_ESCAPE:
			deleteShapesDisplay();
			exit(0);
			break;
		case KEY_KEY_1:{
			queueDraw->insert(rand()%100);
		}
			break;
		case KEY_KEY_2:{
			GLint value;
			queueDraw->remove(value);
			break;
		}
	   	case KEY_TAB:
			deleteShapesDisplay();
			stackStartControl();
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
}
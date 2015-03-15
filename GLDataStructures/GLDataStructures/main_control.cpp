#include <stdio.h>
#include <time.h>
#include "main_control.h"
#include "StackDraw.h"
#include "QueueDraw.h"

StackDraw *stackDraw = NULL;
QueueDraw *queueDraw = NULL;

bool keyboardGenerics(unsigned char key, int x, int y);
void keyboardListenerStack(unsigned char key, int x, int y);
void keyboardListenerQueue(unsigned char key, int x, int y);
void deleteShapesDisplay();

void initGlut(int argc, char** argv){
	CDisplay::getInstance()->initialize(argc, argv); //fun��o que chamas as fun��es de inicializa�ao da glut e desenha a janela.
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
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListenerStack);//Fun��o que registra a fun��o que ser� o callback das entradas de teclado
}

void queueStartControl(){
	queueDraw = new QueueDraw(Color(255,0,0));
	StringShape *string = new StringShape("...Queues...",Color(0,0,0),Point(-60,75),20);
	string->setAntiAlias(true);
	CDisplay::getInstance()->addShape(string);
	CDisplay::getInstance()->addShape(new StringShape("...Queues...",Color(255,255,255),Point(-60,75),20));
	CDisplay::getInstance()->addShape(queueDraw);
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListenerQueue);//Fun��o que registra a fun��o que ser� o callback das entradas de teclado
}


bool keyboardGenerics(unsigned char key, int x, int y){
	switch(key){
		case 'p':
			CDisplay::getInstance()->setPause(!CDisplay::getInstance()->isPause());
			return false;
		case KEY_ESCAPE:
			deleteShapesDisplay();
			exit(0);
			return false;
		default:
			if(CDisplay::getInstance()->isPause()) return false;
			return true;
	}
}

void keyboardListenerStack(unsigned char key, int x, int y){
	Shape *shape = NULL;
	if(!keyboardGenerics(key,x,y)) return;
	switch(key){
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

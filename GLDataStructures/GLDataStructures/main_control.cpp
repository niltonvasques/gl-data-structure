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

void stackStartControl(){	
	srand(time(NULL));
	CDisplay::getInstance()->initialize(); //função que chamas as funções de inicializaçao da glut e desenha a janela.
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListenerStack);//Função que registra a função que será o callback das entradas de teclado
	CDisplay::getInstance()->setBackgroundColor(Color(255,255,255));//Seta a cor de fund
	stackDraw = new StackDraw(0,40,40,Color(0,0,255));
	
	CDisplay::getInstance()->addShape(stackDraw);

	StringShape *string = new StringShape("...Stacks...",Color(0,0,0),Point(-60,75),20);
	string->setAntiAlias(true);
	CDisplay::getInstance()->addShape(string);
	CDisplay::getInstance()->addShape(new StringShape("...Stacks...",Color(255,255,255),Point(-60,75),20));
	CDisplay::getInstance()->run();//Inicia o main loop da gl...
}
//

void queueStartControl(){
	CDisplay::getInstance()->initialize(); //função que chamas as funções de inicializaçao da glut e desenha a janela.
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListenerQueue);//Função que registra a função que será o callback das entradas de teclado
	CDisplay::getInstance()->setBackgroundColor(Color(255,255,255));//Seta a cor de fund
	queueDraw = new QueueDraw(Color());

	StringShape *string = new StringShape("...Queues...",Color(0,0,0),Point(-60,75),20);
	string->setAntiAlias(true);
	CDisplay::getInstance()->addShape(string);
	CDisplay::getInstance()->addShape(new StringShape("...Queues...",Color(255,255,255),Point(-60,75),20));

	CDisplay::getInstance()->addShape(queueDraw);
	CDisplay::getInstance()->run();//Inicia o main loop da gl...	
}

void keyboardListenerStack(unsigned char key, int x, int y){
	Shape *shape = NULL;
	switch(key){
		case KEY_ESCAPE:
			deleteShapesDisplay();
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

void keyboardListenerQueue(unsigned char key, int x, int y){
	Shape *shape = NULL;
	switch(key){
		case KEY_ESCAPE:
			deleteShapesDisplay();
			exit(0);
			break;
		case KEY_KEY_1:{
			queueDraw->insert(rand()%100);
			CDisplay::getInstance()->redraw();
		}
			break;
		case KEY_KEY_2:{
			GLint value;
			queueDraw->remove(value);
			CDisplay::getInstance()->redraw();
			break;
		}
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
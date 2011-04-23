/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autores: Nilton Vasques e Gustavo Neves
  Data do �nicio da implementa��o: 20/04/2011
  Data da �ltima modifica��o: 21/04/2011

  Implementa��o da classe Display que � responsavel por desenhar na tela.
  A mesma recebe por parametro um objeto do tipo Shape.
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Display.h"
#include "Shape.h"

#define WINDOW_TITLE "GL Studys"
#define INIT_X 700
#define INIT_Y 50

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640


using namespace std;

CDisplay *CDisplay::instance = NULL;
void CDisplay::dispatchDraw(){
	int x = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	std::map<Shape*, Shape*> shapes = CDisplay::getInstance()->shapes;
	for (map<Shape*, Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++){
		it->second->Draw();
	}
	glFlush();
}

CDisplay* CDisplay::getInstance(){
	if (!instance) instance = new CDisplay();
	return instance;
}

CDisplay::CDisplay(){
}

CDisplay::~CDisplay(){
}

#define QUADRANT_SIZE 100.0f
void CDisplay::resizeWindow(GLsizei w, GLsizei h){
	// Evita a divisao por zero
	if(h == 0) h = 1;
                           
	// Especifica as dimens�es da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (esquerda, direita, inferior, 
	// superior) mantendo a propor��o com a janela de visualiza��o
	GLdouble left = ( w <= h ? -QUADRANT_SIZE : -QUADRANT_SIZE * w/h);
	GLdouble right = ( w <= h ? QUADRANT_SIZE : QUADRANT_SIZE * w/h);
	GLdouble bottom = ( w <= h ? -QUADRANT_SIZE * h/w : -QUADRANT_SIZE);
	GLdouble top = ( w <= h ? QUADRANT_SIZE * h/w : QUADRANT_SIZE);
	printf("left %f right %f bottom %f bottom %f \n",left,right,bottom,top);
	gluOrtho2D (left, right, bottom, top);
}

void CDisplay::setKeyboardFuncCallback(void (__cdecl *func)(unsigned char, int, int)){
	glutKeyboardFunc(func);
}

void CDisplay::initialize(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	glutDisplayFunc(dispatchDraw);
	//glutIdleFunc(dispatchDraw);
	glMatrixMode(GL_PROJECTION);
	glutReshapeFunc(resizeWindow);
	//glutFullScreen();
}

void CDisplay::setBackgroundColor(Color color){
	glClearColor(color.red,color.green,color.blue,color.alpha);	
}

void CDisplay::run(){
	glutMainLoop();
}

void CDisplay::addShape(Shape* shape){
	shapes[shape] = shape;
}

Shape* CDisplay::removeShapeN(Shape* shape){
	if(shape != NULL) shapes.erase(shape);
	return shape;
}

std::map<Shape*, Shape*> CDisplay::removeAllShapesN(){
	std::map<Shape*, Shape*> ret;
	for (map<Shape*, Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++){
		ret[it->first] = it->second;
	}
	shapes.clear();
	return ret;
}

void CDisplay::redraw(){
	CDisplay::dispatchDraw();
}
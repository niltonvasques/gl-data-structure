#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Display.h"
#include "Shape.h"

#define WINDOW_TITLE "GL Studys"
#define INIT_X 700
#define INIT_Y 50

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


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

void CDisplay::resizeWindow(GLsizei w, GLsizei h){
	// Evita a divisao por zero
	if(h == 0) h = 1;
                           
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	//if (w <= h) 
		gluOrtho2D (0.0f, 100.f, 100.f, 0.0f);
	//else 
		//gluOrtho2D (-50.0f*w/h, 50.0f*w/h, -50.0f, 50.0f);
}

void CDisplay::setKeyboardFuncCallback(void (__cdecl *func)(unsigned char, int, int)){
	glutKeyboardFunc(func);
}

void CDisplay::initialize(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	glutDisplayFunc(dispatchDraw);
	//glutIdleFunc(dispatchDraw);
	glutReshapeFunc(resizeWindow);
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
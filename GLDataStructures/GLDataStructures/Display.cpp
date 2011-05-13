/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autores: Nilton Vasques e Gustavo Neves
  Data do ínicio da implementação: 20/04/2011
  Data da última modificação: 21/04/2011

  Implementação da classe Display que é responsavel por desenhar na tela.
  A mesma recebe por parametro um objeto do tipo Shape.
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include "Display.h"
#include "Shape.h"

#define WINDOW_TITLE "GL Studys"
#define INIT_X 700
#define INIT_Y 50

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640


using namespace std;

CDisplay *CDisplay::instance = NULL;
CDisplay::FUNC_CALLBACK CDisplay::mCallbackKey;
void CDisplay::renderFrame(){
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
	GLdouble left = ( w <= h ? -QUADRANT_SIZE : -QUADRANT_SIZE * w/h);
	GLdouble right = ( w <= h ? QUADRANT_SIZE : QUADRANT_SIZE * w/h);
	GLdouble bottom = ( w <= h ? -QUADRANT_SIZE * h/w : -QUADRANT_SIZE);
	GLdouble top = ( w <= h ? QUADRANT_SIZE * h/w : QUADRANT_SIZE);
	printf("left %f right %f bottom %f bottom %f \n",left,right,bottom,top);
	gluOrtho2D (left, right, bottom, top);
}

void CDisplay::setKeyboardFuncCallback(void (__cdecl *func_)(unsigned char, int, int)){
	mCallbackKey.func = func_;
}

void CDisplay::keyBoardCallback(unsigned char key, int x, int y){
	mCallbackKey.func(key,x,y);
	glutPostRedisplay();
}

void CDisplay::initialize(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	glutDisplayFunc(renderFrame);
	//glutIdleFunc(dispatchDraw);
	glMatrixMode(GL_PROJECTION);
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(CDisplay::keyBoardCallback);
	configureTick(50);
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

//void CDisplay::redraw(){
//	CDisplay::renderFrame();
//}

void CDisplay::enableAntiAlias(){
	if(glIsEnabled(GL_LINE_SMOOTH))
		glDisable(GL_LINE_SMOOTH);
	else
		glEnable(GL_LINE_SMOOTH);
}

void CDisplay::configureTick(GLubyte frame) {
		//struct ntptimeval now;
  //      static long secs, usecs;
  //      long dif;
  //      int msecs = 20;

  //      /* throttle frame rate, ideally to 50 */
  //      ntp_gettime(&now);
  //      
  //      if (frame) {
  //              if (now.time.tv_sec > secs) dif = 1000000-usecs+now.time.tv_usec;
  //              else dif = now.time.tv_usec - usecs;
  //              if (dif >= 20000) msecs = 0;
  //              else msecs = (int)(20000 - dif)/1000;
  //      }
  //      secs = now.time.tv_sec;
  //      usecs = now.time.tv_usec;
  //      
  //      if (!Pause) drawScene();
        //glutTimerFunc(msecs,tick,++frame)
}
/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autores: Nilton Vasques e Gustavo Neves
  Data do ínicio da implementação: 20/04/2011
  Data da última modificação: 16/05/2011

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
	if(CDisplay::getInstance()->isPause()) return;		
	glClear(GL_COLOR_BUFFER_BIT);
	std::map<Shape*, Shape*> shapes = CDisplay::getInstance()->shapes;
	for (map<Shape*, Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++){
		it->second->Draw();
	}
	glFlush();
}

void CDisplay::updateAnimation(){
	list<Animation*> *temp = &CDisplay::getInstance()->listAnimations;
	list<Animation*>::iterator i;
	list<Animation*> b;
	

	for(i=temp->begin(); i != temp->end(); i++){
		int x = (*i)->update();
		if(x == 0){
			b.push_back(*i);
			delete((*i));
		}
	}

	for (i=b.begin(); i != b.end(); i++){
		temp->remove(*i);
	}

	glutPostRedisplay();
}

void CDisplay::addAnimation(Animation *anim){
	//if(CDisplay::getInstance()->animation != NULL) delete(CDisplay::getInstance()->animation);
	//CDisplay::getInstance()->animation = anim;
	listAnimations.push_front(anim);
}

CDisplay* CDisplay::getInstance(){
	if (!instance) instance = new CDisplay();
	return instance;
}

CDisplay::CDisplay(){
	pause = false;
	animation = NULL;
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

void CDisplay::setKeyboardFuncCallback(void (*func_)(unsigned char, int, int)){
	mCallbackKey.func = func_;
}

void CDisplay::keyBoardCallback(unsigned char key, int x, int y){
	mCallbackKey.func(key,x,y);
	glutPostRedisplay();
}

void CDisplay::initialize(int argc, char** argv){
        glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
	glutDisplayFunc(renderFrame);
	glMatrixMode(GL_PROJECTION);
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(CDisplay::keyBoardCallback);
	configureTick(10);
	//glutFullScreen();
}

void CDisplay::setBackgroundColor(Color color){
	glClearColor(color.red,color.green,color.blue,color.alpha);	
}

void CDisplay::run(){
	glutMainLoop();
}

void CDisplay::setPause(bool state){
	this->pause = state;
}

bool CDisplay::isPause(){
	return this->pause;
}

void CDisplay::addShape(Shape* shape){
	shapes[shape] = shape;
}

Shape* CDisplay::removeShapeN(Shape* shape){
	if(shape != NULL) shapes.erase(shape);
	return shape;
}

std::map<Shape*, Shape*> CDisplay::removeAllShapesN(){
	list<Animation*> *temp = &CDisplay::getInstance()->listAnimations;
	list<Animation*>::iterator i;
	for(i=temp->begin(); i != temp->end(); i++){
		delete((*i));		
	}
	this->listAnimations.clear();

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

void CDisplay::configureTick(GLint frame) {
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
	if(!CDisplay::getInstance()->isPause()) updateAnimation();
    glutTimerFunc(50,configureTick,0);
}

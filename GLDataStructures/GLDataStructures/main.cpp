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
	CDisplay::getInstance()->initialize(); //fun��o que chamas as fun��es de inicializa�ao da glut e desenha a janela.
	CDisplay::getInstance()->setKeyboardFuncCallback(keyboardListener);//Fun��o que registra a fun��o que ser� o callback das entradas de teclado
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
			//Exemplo da adi��o de um shape a tela
			//shape = new PointShape(Point(30,30),5.0f);
			shape = new CircleShape(Point(0,0),30,Color(0,0,255));
			CDisplay::getInstance()->addShape(shape);
			CDisplay::getInstance()->redraw();
			break;
		
		case KEY_KEY_2:
			//Exemplo da adi��o de um shape a tela
			//shape = new SquareShape(Rect(10,20,20,20), Color(0, 255, 0));
			shape = new TestShape();
			CDisplay::getInstance()->addShape(shape);
			CDisplay::getInstance()->redraw();			
			break;		
		case KEY_KEY_3:
			//Exemplo da adi��o de um shape a tela
			drawAnimationPointer();
			break;
		case KEY_KEY_4:{
			//Exemplo da remo��o de todos os shapes da tela
			deleteShapesDisplay();
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

////*****************************************************
////
//// Exemplo3DAntialias-linha.cpp
//// Um programa OpenGL demonstrando o uso de
//// blending para obter o efeito de antialiasing em
//// wireframe
////
//// Marcelo Cohen e Isabel H. Manssour
//// Este c�digo acompanha o livro 
//// "OpenGL - Uma Abordagem Pr�tica e Objetiva"
//// 
////*****************************************************
//
//#include <stdlib.h>
//#include <GL/glut.h>
//
//// Vari�veis para controles de navega��o
//GLfloat angle, fAspect;
//GLfloat rotX, rotY, rotX_ini, rotY_ini;
//GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
//int x_ini,y_ini,bot;
//
//// Fun��o respons�vel por inicializar par�metros e vari�veis
//void Inicializa (void)
//{   
//	// Define a cor de fundo da janela de visualiza��o como branca
//	glClearColor(1, 1, 1, 1);
//	glEnable (GL_BLEND);
//	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	// Habilita antialiasing
//	glEnable (GL_LINE_SMOOTH);
//	// Solicita melhor qualidade
//	glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
//
//	glMatrixMode(GL_MODELVIEW);
//
//	// Sem z-buffer
//	glDisable(GL_DEPTH_TEST);
//
//	// Inicializa a vari�vel que especifica o �ngulo da proje��o
//	// perspectiva
//	angle=45;
//    
//	// Inicializa as vari�veis usadas para alterar a posi��o do 
//	// observador virtual
//	rotX = 0;
//	rotY = 0;
//	obsX = obsY = 0;
//	obsZ = 5;
//}
//
//void Desenha(void)
//{
//	// Limpa a janela de visualiza��o com a cor  
//	// de fundo definida previamente
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glColor3f(0,0,0);
//	glutWireSphere(1,40,40);
//
//	glutSwapBuffers();
//}
//
//// Fun��o usada para especificar a posi��o do observador virtual
//void PosicionaObservador(void)
//{
//	// Especifica sistema de coordenadas do modelo
//	glMatrixMode(GL_MODELVIEW);
//	
//	// Inicializa sistema de coordenadas do modelo
//	glLoadIdentity();
//	
//	// Posiciona e orienta o observador
//	glTranslatef(-obsX,-obsY,-obsZ);
//	glRotatef(rotX,1,0,0);
//	glRotatef(rotY,0,1,0);
//}
//
//// Fun��o usada para especificar o volume de visualiza��o
//void EspecificaParametrosVisualizacao(void)
//{
//	// Especifica sistema de coordenadas de proje��o
//	glMatrixMode(GL_PROJECTION);
//	// Inicializa sistema de coordenadas de proje��o
//	glLoadIdentity();
//
//	// Especifica a proje��o perspectiva(angulo,aspecto,zMin,zMax)
//	gluPerspective(angle,fAspect,0.5,500);
//
//	PosicionaObservador();
//}
//
//// Fun��o callback chamada para gerenciar eventos de teclas normais (ESC)
//void Teclado (unsigned char tecla, int x, int y)
//{
//	switch(tecla)
//	{
//		case 27:	// ESC ?
//					exit(0);
//		case 'a':	if(glIsEnabled(GL_LINE_SMOOTH))
//						glDisable(GL_LINE_SMOOTH);
//					else
//						glEnable(GL_LINE_SMOOTH);
//
//	}
//	glutPostRedisplay();
//}
//
//// Fun��o callback para tratar eventos de teclas especiais
//void TeclasEspeciais (int tecla, int x, int y)  
//{
//	switch (tecla)
//	{
//		case GLUT_KEY_HOME:	if(angle>=10)  angle -=5;
//							break;
//		case GLUT_KEY_END:	if(angle<=150) angle +=5;
//							break;
//	}
//	EspecificaParametrosVisualizacao();
//	glutPostRedisplay();
//}
//
//// Fun��o callback para eventos de bot�es do mouse
//void GerenciaMouse(int button, int state, int x, int y)
//{
//	if(state==GLUT_DOWN)
//	{
//		// Salva os par�metros atuais
//		x_ini = x;
//		y_ini = y;
//		obsX_ini = obsX;
//		obsY_ini = obsY;
//		obsZ_ini = obsZ;
//		rotX_ini = rotX;
//		rotY_ini = rotY;
//		bot = button;
//	}
//	else bot = -1;
//}
//
//// Fun��o callback para eventos de movimento do mouse
//#define SENS_ROT	5.0
//#define SENS_OBS	100.0
//#define SENS_TRANSL	100.0
//void GerenciaMovim(int x, int y)
//{
//	// Bot�o esquerdo ?
//	if(bot==GLUT_LEFT_BUTTON)
//	{
//		// Calcula diferen�as
//		int deltax = x_ini - x;
//		int deltay = y_ini - y;
//		// E modifica �ngulos
//		rotY = rotY_ini - deltax/SENS_ROT;
//		rotX = rotX_ini - deltay/SENS_ROT;
//	}
//	// Bot�o direito ?
//	else if(bot==GLUT_RIGHT_BUTTON)
//	{
//		// Calcula diferen�a
//		int deltaz = y_ini - y;
//		// E modifica dist�ncia do observador
//		obsZ = obsZ_ini + deltaz/SENS_OBS;
//	}
//	// Bot�o do meio ?
//	else if(bot==GLUT_MIDDLE_BUTTON)
//	{
//		// Calcula diferen�as
//		int deltax = x_ini - x;
//		int deltay = y_ini - y;
//		// E modifica posi��es
//		obsX = obsX_ini + deltax/SENS_TRANSL;
//		obsY = obsY_ini - deltay/SENS_TRANSL;
//	}
//	PosicionaObservador();
//	glutPostRedisplay();
//}
//
//// Fun��o callback chamada quando o tamanho da janela � alterado 
//void AlteraTamanhoJanela(GLsizei w, GLsizei h)
//{
//	// Evita a divisao por zero
//	if(h == 0) h = 1;
//
//	// Especifica as dimens�es da Viewport
//	glViewport(0, 0, w, h);
//
//	// Calcula a corre��o de aspecto
//	fAspect = (GLfloat)w/(GLfloat)h;
//
//	EspecificaParametrosVisualizacao();
//}
//
//// Programa Principal 
//int main(void)
//{
//	// Define do modo de opera��o da GLUT
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//	// Especifica a posi��o inicial da janela GLUT
//	glutInitWindowPosition(5,5); 
//
//	// Especifica o tamanho inicial em pixels da janela GLUT
//	glutInitWindowSize(450,450); 
// 
//	// Cria a janela passando como argumento o t�tulo da mesma
//	glutCreateWindow("Antialiasing em wireframe");
//
//	// Registra a fun��o callback de redesenho da janela de visualiza��o
//	glutDisplayFunc(Desenha);
//
//	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
//	glutReshapeFunc(AlteraTamanhoJanela);
//
//	// Registra a fun��o callback para tratamento das teclas ASCII
//	glutKeyboardFunc (Teclado);
//    
//	// Registra a fun��o callback para tratamento das teclas especiais
//	glutSpecialFunc (TeclasEspeciais);
//
//	// Registra a fun��o callback para eventos de bot�es do mouse	
//	glutMouseFunc(GerenciaMouse);
//	 
//	// Registra a fun��o callback para eventos de movimento do mouse	
//	glutMotionFunc(GerenciaMovim);
//
//	// Chama a fun��o respons�vel por fazer as inicializa��es
//	Inicializa();
//
//	// Inicia o processamento e aguarda intera��es do usu�rio
//	glutMainLoop();
//
//	return 0;
//}


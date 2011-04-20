#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "keycodes.h"
#include "TriangleShape.h"

void keyPressedListener(unsigned char key, int x, int y);
void resizeWindow(GLsizei w, GLsizei h);
void inicializa();

#define WINDOW_TITLE "GL Studys"
#define INIT_X 700
#define INIT_Y 50

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

void menu(int i){
	printf("La vai");
	glutPostRedisplay();
}

int main(int argc, const char* argv[]){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(INIT_X,INIT_Y);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);

	TriangleShape triangle = TriangleShape(Point(-60,-49),Point(0,49),Point(60,-49));
	triangle.Draw();
	
	glutKeyboardFunc(keyPressedListener);
	glutReshapeFunc(resizeWindow);
	glutMainLoop();

	return 0;
}

void keyPressedListener(unsigned char key, int x, int y){
	printf("keyPressedListener Key %d\n",key);
	switch(key){
		case KEY_ESCAPE:
			exit(0);
			break;
		case KEY_KEY_1:
			printf("pressed\n");
			glutSwapBuffers();			
			break;
		case KEY_KEY_2:
			TriangleShape(Point(-30,-49),Point(0,49),Point(30,-49)).Draw();
			break;
		case KEY_KEY_3:
			TriangleShape(Point(-30,-49),Point(0,29),Point(30,-49)).Draw();
			break;
	}
}

void resizeWindow(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if(h == 0) h = 1;
                           
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (w <= h) 
		gluOrtho2D (-50.0f, 50.0f, -50.0f*h/w, 50.0f*h/w);
	else 
		gluOrtho2D (-50.0f*w/h, 50.0f*w/h, -50.0f, 50.0f);
}

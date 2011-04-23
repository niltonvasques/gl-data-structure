#include "CircleShape.h"
#include <GL/glut.h>
#include <math.h>
#include "constants.h"
#include <stdio.h>

CircleShape::CircleShape(Point center_,GLuint radius_, Color color) : Shape(color){
	setCenter(center_);
	setRadius(radius_);
}

CircleShape::~CircleShape(){

}

void CircleShape::setCenter(Point center_){
	this->center = center_;
}

void CircleShape::setRadius(GLuint radius_){
	this->radius = radius_;
}

void CircleShape::Draw(){
	//Alterar o metodo de coordenadas da tela pois o circulo fica oval em janelas que nao sao quadrado perfeito
	int circle_points = 50;
	glColor4ub(this->color.red, this->color.green, this->color.blue,this->color.alpha);
	glBegin(GL_LINE_LOOP);
	for (float angle = 0; angle < 2 *M_PI; angle +=( M_PI/circle_points)){   
		float x = (cos(angle));
		float y = (sin(angle));
		glVertex2f ( x*this->radius+this->center.x, y*this->radius+this->center.y );
	}
	glEnd();
}	
	//Algoritmo de desenho de cones estranhos
	//int t,i, circle_points = 100;
	//float angle,x,y,x1,y1,x2,y2;
	//printf("drawCircle\n");
	//glBegin(GL_LINE_LOOP);
	//for (i=0; i < circle_points; i++)   {   
	//	glColor3f(1.0f, 0.0f, 0.0f);
	//	angle =  2 * M_PI * i / circle_points;
	//	x = (cos(angle));
	//	y = (sin(angle));
	//	glVertex2f ( x*30+50, y*30+50 );
	//	glVertex2f ( 50, 30 );
	//	printf(" vertex x: %f y: %f\n",x*100,y*100);

	//	if ( i == 32 ) {
	//		x1 = x;
	//		y1 = y;
	//	}
	//}
	//glEnd();
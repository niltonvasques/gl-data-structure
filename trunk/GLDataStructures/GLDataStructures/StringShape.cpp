#include <stdlib.h>
#include <stdio.h>
#include "StringShape.h"

StringShape::StringShape(char *string_, Color color_, Point xyStart_,GLuint fontSize):Shape(color_){
	this->string = string_;
	this->xyStart = xyStart_;
	this->fontSizeFloat = (GLfloat) fontSize / 100;
	this->antiAlias = false;
}

StringShape::~StringShape(){
	free(this->string);
}

void StringShape::setPoint(Point xyStart_){
	this->xyStart = xyStart_;
}

void StringShape::setAntiAlias(bool enabled){
	antiAlias = enabled;
}



void StringShape::Draw(){
	// Limpa a janela de visualização com a cor de fundo definida

	// Define a cor para os textos: preto
	glColor4ub(color.red,color.green,color.blue,color.alpha);

	//// Posiciona o texto stroke usando transformações geométricas
	if(antiAlias) glEnable(GL_LINE_SMOOTH);

	glPushMatrix();	
	glTranslatef(xyStart.x,xyStart.y,0);

	glScalef(fontSizeFloat, fontSizeFloat, fontSizeFloat); // diminui o tamanho do fonte
	//glRotatef(45, 0,0,1); // rotaciona o texto
	glLineWidth(1); // define a espessura da linha
	char *str = this->string;
	while(*str)
		//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*str++);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*str++); 
		

	glPopMatrix();

	glDisable(GL_LINE_SMOOTH);

	//// Posição no universo onde o texto bitmap será colocado 
	//glRasterPos2f(xyStart.x,xyStart.y); 
	//str = this->string;
	//while(*str)
	//	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*str++);
	//DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,"Bitmap");
	//// Exibe o desenha na janela
	//glutSwapBuffers();

}

int StringShape::animation(){
	return 1;
}


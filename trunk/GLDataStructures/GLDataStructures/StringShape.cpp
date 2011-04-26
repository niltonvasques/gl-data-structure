#include <stdlib.h>
#include "StringShape.h"

StringShape::StringShape(char *string_, Color color_, Point xyStart_):Shape(color_){
	this->string = string_;
	this->xyStart = xyStart_;
}

StringShape::~StringShape(){
	free(this->string);
}

void StringShape::setPoint(Point xyStart_){
	this->xyStart = xyStart_;
}

void StringShape::Draw(){
	// Limpa a janela de visualização com a cor de fundo definida

	// Define a cor para os textos: preto
	glColor4ub(color.red,color.green,color.blue,color.alpha);

	//// Posiciona o texto stroke usando transformações geométricas
	//glPushMatrix();	
	//glTranslatef(xyStart.x,xyStart.y,0);
	//glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
	//glRotatef(45, 0,0,1); // rotaciona o texto
	//glLineWidth(3); // define a espessura da linha
	char *str = this->string;
	//while(*str)
	//	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*str++);
	//	glutStrokeCharacter(GLUT_STROKE_ROMAN,*str++); 
	//	

	//glPopMatrix();

	//// Posição no universo onde o texto bitmap será colocado 
	glRasterPos2f(xyStart.x,xyStart.y); 
	str = this->string;
	while(*str)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*str++);
	//DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,"Bitmap");
	//// Exibe o desenha na janela
	//glutSwapBuffers();

}



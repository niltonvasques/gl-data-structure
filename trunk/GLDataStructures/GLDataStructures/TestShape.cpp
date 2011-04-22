#include "TestShape.h"


TestShape::TestShape() :Shape(Color()){

}

TestShape::~TestShape(){
}

void TestShape::Draw(){
	// Função callback de redesenho da janela de visualização
	GLint width;
    
	// Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);
    
	// Especifica a cor vermelha
	glColor3f(1.0f, 0.0f, 0.0f);	

	// Empilha atributo (espessura da linha - default é 1)
	glPushAttrib(GL_LINE_BIT);
	// Empilha atributo (cor)
	glPushAttrib(GL_CURRENT_BIT); 

	// Especifica a cor azul
	glColor3f(0.0f, 0.0f, 1.0f); 
	// Especifica a espessura da linha
	glLineWidth(5);
    
	// Desenha linhas de espessura 5 e cor azul
	// na parte inferior da janela
	glBegin(GL_LINES);
		glVertex2f(10.0f,10.0f);
		glVertex2f( 70.0f,10.0f); 
		glVertex2f(10.0f,20.0f);
		glVertex2f( 70.0f,20.0f);
	glEnd();    
    
	// A variável width irá receber o valor 5
	glGetIntegerv(GL_LINE_WIDTH,&width); 
    
	// Desempilha atributo (cor)
	glPopAttrib(); 
    
	// Desenha linhas de espessura 5 e cor vermelha
	// no meio da janela
	glBegin(GL_LINES);
		glVertex2f(10.0f,45.0f);
		glVertex2f( 40.0f,45.0f); 
		glVertex2f(10.0f,55.0f);
		glVertex2f( 40.0f,55.0f);
	glEnd();     
    
	// Desempilha atributo (espessura da linha)
	glPopAttrib();
    
	// Desenha linhas de espessura 1 (default) e cor vermelha
	// na parte superior da janela    
	glBegin(GL_LINES);
		glVertex2f(10.0f,80.0f);
		glVertex2f( 70.0f,80.0f); 
		glVertex2f(10.0f,70.0f);
		glVertex2f( 70.0f,70.0f);

	glEnd();
    
	// Executa os comandos OpenGL 
	glFlush();
}
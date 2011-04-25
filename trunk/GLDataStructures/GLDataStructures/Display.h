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
#ifndef DISPLAY_H
#define DISPLAY_H

#include <map>
#include "Shape.h"
#include "color.h"

class CDisplay {
public:

	static CDisplay* getInstance();

	void initialize();
	void setKeyboardFuncCallback(void (__cdecl *func)(unsigned char, int, int));
	void addShape(Shape* shape);
	Shape* removeShapeN(Shape* shape);
	std::map<Shape*, Shape*> CDisplay::removeAllShapesN();
	void setBackgroundColor(Color color);
	void redraw();
	void enableAntiAlias();
	void run();

private:

	CDisplay();
	~CDisplay();

	static void dispatchDraw();
	static void resizeWindow(GLsizei w, GLsizei h);
	static CDisplay *instance;

	std::map<Shape*, Shape*> shapes;

};

#endif
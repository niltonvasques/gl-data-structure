/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autores: Nilton Vasques e Gustavo Neves
  Data do �nicio da implementa��o: 20/04/2011
  Data da �ltima modifica��o: 21/04/2011

  Implementa��o da classe Display que � responsavel por desenhar na tela.
  A mesma recebe por parametro um objeto do tipo Shape.
-----------------------------------------------------------------------------*/
#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include "Shape.h"
#include "color.h"
#include "Animation.h"

#define QUADRANT_SIZE 100.0f

class CDisplay {
	struct funcCallback_{
		void (*func)(unsigned char, int, int);
		}typedef FUNC_CALLBACK;
public:

	static CDisplay* getInstance();

	void initialize(int argc, char** argv);
	void setKeyboardFuncCallback(void (*func)(unsigned char, int, int));
	void addShape(Shape* shape);
	void addAnimation(Animation *anim);
	Shape* removeShapeN(Shape* shape);
	std::map<Shape*, Shape*> removeAllShapesN();
	void setBackgroundColor(Color color);
	//void redraw();
	void enableAntiAlias();
	void run();
	void setPause(bool state);
	bool isPause();

private:
	
	CDisplay();
	~CDisplay();
	
	static void configureTick(GLint frame);
	static void renderFrame();
	static void updateAnimation();
	static void resizeWindow(GLsizei w, GLsizei h);
	static void keyBoardCallback(unsigned char, int, int);
	static FUNC_CALLBACK mCallbackKey;
	static CDisplay *instance;
	std::map<Shape*, Shape*> shapes;
	Animation *animation;
	std::list<Animation*> listAnimations;
	bool pause;
};

#endif

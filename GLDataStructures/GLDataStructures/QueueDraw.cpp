/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autor: Nilton Vasques
  Data do ínicio da implementação: 10/05/2011
  Data da última modificação: 16/05/2011

  Implementação da classe QueueDraw que é responsavel representar graficamente
  a estrutura de fila.
-----------------------------------------------------------------------------*/
#include "QueueDraw.h"
#include "Animation.h"
#include "Display.h"

QueueDraw::QueueDraw(Color color_): Shape(color_){
	this->blockWidth = DEFAULT_BLOCK_WIDTH;
	this->blockHeight = DEFAULT_BLOCK_HEIGHT;
	this->originalBlockWidth = this->blockWidth;
	this->originalBlockHeight = this->blockHeight;
	this->x = Point(100,0);
}

QueueDraw::~QueueDraw(){
	while(!shapesQueue.isEmpty()){
		SquareShape *sqr = NULL;
		shapesQueue.remove(sqr);
		delete(sqr);
	}
}

GLint QueueDraw::insert(GLint value){
	SquareShape *squareContent = NULL;
	SquareShape *tail = NULL;
	if(shapesQueue.isEmpty())
		squareContent = new SquareShape(Rect(x.x - blockWidth-1,x.y,this->blockWidth,this->blockHeight),this->color);
	else{
		shapesQueue.pickTail(tail);
		printf("tail x %d\n",tail->getRect().x);
		squareContent = new SquareShape(Rect(tail->getRect().x-blockWidth-2,0,this->blockWidth,this->blockHeight),this->color);
	}
	shapesQueue.insert(squareContent);
	glutPostRedisplay();
	return 1;
}

GLint QueueDraw::remove(GLint &ref){
	SquareShape *temp = NULL;
	shapesQueue.remove(temp);
	if(temp != NULL){
		this->x.x = temp->getRect().x;
		Animation *anim = new Animation(this);
		CDisplay::getInstance()->addAnimation(anim);
	}
	delete(temp);
	return 1;
}


void QueueDraw::setPointFirstBlock(Point x_){
	this->x = x_;
}

Point QueueDraw::getPointFirstBlock(){
	return this->x;
}


void QueueDraw::Draw(){
	Queue<SquareShape*> temp;
	GLint count = 1;
	while(!shapesQueue.isEmpty()){
		SquareShape* sqr = NULL;
		shapesQueue.remove(sqr);
		Rect rect = sqr->getRect();
		sqr->setRect(Rect(x.x - (rect.width+1)*count,x.y,rect.width,rect.height));
		sqr->Draw();
		temp.insert(sqr);
		count++;
	}
	while(!temp.isEmpty()){
		SquareShape* sqr = NULL;
		temp.remove(sqr);
		shapesQueue.insert(sqr);
	}
}

int QueueDraw::animation(){
	if(x.x < 100){
		setPointFirstBlock(Point(x.x+1,0));
		Draw();
		return 1;
	}
	return 0;		
}

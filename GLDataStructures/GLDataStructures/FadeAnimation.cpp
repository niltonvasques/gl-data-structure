#include "Display.h"
#include "FadeAnimation.h"

FadeAnimation::FadeAnimation(SquareShape *square_){
	this->square = square_;
}

FadeAnimation::~FadeAnimation(){

}

//Repensar como vai ficar o animation e implementar o ticketCount...
void FadeAnimation::start(){
		Rect rect = square->getRect();
		CDisplay::getInstance()->addShape(square);
		for(int i = 0; rect.width > 0; i++,sleep(30)){
			square->setRect(Rect(rect.x+1,rect.y,rect.width-2,rect.height-2));
			//CDisplay::getInstance()->redraw();
			rect = square->getRect();
			printf("rect width %d\n",rect.width);
		}
		CDisplay::getInstance()->removeShapeN(square);
}

void FadeAnimation::stop(){

}
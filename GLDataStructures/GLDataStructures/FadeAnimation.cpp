#include "Display.h"
#include "FadeAnimation.h"

FadeAnimation::FadeAnimation(SquareShape *square_){
	this->square = square_;
	printf("FadeAnimation(SquareShape *square_) rectWidth %d\n",square->getRect().width);
	//CDisplay::getInstance()->addShape(square);
}

FadeAnimation::~FadeAnimation(){
	//delete(CDisplay::getInstance()->removeShapeN(square));
}

//Repensar como vai ficar o animation e implementar o ticketCount...
int FadeAnimation::update(){
		Rect rect = square->getRect();		
		printf("update() rectWidth %d\n",rect.width);
		if(rect.width > 0){
			//square->setRect(Rect(rect.x+1,rect.y,rect.width-2,rect.height-2));		
			//square->Draw();
			return 1;
		}
		return 0;
}

void FadeAnimation::stop(){

}
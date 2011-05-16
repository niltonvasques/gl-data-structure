#ifndef QUEUE_DRAW_H
#define QUEUE_DRAW_H

#include "queue.h"
#include "Shape.h"
#include "SquareShape.h"
#include "Point.h"


class QueueDraw : public Shape{
#define DEFAULT_BLOCK_WIDTH  20	
#define	DEFAULT_BLOCK_HEIGHT 10

public:
	QueueDraw(Color color_);
	virtual ~QueueDraw();

	virtual void Draw();
	virtual int animation();
	
	GLint insert(GLint value);
	GLint remove(GLint &ref);

	void setPointFirstBlock(Point x_);
	Point getPointFirstBlock();

private:
	Queue<SquareShape*> shapesQueue;
	Queue<GLint> valuesQueue;

	GLuint blockWidth;
	GLuint blockHeight;
	GLuint originalBlockWidth;
	GLuint originalBlockHeight;
	Point x;
};

#endif
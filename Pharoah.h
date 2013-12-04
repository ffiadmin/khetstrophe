#include "KhetPiece.h"

#ifndef PHAROAH_H
#define PHAROAH_H

class Pharoah : public KhetPiece
{
public:
	Pharoah(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics) {
		setColor(color);
		if(color == 'r')
			setGraphic(PHAROAH_RED, 2);
		else if(color == 'g')
			setGraphic(PHAROAH_GREY, 2);
	}

	RESPONSE onCollision(int dir) {return DESTROY;} // dir: 0 left, 1 up, 2 right, 3 down
private:

};

#endif
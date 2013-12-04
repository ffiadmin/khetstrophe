#include "KhetPiece.h"

#ifndef SPHINX_H
#define SPHINX_H

class Sphinx : public KhetPiece
{
public:
	Sphinx(Game* game, Graphics* graphics, char color) {
		Tile(game, graphics);
		setColor(color);
		if(color = 'r')
			setGraphic(SPHINX_RED);
		else if(color = 'g')
			setGraphic(SPHINX_GREY);
	}
	RESPONSE onCollision(int dir) {return NOTHING;} // dir: 0 left, 1 up, 2 right, 3 down
private:

};

#endif
#include "KhetPiece.h"

#ifndef SCARAB_H
#define SCARAB_H

class Scarab : public KhetPiece
{
public:
	Scarab::Scarab(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics) {
		setColor(color);
		if (color == 'r')
			setGraphic(SCARAB_RED, 2);
		else if (color == 'g')
			setGraphic(SCARAB_GREY, 2);
	}

	RESPONSE onCollision(int dir) // dir: 0 left, 1 up, 2 right, 3 down
	{
		switch (Scarab::getOrientation())
		{
		case 0:
		case 2:
			switch (dir)
			{
			case 0:
				return DOWN;
			case 1:
				return RIGHT;
			case 2:
				return UP;
			case 3:
				return LEFT;
			default:
				return NOTHING;
			}
			break;
		case 1:
		case 3:
			switch (dir)
			{
			case 0:
				return UP;
			case 1:
				return LEFT;
			case 2:
				return DOWN;
			case 3:
				return RIGHT;
			default:
				return NOTHING;
			}
			break;
		default:
			return NOTHING;
		}
	}
private:

};

#endif
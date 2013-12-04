#include "KhetPiece.h"

#ifndef SCARAB_H
#define SCARAB_H

class Scarab : public KhetPiece
{
public:
	Scarab::Scarab(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics) { }

	RESPONSE onCollision(int dir) // dir: 0 left, 1 up, 2 right, 3 down
	{
		switch (Scarab::getOrientation())
		{
		case 0:
			switch (dir)
			{
			case 0:
				return DOWN;
				break;
			case 1:
				return RIGHT;
				break;
			case 2:
				return UP;
				break;
			case 3:
				return LEFT;
				break;
			}
			break;
		case 1:
			switch (dir)
			{
			case 0:
				return UP;
				break;
			case 1:
				return LEFT;
				break;
			case 2:
				return DOWN;
				break;
			case 3:
				return RIGHT;
				break;
			}
			break;
		case 2:
			switch (dir)
			{
			case 0:
				return DOWN;
				break;
			case 1:
				return RIGHT;
				break;
			case 2:
				return UP;
				break;
			case 3:
				return LEFT;
				break;
			}
			break;
		case 3:
			switch (dir)
			{
			case 0:
				return UP;
				break;
			case 1:
				return LEFT;
				break;
			case 2:
				return DOWN;
				break;
			case 3:
				return RIGHT;
				break;
			}
			break;
		}
	}
private:

};

#endif
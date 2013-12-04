#include "KhetPiece.h"

#ifndef PYRAMID_H
#define PYRAMID_H

class Pyramid : public KhetPiece
{
public:
	Pyramid::Pyramid(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics) { }

	RESPONSE onCollision(int dir) // dir: 0 left, 1 up, 2 right, 3 down
	{
		switch (Pyramid::getOrientation())
		{
		case 0:
			switch (dir)
			{
			case 0:
				return DESTROY;
			case 1:
				return DESTROY;
			case 2:
				return UP;
			case 3:
				return LEFT;
			default:
				return NOTHING;
			}
			break;
		case 1:
			switch (dir)
			{
			case 0:
				return UP;
			case 1:
				return DESTROY;
			case 2:
				return DESTROY;
			case 3:
				return RIGHT;	
			default:
				return NOTHING;
			}
			break;
		case 2:
			switch (dir)
			{
			case 0:
				return DOWN;
			case 1:
				return RIGHT;
			case 2:
				return DESTROY;
			case 3:
				return DESTROY;
			default:
				return NOTHING;
			}
			break;
		case 3:
			switch (dir)
			{
			case 0:
				return DESTROY;
			case 1:
				return LEFT;
			case 2:
				return DOWN;
			case 3:
				return DESTROY;
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
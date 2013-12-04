#include "KhetPiece.h"

#ifndef PYRAMID_H
#define PYRAMID_H

class Pyramid : public KhetPiece
{
public:
	RESPONSE onCollision(int dir) // dir: 0 left, 1 up, 2 right, 3 down
	{
		switch (Pyramid::getOrientation())
		{
		case 0:
			switch (dir)
			{
			case 0:
				return DESTROY;
				break;
			case 1:
				return DESTROY;
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
				return DESTROY;
				break;
			case 2:
				return DESTROY;
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
				return DESTROY;
				break;
			case 3:
				return DESTROY;
				break;
			}
			break;
		case 3:
			switch (dir)
			{
			case 0:
				return DESTROY;
				break;
			case 1:
				return LEFT;
				break;
			case 2:
				return DOWN;
				break;
			case 3:
				return DESTROY;
				break;
			}
			break;
		}
	}
private:

};

#endif
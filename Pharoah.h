#include "KhetPiece.h"

#ifndef PHAROAH_H
#define PHAROAH_H

class Pharoah : public KhetPiece
{
public:
	RESPONSE onCollision(int dir) {return DESTROY;} // dir: 0 left, 1 up, 2 right, 3 down
private:

};

#endif
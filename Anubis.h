#include "KhetPiece.h"

#ifndef ANUBIS_H
#define ANUBIS_H

class Anubis : public KhetPiece
{
public:
	Anubis(Game* game, Graphics* graphics, char color);
	RESPONSE onCollision(int dir); // dir: 0 left, 1 up, 2 right, 3 down
private:

};

#endif
#include "KhetPiece.h"

#ifndef SPHINX_H
#define SPHINX_H

class Sphinx : public KhetPiece
{
public:
	RESPONSE onCollision(int dir) {return NOTHING;} // dir: 0 left, 1 up, 2 right, 3 down
private:

};

#endif
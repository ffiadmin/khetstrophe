#include "Anubis.h"

RESPONSE Anubis::onCollision(int dir)
{
	// dir: 0 left, 1 up, 2 right, 3 down
	if(Anubis::getOrientation() == dir)
		return NOTHING;
	else
		return DESTROY;
}
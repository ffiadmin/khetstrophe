#include "Anubis.h"

Anubis::Anubis(Game* game, Graphics* graphics, char color) : KhetPiece(game, graphics)
{
		setColor(color);
		if(color == 'r')
			setGraphic(ANUBIS_RED);
		else if(color == 'g')
			setGraphic(ANUBIS_GREY);
}

RESPONSE Anubis::onCollision(int dir)
{
	// dir: 0 left, 1 up, 2 right, 3 down
	if(Anubis::getOrientation() == dir)
		return NOTHING;
	else
		return DESTROY;
}
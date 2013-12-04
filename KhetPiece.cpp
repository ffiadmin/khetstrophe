#include "KhetPiece.h"

KhetPiece::KhetPiece(Game* game, Graphics* graphics) : Tile(game, graphics) { }

void KhetPiece::rotate(int dir)
{
	if(dir == 1)
		orientation++;
	else if(dir == 0)
		orientation--;
	else
		throw Invalid_rotation_dir_argument();

	if(orientation < 0)
		orientation = 3;
	else if(orientation > 3)
		orientation = 0;

	setCurrentFrame(orientation);
}

void KhetPiece::setOrientation(int newOrientation)
{
	if(newOrientation > 3 || newOrientation < 0)
		throw Invalid_orientation_val();
	else {
		orientation = newOrientation;
		setCurrentFrame(orientation);
	}
}
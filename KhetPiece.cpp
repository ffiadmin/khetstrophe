#include "KhetPiece.h"

void KhetPiece::rotate(int dir)
{
	if(dir == 1)
		setCurrentFrame(getCurrentFrame()+1);
	else if(dir == 0)
		setCurrentFrame(getCurrentFrame()-1);
	else
		throw Invalid_rotation_dir_argument();

	if(getCurrentFrame() < 0)
		setCurrentFrame(3);
	else if(getCurrentFrame() > 3)
		setCurrentFrame(0);
}

void KhetPiece::setOrientation(int newOrientation)
{
	if(newOrientation > 3 || newOrientation < 0)
		throw Invalid_orientation_val();
	else
		orientation = newOrientation;
}
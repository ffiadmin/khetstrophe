#include "Tile.h"

#ifndef KHETPIECE_H
#define KHETPIECE_H

class KhetPiece : public Tile
{
public:
	void rotate(int dir); // 0 left (-90 degree) rotation, 1 right (90 degree) rotation
	virtual void onCollision()=0; // what to do when piece is hit by laser
private:
	int orientation; //current frame: 0 left, 1 up, 2 right, 3 down
};

class Invalid_rotation_dir_argument {};

#endif
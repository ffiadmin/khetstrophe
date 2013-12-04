#include "Tile.h"

#ifndef KHETPIECE_H
#define KHETPIECE_H

enum RESPONSE {UP, DOWN, LEFT, RIGHT, DESTROY, NOTHING};

class Cannot_use_KhetPiece_default_constructor {};

class KhetPiece : public Tile
{
public:
	KhetPiece() {throw Cannot_use_KhetPiece_default_constructor();}
	KhetPiece(Game* game, Graphics* graphics);

	void rotate(int dir); // 0 left (-90 degree) rotation, 1 right (90 degree) rotation
	virtual RESPONSE onCollision(int dir)=0; // what to do when piece is hit by laser
										 // dir: 0 left, 1 up, 2 right, 3 down
	
	int getOrientation() {return orientation;}
	void setOrientation(int newOrientation);

	char getColor() {return color;}
	void setColor(char c) {color = c;}

private:
	int orientation; //current frame: 0 left, 1 up, 2 right, 3 down
	char color; // r: red g: grey
};

class Invalid_rotation_dir_argument {};
class Invalid_orientation_val {};

#endif
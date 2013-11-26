#ifndef OLIVER_TEST_H
#define OLIVER_TEST_H

#include "game.h"
#include "Laser.h"
#include "Tile.h"

class OliverTest :	public Game {
private : 
	char dir;

	Laser* l;
	Tile* t;

public : 
	OliverTest();
	~OliverTest();

	void ai();
	void collisions();
	void initialize(HWND hwnd);
    void releaseAll();
    void render();
    void resetAll();
	void update();
};

#endif
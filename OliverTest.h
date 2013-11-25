#ifndef OLIVER_TEST_H
#define OLIVER_TEST_H

#include "Explode.h"
#include "game.h"

class OliverTest :	public Game {
private : 
	Explode* e;

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
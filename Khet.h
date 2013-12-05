/*  
*   Members: Garrett Young, Nick Tallents, Oliver Spryn, Zac Stahl
*   Course: 322, Obj. Oriented / Adv. Programming
*   Date: 04 Dec 2013 
*   Description: This file defines the Khet class and is our main game engine  
*/

#ifndef KHET_H
#define KHET_H

#include "game.h"
#include "Grid.h"
#include "KhetParser.h"
#include "Laser.h"
#include "Tile.h"

class Khet : public Game {
private : 
	Grid<KhetPiece, X, Y>* g;
	KhetParser<KhetPiece>* kp;
	Laser* l;

	int step;
	char turn;
	vector<vector<KhetPiece*>>* grid;
	ClickData<KhetPiece> active;
	bool activeSelected;

	Image numGrid;
      TextureManager numGridTexture;

public : 
	Khet();
	~Khet();

	void ai();
	void callback(ClickData<KhetPiece> d);
	void collisions();
	void initialize(HWND hwnd);
    void releaseAll();
    void render();
    void resetAll();
	void update();
    bool canSwap(int,int);
};

#endif
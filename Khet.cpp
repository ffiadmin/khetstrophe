#include "Khet.h"

Khet::Khet()
{

}

//=============================================================================
// Destructor
//=============================================================================
Khet::~Khet()
{

	
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Khet::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

	
}


void Khet::restart()
{
	
}

//=============================================================================
// Update all game items
//=============================================================================
void Khet::update()
{

}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Khet::ai()
{

}

//=============================================================================
// Handle collisions
//=============================================================================
void Khet::collisions()
{

}

//=============================================================================
// Render game items
//=============================================================================
void Khet::render()
{
    graphics->spriteBegin();                // begin drawing sprites



	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Khet::releaseAll()
{
	//platformTexture.onLostDevice();
	//personTexture.onLostDevice();
	//crateTexture.onLostDevice();

    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Khet::resetAll()
{
	//platformTexture.onResetDevice();
	//personTexture.onResetDevice();
	//crateTexture.onResetDevice();

    Game::resetAll();
    return;
}

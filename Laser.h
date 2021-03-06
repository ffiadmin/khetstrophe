/**
 * Laser class
 *
 * This class is designed to create a laser which has the
 * following capibilities:
 *  - Can change its color.
 *  - Can be fired from any X, Y location at any angle.
 *  - Can internally keep track of the number of collisions.
 *  - Can self destruct after a given number of collisions
 *    or amount of time.
 *
 * @author    Oliver Spryn
 * @namespace global
 * @package   global
*/

#ifndef LASER_H
#define LASER_H
#define WIN32_LEAN_AND_MEAN

#include <cmath>
#include <ctime>
#include <vector>

#include "constants.h"
#include "entity.h"
#include "game.h"
#include "gameError.h"
#include "image.h"
#include "textureManager.h"

using std::clock_t;
using std::vector;

namespace laserNS {
	const char  GRAPHIC[]    = "pictures\\laser.jpg"; //The graphic for the laser
	const int   HEAD_HEIGHT  = 5;                     // Height of the head pixel of the laser
	const int   HEAD_WIDTH   = 5;                     // Width of the head pixel of the laser
	const int   TAIL         = 50;                    // Length of the laser's tail, in pixels
	const int   VELOCITY     = 250;                   // Laser velocity, both X and Y
	const float X            = 2.0f;                  // Default location of the head pixel of the laser
	const float Y            = 2.0f;                  // Default location of the head pixel of the laser
}

class Laser : public Entity {
private : 
	Game* game;
	Graphics* graphics;
	TextureManager tm;

	int collisions;
	DWORD color;
	int destroyConst;
	int destroyCounter;
	char destroyMethod;
	bool destroyPending;
	int lastPixelIndex;
	vector<Image> tailImages;
	double timeConst;
	clock_t timeStart;

	void activate(float x, float y);
	bool checkDestory();
	void finalizeDestruction();

public : 
	static const DWORD COLOR_BLUE = SETCOLOR_ARGB(255, 0, 0, 255);
	static const DWORD COLOR_GREEN = SETCOLOR_ARGB(255, 0, 255, 0);
	static const DWORD COLOR_RED = SETCOLOR_ARGB(255, 255, 0, 0);

	static const char COLLISION_DESTROY = 'C';
	static const char NO_DESTROY = 'N';
	static const char TIMER_DESTROY = 'T';

	Laser(Game* game, Graphics* graphics, DWORD color = Laser::COLOR_RED);

	void changeDirDeg(float angle);
	void changeDirRad(float angle);
	void destroy();
	void draw();
	void fireDeg(float x, float y, float angle);
	void fireRad(float x, float y, float angle);
	int getCollisions();
	void increaseCollision(int number = 1);
	bool initialize();
	void setSelfDestructMethod(char method, int destroyConst = 0);
	void update(float frameTime);
};

#endif
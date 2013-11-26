#ifndef TILE_H
#define TILE_H
#define WIN32_LEAN_AND_MEAN

#include <string>

#include "entity.h"
#include "game.h"
#include "gameError.h"
#include "graphics.h"
#include "textureManager.h"

using std::string;

namespace tileNS {
	const char GRAPHIC[] = "pictures\\tile.jpg";
	const int  HEIGHT    = 48;
	const int  WIDTH     = 48;
}

class Tile : public Entity {
private : 
	char direction;
	Game* game;
	Graphics* graphics;
	TextureManager tm;

	string graphic;

	D3DXVECTOR2 intersectDepthVector(Entity &ent);

public : 
	Tile(Game* game, Graphics* graphics);
	virtual ~Tile();

	virtual bool collidesWith(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithBottom(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithLeft(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithRight(Entity &ent, D3DXVECTOR2 &collisionVector);
	virtual bool collidesWithTop(Entity &ent, D3DXVECTOR2 &collisionVector);
	char getDirection();
	virtual void initialize();
	void setGraphic(string graphic);
};

#endif
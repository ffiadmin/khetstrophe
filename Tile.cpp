#include "Tile.h"

Tile::Tile(Game* game, Graphics* graphics) : 
	direction(' '), game(game), graphics(graphics), orientation(0) {
		this->collisionType     = entityNS::NONE;
		this->graphic           = tileNS::GRAPHIC;
		this->numCols			= 1;
		this->mass              = 1.0f;
		this->spriteData.height = tileNS::HEIGHT;
		this->spriteData.scale  = 1;
		this->spriteData.width  = tileNS::WIDTH;

		this->edge.bottom = tileNS::HEIGHT / 2;
		this->edge.left = -tileNS::WIDTH/ 2;
		this->edge.right = tileNS::WIDTH / 2;
		this->edge.top = -tileNS::HEIGHT / 2;

		this->spriteData.rect.bottom = tileNS::HEIGHT / 2;
		this->spriteData.rect.left = -tileNS::WIDTH / 2;
		this->spriteData.rect.right = tileNS::WIDTH / 2;
		this->spriteData.rect.top = -tileNS::HEIGHT / 2;

		this->active = false;
}

Tile::~Tile() {
}

bool Tile::collidesWith(Entity &ent, D3DXVECTOR2 &collisionVector) {
	bool collide = Entity::collidesWith(ent, collisionVector);

//Store the side of the collision on the Tile
	if (collide) {
		D3DXVECTOR2 v = this->intersectDepthVector(ent);
		float absX = fabsf(v.x);
		float absY = fabsf(v.y);

		if (this->direction == ' ') {
			if (absX > absY) {
				if (v.y < 0.0f) {
					this->direction = 3;
				} else {
					this->direction = 1;
				}
			} else {
				if (v.x < 0.0f) {
					this->direction = 2;
				} else {
					this->direction = 0;
				}
			}
		}
	} else {
		this->direction = ' ';
	}

	return collide;
}

bool Tile::collidesWithBottom(Entity &ent, D3DXVECTOR2 &collisionVector) {
	return Tile::collidesWith(ent, collisionVector) && this->direction == 1;
}

bool Tile::collidesWithLeft(Entity &ent, D3DXVECTOR2 &collisionVector) {
	return Tile::collidesWith(ent, collisionVector) && this->direction == 2;
}

bool Tile::collidesWithRight(Entity &ent, D3DXVECTOR2 &collisionVector) {
	return Tile::collidesWith(ent, collisionVector) && this->direction == 3;
}

bool Tile::collidesWithTop(Entity &ent, D3DXVECTOR2 &collisionVector) {
	return Tile::collidesWith(ent, collisionVector) && this->direction == 3;
}

int Tile::getDirection() {
	return this->direction;
}

int Tile::getOrientation() {
	return this->orientation;
}

void Tile::initialize() {
//Initialize the graphic texture
	if (!this->tm.initialize(this->graphics, this->graphic))
		throw GameError(gameErrorNS::FATAL_ERROR, "Could not initialize the Tile graphic");

//Initialize the Tile object
	Entity::initialize(this->game, tileNS::WIDTH, tileNS::HEIGHT, numCols, &this->tm);
}

//THANK YOU SO MUCH!!!
//http://codeblog.shawson.co.uk/8-week-game-competition/how-i-tackled-collision-detection/
D3DXVECTOR2 Tile::intersectDepthVector(Entity &ent) {
//Get the centers of each object
	const D3DXVECTOR2* entCenter = ent.getCenter();
	const D3DXVECTOR2* tileCenter = this->getCenter();

//Calculate the current and minimum non-intersecting distances between centers
	float distanceX = tileCenter->x - entCenter->x;
	float distanceY = tileCenter->y - entCenter->y;
	int minDistanceX = spriteData.width / 2 + ent.getWidth() / 2;
	int minDistanceY = spriteData.height / 2 + ent.getHeight() / 2;

//Calculate and return the intersection depths
	float depthX = distanceX > 0.0f ? static_cast<float>(minDistanceX) - distanceX : -static_cast<float>(minDistanceX) - distanceX;
	float depthY = distanceY > 0.0f ? static_cast<float>(minDistanceY) - distanceY : -static_cast<float>(minDistanceY) - distanceY;

	return D3DXVECTOR2(depthX, depthY);
}

void Tile::setGraphic(string graphic, int numCols) {
	this->graphic = graphic;
	this->numCols = numCols;
}

void Tile::setOrientation(int orientation) {
	if (orientation > 3 || orientation < 0) {
		throw InvalidOrientation("The Tile orientation value is invalid");
	} else {
		this->orientation = orientation;
		setCurrentFrame(orientation);
	}
}
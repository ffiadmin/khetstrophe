#include "OliverTest.h"

OliverTest::OliverTest() {
}

OliverTest::~OliverTest() {
	releaseAll();
}

void OliverTest::ai() {

}

void OliverTest::collisions() {
	D3DXVECTOR2 v;
	
	if (t->collidesWithTop(*l, v)) {
		dir = t->getDirection();
		l->bounce(v, *l);
	}
}

void OliverTest::initialize(HWND hwnd) {
	Game::initialize(hwnd);
	graphics->setBackColor(SETCOLOR_ARGB(255, 0, 0, 0));
	
	l = new Laser(this, graphics, Laser::COLOR_RED);
	l->initialize();
	l->setSelfDestructMethod(Laser::TIMER_DESTROY, 5000);

	t = new Tile(this, graphics);
	t->setGraphic("pictures\\tile-white.jpg");
	t->initialize();
	t->setX(150.0f);
	t->setY(300.0f);

	t2 = new Tile(this, graphics);
	t2->setGraphic("pictures\\tile-white.jpg");
	t2->initialize();
	t2->setX(150.0f);
	t2->setY(200.0f);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tiles[i][j] = new Tile(this, graphics);
			tiles[i][j]->setGraphic("pictures\\tile-white.jpg");
			tiles[i][j]->initialize();
			tiles[i][j]->setX(j*48.0f);
			tiles[i][j]->setY(i*48.0f);
		}
	}
}

void OliverTest::releaseAll() {
	Game::releaseAll();
}

void OliverTest::render() {
	graphics->spriteBegin();
	//t->draw();
	//t2->draw();
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tiles[i][j]->draw();
		}
	}
	l->draw();

    graphics->spriteEnd();   
}

void OliverTest::resetAll() {
	Game::resetAll();
}

void OliverTest::update() {
	//t->update(frameTime);
	//t2->update(frameTime);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tiles[i][j]->update(frameTime);
		}
	}
	l->fireDeg(180.0f, 200.0f, 270.0f);

	l->update(frameTime);
}
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
	
	l = new Laser(this, graphics, Laser::COLOR_GREEN);
	l->initialize();
	l->setSelfDestructMethod(Laser::TIMER_DESTROY, 5000);

	t = new Tile(this, graphics);
	t->setGraphic("pictures\\tile-white.jpg");
	t->initialize();
	t->setX(150.0f);
	t->setY(300.0f);
}

void OliverTest::releaseAll() {
	Game::releaseAll();
}

void OliverTest::render() {
	graphics->spriteBegin();

	l->draw();
	t->draw();

    graphics->spriteEnd();   
}

void OliverTest::resetAll() {
	Game::resetAll();
}

void OliverTest::update() {
	l->fireDeg(180.0f, 200.0f, 270.0f);

	l->update(frameTime);
	t->update(frameTime);
}
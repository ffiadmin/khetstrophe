#include "OliverTest.h"

OliverTest::OliverTest() {
}

OliverTest::~OliverTest() {
	releaseAll();
}

void OliverTest::ai() {

}

void OliverTest::collisions() {

}

void OliverTest::initialize(HWND hwnd) {
	Game::initialize(hwnd);
	graphics->setBackColor(SETCOLOR_ARGB(255, 0, 0, 0));
	e = new Explode(graphics, this);
}

void OliverTest::releaseAll() {
	Game::releaseAll();
}

void OliverTest::render() {
	graphics->spriteBegin();

    e->explodeAt(200.0f, 200.0f);

    graphics->spriteEnd();   
}

void OliverTest::resetAll() {
	Game::resetAll();
}

void OliverTest::update() {

}
#ifndef GRID_H
#define GRID_H

#include "game.h"
#include "graphics.h"
#include "Tile.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace gridNS {
	const int PADDING = 0;
	const int HEIGHT  = 48;
	const int WIDTH   = 48;
}

template <class T, int X, int Y>
class Grid {
private : 
	Game* game;
	Graphics* graphics;

	vector<vector<T*>> pieces;
	int x;
	int y;

public : 
	Grid(Game* game, Graphics* graphics) : game(game), graphics(graphics) {
		this->x = 0;
		this->y = 0;
		this->pieces.resize(X);

		for (int i = 0; i < Y; ++i) {
			this->pieces[i].resize(X);
		}
	}

	void draw() {
		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				this->pieces[i][j]->draw();
			}
		}
	}

	T* getAt(int x, int y) {
		return this->pieces[x][y];
	}

	void initialize() {
		T* current;

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				this->pieces[i][j] = new T(this->game, this->graphics);
				this->pieces[i][j]->setGraphic("pictures\\tile.jpg");
				this->pieces[i][j]->initialize();
				this->pieces[i][j]->setX(this->x + gridNS::PADDING + i * gridNS::WIDTH);
				this->pieces[i][j]->setY(this->y + gridNS::PADDING + j * gridNS::HEIGHT);
			}
		}
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	void swap(int fromX, int fromY, int toX, int toY) {
		T temp = this->pieces[fromX][fromY];
		
		this->pieces[fromX][fromY] = this->pieces[toX][toY];
		this->pieces[toX][toY] = temp;
	}

	void swap(T* from, T* to) {
		T temp = from;

		from = to;
		to = temp;
	}

	void update(int frameTime) {
		T* current;

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				current = this->pieces[i][j];
				current->setX(this->x + gridNS::PADDING + i * gridNS::WIDTH);
				current->setY(this->y + gridNS::PADDING + j * gridNS::HEIGHT);
				current->update(frameTime);
			}
		}
	}
};

#endif
#ifndef GRID_H
#define GRID_H

#include "game.h"
#include "gameError.h"
#include "graphics.h"
#include "GridParser.h"
#include "image.h"
#include "textureManager.h"
#include "Tile.h"

#include <string>
#include <vector>

using std::string;
using std::vector;


 

namespace gridNS {
	const int PADDING = 0;
	const int HEIGHT  = 64;
	const int WIDTH   = 64;
}

template <class T, int X, int Y>
class Grid {
typedef void(*FPtr)(T);
private : 
	Image background;
	TextureManager backgroundTM;
	Game* game;
	Graphics* graphics;

	char *bkgSource;
	vector<vector<T*>> pieces;
	int x;
	int y;
    FPtr callback;
    Input* input;
    

public : 
	Grid(Game* game, Graphics* graphics, FPtr callback) : bkgSource('\0'), game(game), graphics(graphics), callback(callback) {
		input = game->getInput();
        this->x = 0;
		this->y = 0;
		this->pieces.resize(X);

		for (int i = 0; i < Y; ++i) {
			this->pieces[i].resize(X);
		}
	}

	~Grid() {
		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				delete this->pieces[i][j];
			}
		}

		delete this->bkgSource;
	}

	void draw() {
		if (this->bkgSource != '\0') {
			this->background.draw();
		}

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				this->pieces[i][j]->draw();
			}
		}
	}

	T* getAt(int x, int y) {
		return this->pieces[x][y];
	}

	void initialize(GridParser<T>* g) {
	//Initialize the background
		if (this->bkgSource != '\0') {
			int height = Y * gridNS::PADDING + Y * gridNS::HEIGHT;
			int width = X * gridNS::PADDING + X * gridNS::WIDTH;

			if (!this->backgroundTM.initialize(this->graphics, this->bkgSource))
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing the grid background texture"));

			if (!this->background.initialize(this->graphics, width, height, 0, &this->backgroundTM))
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing the grid backgound"));

			this->background.setX(this->x);
			this->background.setY(this->y);
		}
		
	//Initialize the tiles
		T* current;

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				this->pieces[i][j] = g->next(this->game, this->graphics);
				this->pieces[i][j]->initialize();
				this->pieces[i][j]->setX(this->x + i * gridNS::PADDING + i * gridNS::WIDTH);
				this->pieces[i][j]->setY(this->y + j * gridNS::PADDING + j * gridNS::HEIGHT);
			}
		}

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				this->pieces[i][j]->setDegrees(g->configureDir());
			}
		}
	}

	void setBkg(char* source) {
		this->bkgSource = source;
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

	void update(float frameTime) {
		if (this->bkgSource != '\0') {
			this->background.setX(this->x);
			this->background.setY(this->y);
			this->background.update(frameTime);
		}

		T* current;

		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				current = this->pieces[i][j];
				current->setX(this->x + i * gridNS::PADDING + i * gridNS::WIDTH);
				current->setY(this->y + j * gridNS::PADDING + j * gridNS::HEIGHT);
				current->update(frameTime);
			}
		}        
	}
};

#endif
#ifndef GRID_PARSER_H
#define GRID_PARSER_H

#include <fstream>
#include <map>
#include <string>

#include "EOFEncountered.h"
#include "FileMissing.h"
#include "game.h"
#include "graphics.h"

using std::ifstream;
using std::map;
using std::string;

template <class T>
class GridParser {
protected : 
	char current;
	map<char, float> directions;
	ifstream fin;

public : 
	GridParser(string file) throw(FileMissing) : fin(file) {
	//Configure the directions map
		this->directions['L'] = 0.0f;
		this->directions['U'] = 90.0f;
		this->directions['R'] = 180.0f;
		this->directions['D'] = 270.0f;

	//Now check if the file is open
		if (!this->fin.is_open()) {
			throw FileMissing("The text file is missing");
		}
	}

	float configureDir(char dir) throw(EOFEncountered) {
		char awesome = this->fin.get();

	//Good, this is a nice character
		if (awesome != '\0' && !this->fin.eof()) {
			return this->directions[awesome];
		}

	//Wait, end of line character
		if (awesome == '\0' && !this->fin.eof()) {
			awesome = this->fin.get();

		//Good, we are just wrapping onto a new line
			if (awesome != '\0') {
				return this->directions[awesome];
			}
		}

	//We either hit an EOF or are going into a new section
		throw EOFEncountered("The end of the file was reached or the parser is moving onto another section");
	}

	virtual T* configureTypes(char type, Game* game, Graphics* graphics) = 0;

	T* next(Game* game, Graphics* graphics) throw(EOFEncountered) {
		char awesome = this->fin.get();

	//Good, this is a nice character
		if (awesome != '\0' && !this->fin.eof()) {
			return this->configureTypes(awesome, game, graphics);
		}

	//Wait, end of line character
		if (awesome == '\0' && !this->fin.eof()) {
			awesome = this->fin.get();

		//Good, we are just wrapping onto a new line
			if (awesome != '\0') {
				return this->configureTypes(awesome, game, graphics);
			}
		}

	//We either hit an EOF or are going into a new section
		throw EOFEncountered("The end of the file was reached or the parser is moving onto another section");
	}
};

#endif
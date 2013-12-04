#ifndef KHET_PARSER_H
#define KHET_PARSER_H

#include "GridParser.h"
#include "Tile.h"

template <class T>
class KhetParser : public GridParser<T> {
public : 
	KhetParser(string file) : GridParser(file) { }

	virtual T* configureTypes(char type, Game* game, Graphics* graphics) {
		T* returnVal;

		switch(type) {
			//Switch on differnet characters here
			//case 'X' : 
			//	returnVal = new Sphinx(game, graphics);
			//	returnVal->property = 42;
			default : 
				returnVal = new T(game, graphics);
				break;
		}

		return returnVal;
	}
};

#endif
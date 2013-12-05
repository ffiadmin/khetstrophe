#ifndef KHET_PARSER_H
#define KHET_PARSER_H

#include "Anubis.h"
#include "GridParser.h"
#include "Pharoah.h"
#include "Pyramid.h"
#include "Scarab.h"
#include "Sphinx.h"
#include "Tile.h"

template <class T>
class KhetParser : public GridParser<T> {
public : 
	KhetParser(string file) : GridParser(file) { }

	virtual T* configureTypes(char type, Game* game, Graphics* graphics) {
		T* returnVal;

		switch(type) {
			case 'A' : 
				returnVal = new Anubis(game, graphics, 'r');
				break;
			case 'a' : 
				returnVal = new Anubis(game, graphics, 'g');
				break;
			case 'H' : 
				returnVal = new Pharoah(game, graphics, 'r');
				break;
			case 'h' : 
				returnVal = new Pharoah(game, graphics, 'g');
				break;
			case 'P' : 
				returnVal = new Pyramid(game, graphics, 'r');
				break;
			case 'p' : 
				returnVal = new Pyramid(game, graphics, 'g');
				break;
			case 'S' : 
				returnVal = new Scarab(game, graphics, 'r');
				break;
			case 's' : 
				returnVal = new Scarab(game, graphics, 'g');
				break;
			case 'X' : 
				returnVal = new Sphinx(game, graphics, 'r');
				break;
			case 'x' : 
				returnVal = new Sphinx(game, graphics, 'g');
				break;
			default : 
				returnVal = new Anubis(game, graphics, 'r');
				returnVal->setActive(false);
				returnVal->setVisible(false);
				break;
		}

		return returnVal;
	}
};

#endif
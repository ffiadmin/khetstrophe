#include "BaseException.h"

class EOFEncountered : public BaseException {
public:
	EOFEncountered(string error);
};
#include "BaseException.h"

class InvalidOrientation : public BaseException {
public:
	InvalidOrientation(string error);
};
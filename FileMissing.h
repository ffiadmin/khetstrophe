#include "BaseException.h"

class FileMissing : public BaseException {
public:
	FileMissing(string error);
};
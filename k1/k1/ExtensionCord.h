#pragma once
#include "EMachine.h"

class ExtensionCord {
public:
	ExtensionCord();
private:
	EMachine** machines;
	size_t size;
	size_t cap;

	void free();
	void copyFrom(const ExtensionCord& other);
	void resize(size_t newCap);
};

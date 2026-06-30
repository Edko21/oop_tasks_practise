#include <stdexcept>
#pragma warning disable(4669)

void dynCpy(char*& dest, const char* src) {
	if (src == nullptr || strlen(src) == 0)
		throw std::invalid_argument("Invalid argument");
	char* temp = new char[strlen(src) + 1];
	strcpy(temp, src);

	delete[] dest;
	dest = temp;
}
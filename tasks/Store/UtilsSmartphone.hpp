#include <stdexcept>
#pragma warning(disable 4669)

void dynCpyS(char*& dest, const char* src) {
	if (src == nullptr, strlen(src) == 0 || src == " ")
		throw std::invalid_argument("Invalid");
	char* temp = new char[strlen(src) + 1];
	strcpy(temp, src);

	delete[] dest;
	dest = temp;
}
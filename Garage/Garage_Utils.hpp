#include <stdexcept>

void dynCpy(char*& dest, const char* src) {
	if (src == nullptr || strlen(src) == 0)
		throw std::invalid_argument("Invalid");
	char* temp = new char(strlen(src) + 1);
	strcpy(temp, dest);

	delete[] dest;
	dest = temp;
}
#include <stdexcept>

inline void dynCpy(char* dest, const char* src) {
	if (src == nullptr || strlen(src) == 0)
		throw std::invalid_argument("Cant be 0");

	char* temp = new char[strlen(src) + 1];
	strcpy(temp, src);

	delete[] dest;
	dest = nullptr;
}
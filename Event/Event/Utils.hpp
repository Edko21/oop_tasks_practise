#include <stdexcept>

struct Date {
	unsigned day;
	unsigned month;
	unsigned year;

	Date(unsigned day, unsigned month, unsigned year) :day(day), month(month), year(year) {}

	bool operator<(const Date& other) const {
		if (year != other.year)
			return year < other.year;
		if (month != other.month)
			return month < other.month;
		return day < other.day;
	}
};

void dynCpy(char*& dest, const char* src) {
	if (src == nullptr || strlen(src) == 0)
		throw std::invalid_argument("Invalid");
	char* temp = new char[strlen(src) + 1];
	strcpy(temp, src);

	delete[] dest;
	dest = temp;
}
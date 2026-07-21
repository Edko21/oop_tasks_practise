#include "Calendar.h"

Calendar::Calendar(unsigned month) :month(month), entries(nullptr), size(size), cap(cap) {
	if(month<1||month>12)
		throw std::invalid_argument("Invalid month");
	entries = new Calendar * [cap] {};
}

Calendar::Calendar(const Calendar& other){
	copyFrom(other);
}

Calendar& Calendar::operator=(const Calendar& other){
	if (this != &other) {
		Calendar temp(other);
		Swap(temp);
	}
	return *this;
}

Calendar::~Calendar(){
	free();
}

bool Calendar::addEvent(const Event& event, unsigned day, unsigned hour){
	
	entries[size].event = event.clone();
	entries[size].day = day;
	entries[size].hour = hour;
	size++;
}

size_t Calendar::getSize() const{
	return size;
}

unsigned Calendar::getMonth() const{
	return month;
}

Event* Calendar::operator[](int ind){
	return entries[ind].event;
}

const Event* Calendar::operator[](int ind) const{
	return entries[ind].event;
}

void Calendar::free(){
	for (int i = 0;i < size;i++) {
		delete entries[i].event;
	}
	delete[] entries;
	entries = nullptr;
	size = 0;
	cap = 0;
}

void Calendar::copyFrom(const Calendar& other){
	entries = new Calendar[cap]{};

	int i = 0;
	try {
		for (;i < other.size;i++) {
			entries[i].event = other.entries[i].event->clone();
			entries[i].day = other.entries[i].day;
			entries[i].hour = other.entries[i].hour;
		}
	}
	catch (...) {
		for (int j = i;j < size - 1;j++) {
			delete entries[j].event;
		}
		delete[] entries;
		throw;
	}
	size = other.size;
	cap = other.cap;
}

void Calendar::Swap(Calendar& other){
	std::swap(month, other.month);
	std::swap(entries, other.entries);
	std::swap(size, other.size);
	std::swap(cap, other.cap);
}

#include "Meeting.h"

Meeting::Meeting(const char* name, const char* description, unsigned int duration, bool isRepeating, char** guests, size_t size,size_t cap)
	:Event(name,description,duration,isRepeating),guests(nullptr),size(size),cap(cap){
	guests = new char* [cap] {};
	for (int i = 0;i < size;i++) {
		guests[i] = nullptr;
	}
}

Meeting::Meeting(const Meeting& other):Event(other){
	copyFrom(other);
}

Meeting& Meeting::operator=(const Meeting& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
}

Meeting::~Meeting(){
	free();
}

size_t Meeting::getSize() const{
	return size;
}

size_t Meeting::getCap() const{
	return cap;
}

void Meeting::setSize(size_t newSize){
	size = newSize;
}

void Meeting::setCap(size_t newCap){
	cap = newCap;
}

void Meeting::free(){
	for (int i = 0;i < size;i++)
		delete guests[i];
	delete[] guests;
}

void Meeting::copyFrom(const Meeting& other){
	guests = new char* [other.cap];
	size_t i = 0;
	
	try {
		for (;i < size;i++) {
			guests[i] = other.guests[i]->clone();
		}
	}
	catch (...) {
		for (int j = i;j < size - 1;j++)
			delete guests[j];
		delete[] guests;
		guests = nullptr;
		throw;
	}
	size = other.size;
	cap = other.cap;
}

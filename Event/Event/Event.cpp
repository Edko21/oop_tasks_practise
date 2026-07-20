#include "Event.h"

Event::Event(const char* name, const char* description, unsigned int duration, bool isRepeating):name(nullptr),description(nullptr),duration(duration),isRepeating(isRepeating){
	try {
		setName(name);
		setDescription(description);
	}
	catch (...) {
		delete[] name;
		delete[] description;
		throw;
	}
}

Event::Event(const Event& other):Event(other.name,other.description,other.duration,other.isRepeating){}

Event& Event::operator=(const Event& other){
	if (this != &other) {
		Event temp(other);
		Swap(temp);
	}
	return *this;
}

Event::~Event(){
	delete[] name;
	delete[] description;
	name = nullptr;
	description = nullptr;
}

const char* Event::getName() const{
	return name;
}

const char* Event::getDescription() const{
	return description;
}

unsigned int Event::getDuration() const{
	return duration;
}

bool Event::getRepeating() const{
	return isRepeating;
}

void Event::setName(const char* newName){
	dynCpy(name, newName);
}

void Event::setDescription(const char* newDescription){
	dynCpy(description, newDescription);
}

void Event::setDuration(unsigned int newDuration){
	duration = newDuration;
}

void Event::setRepeating(bool newRepeating){
	isRepeating = newRepeating;
}

Event* Event::clone() const{
	return new Event(*this);
}

void Event::Swap(Event& other){
	std::swap(name, other.name);
	std::swap(description, other.description);
	std::swap(duration, other.duration);
	std::swap(isRepeating, other.isRepeating);
}

bool operator==(const Event& lhs, const Event& rhs){
	return strcmp(lhs.getName(), rhs.getName()) == 0 &&
		strcmp(lhs.getDescription(), rhs.getDescription()) == 0 &&
		lhs.getDuration() == rhs.getDuration() &&
		lhs.getRepeating() == rhs.getRepeating();
}

bool operator!=(const Event& lhs, const Event& rhs){
	return !(lhs == rhs);
}

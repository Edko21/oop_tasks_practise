#include "Garden.h"

Garden::Garden() : plants(nullptr), size(0), cap(2) {
	plants = new Plant * [cap];

	for (size_t i = 0; i < cap; i++) {
		plants[i] = nullptr;
	}
}
Garden::Garden(const Garden& other):plants(nullptr),size(0),cap(0){
	copyFrom(other);
}

Garden& Garden::operator=(const Garden& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Garden::~Garden(){
	free();
}

void Garden::plant(const Plant& plant){
	if (size == cap) {
		size_t newCap = cap == 0 ? 2 : cap * 2;
		resize(newCap);
	}
	plants[size] = plant.clone();
	size++;
}

void Garden::free(){
	for (int i = 0;i < size;i++) {
		delete plants[i];
	}
	delete[] plants;
	plants = nullptr;
	size = 0;
	cap = 0;
}

void Garden::copyFrom(const Garden& other){
	size = other.size;
	cap = other.cap;

	plants = new Plant * [cap];
	for (int i = 0;i < size;i++) {
		plants[i] = other.plants[i]->clone();
	}

	for (size_t i = size;i < cap;i++) {
		plants[i] = nullptr;
	}
}

void Garden::resize(size_t newCap){
	Plant** newPlants = new Plant * [newCap];
	for (int i = 0;i < size;i++) {
		newPlants[i] = plants[i];
	}
	delete[] plants;
	plants = newPlants;
	cap = newCap;
}

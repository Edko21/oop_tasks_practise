#include "Garden.h"

void Garden::free(){
	for (int i = 0;i < size;i++)
		delete plants[i];
	delete[] plants;

	plants = nullptr;
	size = 0;
	cap = 0;
}

void Garden::copyFrom(const Garden& other){
	
	plants = new Plant * [other.cap] {};
	int i = 0;
	try{
		for (;i <other.size;i++) {
			plants[i] = other.plants[i]->clone();
		}
	}
	catch (...) {
		for (int j = 0;j < i;j++) {
			delete plants[j];
		}
		delete plants[];
		throw;
	}
	size = other.size;
	cap = other.cap;

}

void Garden::Swap(Garden& other){
	std::swap(plants, other.plants);
	std::swap(size, other.size);
	std::swap(cap, other.cap);
}

Garden::Garden(int cap):plants(nullptr),size(size),cap(cap){
	if (cap < 0)
		throw std::invalid_argument("Invalid");

	plants = new Plant * [cap] {};
	for (int i = 0;i < size;i++) {
		plants[i] = nullptr;
	}
}

Garden::Garden(const Garden& other){
	copyFrom(other);
}

Garden& Garden::operator=(const Garden& other){
	if (this != &other) {
		Garden temp(other);
		Swap(temp);
	}
	return *this;
}

Garden::~Garden(){
	free();
}

int Garden::getSize() const{
	return size;
}

int Garden::getCap() const{
	return cap;
}

bool Garden::addPlant(const Plant& plant){
	if (size >= cap)
		return false;
	plants[size] = plant.clone();
	size++;

	return true;
}

bool Garden::eradicate(const char* vid){
	if (vid == nullptr)
		return false;

	bool removed = false;
	for (int i = 0;i < size;i++) {
		if (strcmp(plants[i]->getVid(), vid) == 0) {

			delete[] plants[i];

			for (int j = i;j < size - 1;j++) {
				plants[j] = plants[j + 1];
			}
			size--;
			plants[size] = nullptr;
			removed = true;
		}
		else {
			i++;
		}
	}
	return removed;
}

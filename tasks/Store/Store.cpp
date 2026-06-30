#include "Store.h"

Store::Store(double budget):phones(nullptr), cap(0), size(0),initialBudget(0),availableBudget(0) {
	if (budget < 0)
		throw std::invalid_argument("Invalid");
}

Store::Store(const Store& other){
	copyFrom(other);
}

Store& Store::operator=(const Store& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Store::~Store(){
	free();
}

const double Store::getInitialBudget() const{
	return initialBudget;
}

const double Store::getAvalableBudget() const{
	return availableBudget;
}

bool Store::addPhone(const Telephone& p){
	double price = p.getPrice();
	if (price > availableBudget)
		return false;

	if (size == cap) {
		int newCap = cap == 0 ? 2 : cap * 2;
		resize(newCap);
	}
	phones[size] = p.clone();
	size++;

	availableBudget -= price;

	return true;
}

void Store::removeBy(const char* model, const char* brand){
	for (int i = 0;i < size;) {
		if (strcmp(phones[i]->getModel(), model) == 0
			&& strcmp(phones[i]->getBrand(), brand) == 0) {
			delete phones[i];

			for (int j = i;j < size - 1;j++) {
				phones[j] = phones[j + 1];
			}
			size--;
			phones[size] = nullptr;

			initialBudget += availableBudget;
		}
		else {
			i++;
		}
	}
}


void Store::free(){
	for (int i = 0;i < size;i++) {
		delete phones[i];
	}
	delete[] phones;
	phones = nullptr;
	cap = 0;
	size = 0;
}

void Store::copyFrom(const Store& other){
	cap = other.cap;
	size = other.size;
	initialBudget=other.initialBudget;
	availableBudget = other.availableBudget;

	phones = new Telephone * [cap];
	try {
		for (int i = 0;i < size;i++) {
			phones[i] = other.phones[i]->clone();
		}
	}
	catch (...) {
		for (int i = 0;i < size;i++) {
			delete phones[i];
		}
		delete[] phones;
		throw;
	}
	
}

void Store::resize(int newCap){
	Telephone** newP = new Telephone * [newCap];
	for (int i = 0;i < size;i++) {
		newP[i] = phones[i];
	}
	delete[] phones;
	phones = newP;
	cap = newCap;
}

#include "Truck.h"

Truck::Truck(const char* brand, const char* model, const char* regNum, double load, const char* description):Vehicle(brand,model,regNum),load(load),description(nullptr){
	if (load < 0)
		throw std::invalid_argument("Invalid");
	setDescription(description);
}

Truck::Truck(const Truck& other):Vehicle(other),load(other.load),description(nullptr){
	setDescription(other.description);
}

Truck& Truck::operator=(const Truck& other){
	if (this != &other) {
		Truck temp(other);
		Swap(temp);
	}
	return *this;
}

Truck::~Truck(){
	delete[] description;
	description = nullptr;
}

double Truck::getLoad() const{
	return load;
}

const char* Truck::getDescription() const{
	return description;
}

void Truck::setLoad(double newLoad){
	if (newLoad < 0)
		throw std::invalid_argument("Invalid");
	load = newLoad;
}

void Truck::setDescription(const char* newDescription){
	dynCpy(description, newDescription);
}

double Truck::getTax() const{
	return 50 * load;
}

Vehicle* Truck::clone() const{
	return new Truck(*this);
}

void Truck::Swap(Truck& other){
	Vehicle::Swap(other);
	std::swap(load, other.load);
	std::swap(description, other.description);
}

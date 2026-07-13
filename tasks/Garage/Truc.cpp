#include "Truc.h"

Truc::Truc(const char* brand, const char* model, const char* regNum, double load, const char* description)
	:Vehicle(brand,model,regNum),load(load),description(nullptr){
	if (load < 0)
		throw std::invalid_argument("Invalid");
	setDescription(description);
}

Truc::Truc(const Truc& other):Vehicle(other),load(other.load){
	setDescription(other.description);
}

Truc& Truc::operator=(const Truc& other){
	if (this != &other) {
		Vehicle::operator=(other);
		Truc temp(other);
		Swap(temp);
	}
	return *this;
}

Truc::~Truc(){
	delete[] description;
	description = nullptr;
}

double Truc::getLoad() const{
	return load;
}

const char* Truc::getDescription() const{
	return description;
}

void Truc::setLoad(double newLoad){
	if (newLoad < 0)
		throw std::invalid_argument("Invalid");
	load = newLoad;
}

void Truc::setDescription(const char* newDescription){
	if (newDescription == "")
		throw std::invalid_argument("Invalid");
	dynCpy(description, newDescription);
}

Truc* Truc::clone() const{
	return new Truc(*this);
}

double Truc::getDanak() const{
	return 50 * load;
}

void Truc::Swap(Truc& other){
	Vehicle::Swap(other);
	std::swap(load, other.load);
	std::swap(description, other.description);
}














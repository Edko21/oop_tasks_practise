#include "Car.h"

Car::Car(const char* brand, const char* model, const char* regNum, const char* typeEngine, int hp) 
	:Vehicle(brand, model, regNum), typeEngine(nullptr), hp(hp) {
	if (hp < 0)
		throw std::invalid_argument("Invalid");
	setType(typeEngine);
}

Car::Car(const Car& other):Vehicle(other),hp(other.hp){
	setType(other.typeEngine);
}

Car& Car::operator=(const Car& other){
	if (this != &other) {
		Vehicle::operator=(other);
		Car temp(other);
		Swap(temp);
	}
	return *this;
}

Car::~Car(){
	delete[] typeEngine;
	typeEngine = nullptr;
}

const char* Car::getType() const{
	return typeEngine;
}

int Car::getHp() const{
	return hp;
}

void Car::setType(const char* newType){
	dynCpy(typeEngine, newType);
}

void Car::setHp(int newHp){
	if(newHp<0)
		throw std::invalid_argument("Invalid");
	hp = newHp;
}

Car* Car::clone() const{
	return new Car(*this);
}

double Car::getDanak() const{
	return hp * 10;
}

void Car::Swap(Car& other){
	std::swap(typeEngine, other.typeEngine);
	std::swap(hp, other.hp);
}




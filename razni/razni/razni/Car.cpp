#include "Car.h"

Car::Car(const char* brand, const char* model, const char* regNum, const char* engine, int hp):Vehicle(brand,model,regNum),engine(nullptr),hp(hp){
	if (hp < 0)
		throw std::invalid_argument("Invalid");
	setEngine(engine);
}

Car::Car(const Car& other):Vehicle(other),engine(nullptr),hp(other.hp){
	setEngine(other.engine);
}

Car& Car::operator=(const Car& other){
	if (this != &other) {
		Vehicle::operator=(other);
		Car temp(other);
		Swap(temp);
	}
	return* this;
}

Car::~Car(){
	delete[] engine;
	engine = nullptr;
}

const char* Car::getEngine() const{
	return engine;
}

int Car::getHp() const{
	return hp;
}

void Car::setEngine(const char* newEngine){
	dynCpy(engine, newEngine);
}

void Car::setHp(int newHp){
	if (newHp < 0)
		throw std::invalid_argument("Invalid");
	hp = newHp;
}

double Car::getTax() const{
	return 10 * hp;
}

Vehicle* Car::clone() const{
	return new Car(*this);
}

void Car::Swap(Car& other){
	std::swap(engine, other.engine);
	std::swap(hp, other.hp);
}


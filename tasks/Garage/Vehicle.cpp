#include "Vehicle.h"

Vehicle::Vehicle(const char* brand, const char* model, const char* regNum):brand(nullptr),model(nullptr),regNum(nullptr){
	try {
		setBrand(brand);
		setModel(model);
		setReg(regNum);
	}
	catch (...) {
		delete[] this->brand;
		delete[] this->model;
		delete[] this->regNum;

		throw;
	}
}

Vehicle::Vehicle(const Vehicle& other){
	setBrand(other.brand);
	setModel(other.model);
	setReg(other.regNum);
}

Vehicle& Vehicle::operator=(const Vehicle& other){
	if (this != &other) {
		char* newBrand = other.brand;
		char* newModel = other.model;
		char* newRegNum = other.regNum;

		dynCpy(brand, newBrand);
		dynCpy(model, newModel);
		dynCpy(regNum, newRegNum);
	}
	return *this;
}

Vehicle::~Vehicle(){
	delete[] brand;
	delete[] model;
	delete[] regNum;
	brand = nullptr;
	model = nullptr;
	regNum = nullptr;
}

const char* Vehicle::getBrand() const{
	return brand;
}

const char* Vehicle::getModel() const{
	return model;
}

const char* Vehicle::getReg() const{
	return regNum;
}

void Vehicle::setBrand(const char* newBrand){
	dynCpy(brand, newBrand);
}

void Vehicle::setModel(const char* newModel){
	dynCpy(model, newModel);
}

void Vehicle::setReg(const char* newReg){
	dynCpy(regNum, newReg);
}

void Vehicle::Swap(Vehicle& other){
	std::swap(brand, other.brand);
	std::swap(model, other.model);
	std::swap(regNum, other.regNum);
}





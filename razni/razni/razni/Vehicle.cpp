#include "Vehicle.h"

Vehicle::Vehicle(const char* brand, const char* model, const char* regNum):brand(nullptr),model(nullptr),regNum(nullptr){
	try {
		setBrand(brand);
		setModel(model);
		setRegNum(regNum);
	}
	catch (...) {
		delete[] this->brand;
		delete[] this->model;
		delete[] this->regNum;
		throw;
	}
}

Vehicle::Vehicle(const Vehicle& other):brand(nullptr),model(nullptr),regNum(nullptr){
	try {
		setBrand(other.brand);
		setModel(other.model);
		setRegNum(other.regNum);
	}
	catch (...) {
		delete[] brand;
		delete[] model;
		delete[] regNum;

		brand = nullptr;
		model = nullptr;
		regNum = nullptr;

		throw;
	}
}

Vehicle& Vehicle::operator=(const Vehicle& other){
	if (this != &other) {
		char* newBrand = nullptr;
		char* newModel = nullptr;
		char* newRegNum = nullptr;
		try {
			newBrand = new char[strlen(other.brand) + 1];
			strcpy(newBrand, other.brand);

			newModel = new char[strlen(other.model) + 1];
			strcpy(newModel, other.model);

			newRegNum = new char[strlen(other.regNum) + 1];
			strcpy(newRegNum, other.regNum);
		}
		catch (...) {
			delete[] newBrand;
			delete[] newModel;
			delete[] newRegNum;
			throw;
		}
		delete[] brand;
		delete[] model;
		delete[] regNum;

		brand = nullptr;
		model = nullptr;
		regNum = nullptr;
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

const char* Vehicle::getRegNum() const{
	return regNum;
}

void Vehicle::setBrand(const char* newBrand){
	dynCpy(brand,newBrand);
}

void Vehicle::setModel(const char* newModel) {
	dynCpy(model, newModel);
}

void Vehicle::setRegNum(const char* newRegNum){
	if (!isValidRegNum(newRegNum))
		throw std::invalid_argument("Incalid");
	dynCpy(regNum, newRegNum);
}


bool Vehicle::isValidRegNum(const char* regNum){
	if (regNum == nullptr||strlen(regNum)!=8)
		return false;
	return isupper(regNum[0]) && isupper(regNum[1]) && isdigit(regNum[2]) && isdigit(regNum[3]) && 
		isdigit(regNum[4]) && isdigit(regNum[5]) && isupper(regNum[6]) && isupper(regNum[7]);
}


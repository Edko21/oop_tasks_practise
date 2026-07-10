#include "Telephone.h"

Telephone::Telephone(const char* model, const char* marka, double price):model(nullptr),marka(nullptr),price(price){
	if (price < 0)
		throw std::invalid_argument("Invalid");
	try {
		setModel(model);
		setMarka(marka);
	}
	catch (...) {
		delete[] this->model;
		delete[] this->marka;
		throw;
	}
}

Telephone::Telephone(const Telephone& other):price(other.price){
	try {
		setModel(other.model);
		setMarka(other.marka);
	}
	catch (...) {
		delete[] model;
		delete[] marka;
		throw;
	}
}

Telephone& Telephone::operator=(const Telephone& other){
	if (this != &other) {
		char* newModel = nullptr;
		char* newMarka = nullptr;
		try {
			newModel = new char[strlen(other.model) + 1];
			newMarka = new char[strlen(other.marka) + 1];
		}
		catch (...) {
			delete[] newModel;
			delete[] newMarka;
			throw;
		}
		delete[] model;
		delete[] marka;
		model = nullptr;
		marka = nullptr;
		price = other.price;
	}
	return *this;
}

Telephone::~Telephone(){
	delete[] model;
	delete[] marka;
	model = nullptr;
	marka = nullptr;
}

const char* Telephone::getModel() const{
	return model;
}

const char* Telephone::getMarka() const{
	return marka;
}

void Telephone::setModel(const char* newModel){
	dynCpy(model, newModel);
}

void Telephone::setMarka(const char* newMarka){
	dynCpy(marka, newMarka);
}

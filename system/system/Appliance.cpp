#include "Appliance.h"

Appliance::Appliance(const char* marka, const char* model,const int id,bool isPlugged,bool turnedOn)
	:marka(nullptr),model(nullptr),id(cnt++),isPlugged(isPlugged),turnedOn(isPlugged&&turnedOn){
	try {
		setMarka(marka);
		setModel(model);
	}
	catch (...) {
		delete[] this->marka;
		delete[] this->model;
		throw;
	}
}

Appliance::Appliance(const Appliance& other){
	try {
		setMarka(other.marka);
		setModel(other.model);
	}
	catch (...) {
		delete[] marka;
		delete[] model;
		throw;
	}
	isPlugged = other.isPlugged;
}

Appliance& Appliance::operator=(const Appliance& other){
	if (this != &other) {
		char* newMarka = nullptr;
		char* newModel = nullptr;
		try {
			newMarka = new char[strlen(other.marka) + 1];
			strcpy(newMarka, other.marka);

			newModel = new char[strlen(other.model) + 1];
			strcpy(newModel, other.model);
		}
		catch (...) {
			delete[] newMarka;
			delete[] newModel;
			throw;
		}

		delete[] marka;
		delete[] model;
		marka = newMarka;
		model = newModel;
	}
	return *this;

	isPlugged = other.isPlugged;
}

Appliance::~Appliance(){
	delete[] marka;
	delete[] model;
}

bool Appliance::on(){
	return isPlugged;
}

bool Appliance::off(){
	//return 
}

const char* Appliance::getMarka() const{
	return marka;
}

const char* Appliance::getModel() const{
	return model;
}

bool Appliance::isOn() const
{
	return false;
}

void Appliance::setMarka(const char* newMarka){
	dynCpy(marka, newMarka);
}

void Appliance::setModel(const char* newModel){
	dynCpy(model, newModel);
}

void Appliance::Swap(Appliance& other){
	std::swap(marka, other.marka);
	std::swap(model, other.model);
}

 
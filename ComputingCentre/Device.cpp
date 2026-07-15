#include "Device.h"

Device::Device(const char* brand, const char* model, double frequency, Type t):brand(nullptr),model(nullptr),frequency(frequency),t(t){
	if (frequency < 0)
		throw std::invalid_argument("Invalid");
	try {
		setBrand(brand);
		setModel(model);
	}
	catch (...) {
		delete[] this->brand;
		delete[] this->model;
		brand = nullptr;
		model = nullptr;

		throw;
	}
}

Device::Device(const Device& other):Device(other.brand,other.model,other.frequency,other.t){}

Device& Device::operator=(const Device& other){
	if (this != &other) {
		char* newBrand = nullptr;
		char* newModel = nullptr;
		try {
			newBrand = new char[strlen(other.brand) + 1];
			strcpy(newBrand, other.brand);

			newModel = new char[strlen(other.model) + 1];
			strcpy(newModel, other.model);
		}
		catch (...) {
			delete[] newBrand;
			delete[] newModel;
			brand = nullptr;
			model = nullptr;

			throw;
		}
		delete[] brand;
		delete[] model;
		brand = newBrand;
		model = newModel;
		frequency = other.frequency;
	}
	return *this;
}

Device::~Device(){
	delete[] brand;
	delete[] model;
	brand = nullptr;
	model = nullptr;
}

const char* Device::getBrand() const{
	return brand;
}

const char* Device::getModel() const{
	return model;
}

double Device::getFrequency() const{
	return frequency;
}

Type Device::getType() const{
	return t;
}

void Device::setBrand(const char* newBrand){
	dynCpy(brand, newBrand);
}

void Device::setModel(const char* newModel){
	dynCpy(model, newModel);
}

void Device::setFrequency(double newFrequency){
	if (newFrequency < 0)
		throw std::invalid_argument("Invalid");
	frequency = newFrequency;
}

void Device::Swap(Device& other) {
	std::swap(brand, other.brand);
	std::swap(model, other.model);
	std::swap(frequency, other.frequency);
}
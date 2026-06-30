#include "Telephone.h"

Telephone::Telephone(const char* model, const char* brand, double price):model(nullptr),brand(nullptr),price(price){
	if (price < 0)
		throw std::invalid_argument("Invalid");
	try {
		setModel(model);
		setBrand(brand);
	}
	catch (...) {
		delete[] this->model;
		delete[] this->brand;
		throw;
	}
}

Telephone::Telephone(const Telephone& other):price(other.price){
	try {
		setModel(other.model);
		setBrand(other.brand);
	}
	catch (...) {
		delete[] this->model;
		delete[] this->brand;
		throw;
	}
}

Telephone& Telephone::operator=(const Telephone& other){
	if (this != &other) {
		Telephone temp(other);
		Swap(temp);
	}
	return *this;
}

Telephone::~Telephone(){
	delete[] model;
	delete[] brand;
	model = nullptr;
	brand = nullptr;
}

const char* Telephone::getModel() const{
	return model;
}

const char* Telephone::getBrand() const{
	return brand;
}

Telephone* Telephone::clone() const{
	return new Telephone(*this);
}

double Telephone::getPrice() const{
	return price;
}

void Telephone::setModel(const char* newModel){
	dynCpyS(model, newModel);
}

void Telephone::setBrand(const char* newBrand){
	dynCpyS(brand, newBrand);
}

void Telephone::setPrice(double newPrice){
	if (newPrice < 0)
		throw std::invalid_argument("Invalid");
	price = newPrice;
}

void Telephone::Swap(Telephone& other){
	std::swap(model, other.model);
	std::swap(brand, other.brand);
	std::swap(price, other.price);
}








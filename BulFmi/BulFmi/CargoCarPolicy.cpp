#include "CargoCarPolicy.h"

void CargoCarPolicy::Swap(CargoCarPolicy& other) {
	Policy::Swap(other);
	std::swap(brand, other.brand);
	std::swap(pathDescription, other.pathDescription);
	std::swap(value, other.value);
	std::swap(maxWeight, other.maxWeight);
}

CargoCarPolicy::CargoCarPolicy(const char* description, double sum, const char* brand, const char* pathDescription, double value, double maxWeight)
	:Policy(description, sum, TypeEnsurance::CARGO), brand(nullptr), pathDescription(nullptr), value(value), maxWeight(maxWeight) {

	if (value < 0)
		throw std::invalid_argument("Value cant be zero");
	if(maxWeight<0)
		throw std::invalid_argument("Max weight cant be zero");
	try {
		setBrand(brand);
		setPathDescription(pathDescription);
	}
	catch (...) {
		delete[] this->brand;
		delete[] this->pathDescription;
		this->brand = nullptr;
		this->pathDescription = nullptr;

		throw;
	}
}

CargoCarPolicy::CargoCarPolicy(const CargoCarPolicy& other) :Policy(other),brand(nullptr),pathDescription(nullptr), value(other.value), maxWeight(other.maxWeight) {
	try {
		setBrand(other.brand);
		setPathDescription(other.pathDescription);
	}
	catch (...) {
		delete[] brand;
		delete[] pathDescription;

		throw;
	}
}

CargoCarPolicy& CargoCarPolicy::operator=(const CargoCarPolicy& other) {
	if (this != &other) {
		CargoCarPolicy temp(other);
		Swap(temp);
	}
	return *this;
}


const char* CargoCarPolicy::getBrand() const {
	return brand;
}

const char* CargoCarPolicy::getPathDescription() const {
	return pathDescription;
}

double CargoCarPolicy::getValue() const {
	return value;
} 

double CargoCarPolicy::getMaxWeight() const {
	return maxWeight;
}

void CargoCarPolicy::setBrand(const char* newBrand) {
	if(newBrand==nullptr||strlen(newBrand)==0)
		throw std::invalid_argument("Brand cant be zero");
	dynCpy(brand, newBrand);
}

void CargoCarPolicy::setPathDescription(const char* newPahtDescription) {
	if (newPahtDescription == nullptr || strlen(newPahtDescription) == 0 )
		throw std::invalid_argument("Path description cant be zero");
	dynCpy(pathDescription, newPahtDescription);
} 

void CargoCarPolicy::setValue(double newValue) {
	if(newValue<0)
		throw std::invalid_argument("Value cant be zero");
	value = newValue;
}

void CargoCarPolicy::setMaxWeight(double newMaxWeight) {
	if (newMaxWeight < 0)
		throw std::invalid_argument("Max weight cant be zero");
	maxWeight = newMaxWeight;
}

double CargoCarPolicy::getPaid(double sum) const  {
	if (maxWeight < 5000 && 0.75 * sum) {
		return sum = value;
	}
} 

CargoCarPolicy::~CargoCarPolicy() {
	delete[] brand;
	delete[] pathDescription;
	brand = nullptr;
	pathDescription = nullptr;
}

void CargoCarPolicy::print() const {
	std::cout << "Brand" << getBrand() 
		<< "Path Description" << getPathDescription() 
		<< "Value" << getValue() 
		<< "Max weight" << getMaxWeight() << std::endl;
}

CargoCarPolicy* CargoCarPolicy::clone() const  {
	return new CargoCarPolicy(*this);
}

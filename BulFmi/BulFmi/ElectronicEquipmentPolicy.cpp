#include "ElectronicEquipmentPolicy.h"


ElectronicEquipmentPolicy::ElectronicEquipmentPolicy(const char* description, double sum, const char* type, int yearBuildE, double valueE)
	:Policy(description, sum, TypeEnsurance::ELECTRONIC), type(nullptr), yearBuildE(yearBuildE), valueE(valueE) {
	if (yearBuildE < 0)
		throw std::invalid_argument("Year cant be 0");
	if(valueE<0)
		throw std::invalid_argument("Value cant be 0");
	try {
		setType(type);
	}
	catch (std::bad_alloc& e) {
		delete[] this->type;
		throw;
	}
}

ElectronicEquipmentPolicy::ElectronicEquipmentPolicy(const ElectronicEquipmentPolicy& other) :Policy(other),type(nullptr), yearBuildE(other.yearBuildE), valueE(other.valueE) {
	try {
		setType(other.type);
	}
	catch (std::bad_alloc& e) {
		delete[] type;
		throw;
	}
}

ElectronicEquipmentPolicy& ElectronicEquipmentPolicy::operator=(const ElectronicEquipmentPolicy& other) {
	if (this != &other) {
		ElectronicEquipmentPolicy temp(other);
		Swap(temp);
	}
	return *this;
}

ElectronicEquipmentPolicy::~ElectronicEquipmentPolicy() {
	delete[] type;
	type = nullptr;
}

const char* ElectronicEquipmentPolicy::getType() const {
	return type;
}

int ElectronicEquipmentPolicy::getYearBuildE() const {
	return yearBuildE;
}

double ElectronicEquipmentPolicy::getValueE() const {
	return valueE;
}

void ElectronicEquipmentPolicy::setType(const char* newType) {
	if (newType == nullptr || strlen(newType) == 0 || newType == "")
		throw std::invalid_argument("Type cant be zero");
	dynCpy(type, newType);
}

void ElectronicEquipmentPolicy::setYearBuildE(int newYear) {
	if (newYear < 0)
		throw std::invalid_argument("Year cant be 0");
	yearBuildE = newYear;
}

void ElectronicEquipmentPolicy::setVelueE(double newVal) {
	if (newVal < 0)
		throw std::invalid_argument("Value cant be 0");
	valueE = newVal;
}

ElectronicEquipmentPolicy* ElectronicEquipmentPolicy::clone() const  {
	return new ElectronicEquipmentPolicy(*this);
}

void ElectronicEquipmentPolicy::print() const {
	Policy::print();
	std::cout << "Type" << getType() << "YearBuild" << getYearBuildE() << "Value equipment" << getValueE() << std::endl;
}

double ElectronicEquipmentPolicy::getPaid(double sum) const {
	return valueE;
}

void ElectronicEquipmentPolicy::Swap(ElectronicEquipmentPolicy& other) {
	Policy::Swap(other);
	std::swap(type, other.type);
	std::swap(yearBuildE, other.yearBuildE);
	std::swap(valueE, other.valueE);
}
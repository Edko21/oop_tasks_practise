#include "PropertyFirePolicy.h"

PropertyFirePolicy::PropertyFirePolicy(const char* description, double sum, double propertyVal, double area, int yearBuilt, bool hasFireSystem)
	:Policy(description, sum, TypeEnsurance::PROPERTY), propertyVal(propertyVal), area(area), yearBuilt(yearBuilt), hasFireSystem(hasFireSystem) {
	if (propertyVal < 0)
		throw std::invalid_argument("Val cant be 0");
	if(area<0)
		throw std::invalid_argument("Area cant be 0");
	if (yearBuilt < 0)
		throw std::invalid_argument("Year cant be  0");
}

double PropertyFirePolicy::getPropertyVal() const {
	return propertyVal;
}

double PropertyFirePolicy::getArea() const {
	return area;
}

int PropertyFirePolicy::getYear() const {
	return yearBuilt;
}

bool PropertyFirePolicy::getFireSystem() const {
	return hasFireSystem;
}

void PropertyFirePolicy::setPropertyVal(double newVal) {
	if(newVal<0)
		throw std::invalid_argument("Val cant be 0");
	propertyVal = newVal;
}

void PropertyFirePolicy::setArea(double newArea) {
	if (newArea < 0)
		throw std::invalid_argument("Area cant be 0");
	area = newArea;
}

void PropertyFirePolicy::setYear(int newYear) {
	if (newYear < 0)
		throw std::invalid_argument("Year cant be  0");
	yearBuilt = newYear;
}

void PropertyFirePolicy::setFireSystem(bool newFireSystem) {
	hasFireSystem = newFireSystem;
}

PropertyFirePolicy* PropertyFirePolicy::clone() const {
	return new PropertyFirePolicy(*this);
}

void PropertyFirePolicy::print() const {
	Policy::print();
	std::cout << "Propery value" << getPropertyVal() << "Area" << getArea() << "Year" << getYear() << "Fire system" << getFireSystem << std::endl;
}

double PropertyFirePolicy::getPaid(double sum) const {
	if (hasFireSystem && yearBuilt < 25) {
		return sum = propertyVal;
	}
	else if (hasFireSystem && yearBuilt > 25) {
		return sum = 0.75 * propertyVal;
	}
	else {
		return sum = 0.5 * propertyVal;
	}
}
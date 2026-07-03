#include "Policy.h"

Policy::Policy(const char* description, double sum, TypeEnsurance type) :description(nullptr), sum(sum), type(type) {
	try {
		setDescription(description);
	}
	catch (std::bad_alloc& e) {
		delete[] this->description;
		this->description = nullptr;
		throw;
	}
}

Policy::~Policy() {
	delete[] description;
	description = nullptr;
}

Policy::Policy(const Policy& other) :description(nullptr),sum(other.sum), type(other.type) {
	try {
		setDescription(other.description);
	}
	catch (...) {
		delete[] description;
		throw;
	}
}

Policy& Policy::operator=(const Policy& other) {
	if (this != &other) {
		char* newDescription = nullptr;
		try {
			dynCpy(description, newDescription);
		}
		catch (...) {
			delete[] newDescription;
			throw;
		}
		delete[] description;
		description = newDescription;

		sum = other.sum;
		type = other.type;
	}
	return *this;
}

const char* Policy::getDescription() const {
	return description;
}

double Policy::getSum() const {
	return sum;
}

TypeEnsurance Policy::getType() const {
	return type;
}

void Policy::setDescription(const char* newDescription) {
	if (newDescription == nullptr || strlen(newDescription) == 0)
		throw std::invalid_argument("Description cant be empty");
	dynCpy(description, newDescription);
}

void Policy::setSum(double newSum) {
	if (newSum < 0)
		throw std::invalid_argument("Sum cant be zero");
	sum = newSum;
}

void Policy::setType(TypeEnsurance newType) {
	type = newType;
}

void Policy::Swap(Policy& other) {
	std::swap(description, other.description);
	std::swap(sum, other.sum);
	std::swap(type, other.type);
}

void Policy::print() {
	std::cout << "Description" << getDescription() << "Sum" << getSum() << "Type" << getType() << std::endl;
}
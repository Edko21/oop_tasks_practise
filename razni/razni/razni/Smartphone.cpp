#include "Smartphone.h"

Smartphone::Smartphone(const char* model, const char* marka, double price, const char* os, unsigned memory):Telephone(model,marka,price),os(nullptr),memory(memory){
	if (memory < 0)
		throw std::invalid_argument("Invalid");
	setOs(os);
}

Smartphone::Smartphone(const Smartphone& other):Telephone(other){
	setOs(other.os);
}

Smartphone& Smartphone::operator=(const Smartphone& other){
	if (this != &other) {
		Smartphone temp(other);
		Telephone::operator=(other);
		Swap(temp);
	}
	return *this;
}

Smartphone::~Smartphone(){
	delete[] os;
	os = nullptr;
}

const char* Smartphone::getOs() const{
	return os;
}

unsigned Smartphone::getMemory() const{
	return memory;
}

void Smartphone::setOs(const char* newOs){
	dynCpy(os,newOs);
}

void Smartphone::setMemory(unsigned newMemory){
	if (newMemory < 0)
		throw std::invalid_argument("Invalid");
	memory = newMemory;
}

Telephone* Smartphone::clone() const{
	return new Smartphone(*this);
}

double Smartphone::getPrice() const{
	return memory;
}

void Smartphone::Swap(Smartphone& other){
	std::swap(os, other.os);
	std::swap(memory, other.memory);
}

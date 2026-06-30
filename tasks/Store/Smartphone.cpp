#include "Smartphone.h"

Smartphone::Smartphone(const char* model, const char* brand, double price, const char* os, unsigned int mem) :Telephone(model, brand, price), os(nullptr), mem(mem) {
	if (mem < 0)
		throw std::invalid_argument("Invalid");
	setOs(os);
}

Smartphone::Smartphone(const Smartphone& other):Telephone(other),mem(other.mem){
	setOs(other.os);
}

Smartphone& Smartphone::operator=(const Smartphone& other){
	if (this != &other) {
		Smartphone temp(other);
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

unsigned int Smartphone::getMem() const{
	return mem;
}

void Smartphone::setOs(const char* newOs){
	dynCpyS(os, newOs);
}

void Smartphone::setMem(unsigned int newMem){
	if (newMem < 0)
		throw std::invalid_argument("Invalid");
	mem = newMem;
}

double Smartphone::getPrice() const{
	return Telephone::getPrice()+mem;
}

Telephone* Smartphone::clone() const{
	return new Smartphone(*this);
}

void Smartphone::Swap(Smartphone& other){
	Telephone::Swap(other);
	std::swap(os, other.os);
	std::swap(mem, other.mem);
}














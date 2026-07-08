#include "Garage.h"

void Garage::free(){
	for (int i = 0;i < size;i++)
		delete vehicles[i];
	delete[] vehicles;
	vehicles = nullptr;
}

void Garage::copyFrom(const Garage& other){
	size = other.size;
	cap = other.cap;

	for (int i = 0;i < size;i++) {
		vehicles[i] = other.vehicles[i]->clone();
	}
}

Garage::Garage(size_t cap):vehicles(nullptr), size(size),cap(cap){
	if (size < 0 || cap < 0)
		throw std::invalid_argument("Invalid");
	vehicles = new Vehicle * [cap];
	for (int i = 0;i < size;i++)
		vehicles[i] = nullptr;
}

Garage::Garage(const Garage& other):vehicles(nullptr),size(other.size),cap(other.cap){
	copyFrom(other);
}

Garage& Garage::operator=(const Garage& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Garage::~Garage(){
	free();
}

size_t Garage::getSize() const{
	return size;
}

size_t Garage::getCap() const{
	return cap;
}

Vehicle* Garage::operator[](int ind){
	return vehicles[ind];
}

const Vehicle* Garage::operator[](int ind) const{
	return vehicles[ind];
}

bool Garage::addV(const Vehicle& v){
	if (size >= cap)
		return false;
	vehicles[size] = v.clone();
	size++;
}

bool Garage::removeBy(const char* brand, const char* model){
	for (int i = 0;i < size;) {
		if (strcmp(vehicles[i]->getBrand(), brand) == 0 && strcmp(vehicles[i]->getModel(), model) == 0) {

			delete vehicles[i];

			for (int j = i;j < size - 1;j++) {
				vehicles[j] = vehicles[j + 1];
			}
			size--;
		}
		else
			i++;
	}
}

int Garage::getCars() const{
	int cars = 0;
	for (int i = 0;i < size;i++) {
		if (vehicles[i] != nullptr)
			cars++;
	}
	return cars;
}

double Garage::getAllTax() const{
	double res = 0;
	for (int i = 0;i < size;i++) {
		res += vehicles[i]->getTax();
	}
	return res;
}

int Garage::getFreeSpaces(){
	return cap - size;
}

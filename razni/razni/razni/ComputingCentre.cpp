#include "ComputingCentre.h"

ComputingCentre::ComputingCentre(int size):devices(nullptr),size(0){
	if (size < 0)
		throw std::invalid_argument("Invalid");
	for (int i = 0;i < 16;i++)
		devices[i] = nullptr;
}

ComputingCentre::ComputingCentre(const ComputingCentre& other):devices(nullptr),size(other.size){
	copyFrom(other);
}

ComputingCentre& ComputingCentre::operator=(const ComputingCentre& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ComputingCentre::~ComputingCentre(){
	free();
}

int ComputingCentre::getCap() const{
	return size;
}

bool ComputingCentre::addDevice(const Device& device){
	if (size >= MAX_SIZE)
		return false;
	devices[size] = device.clone();
	size++;
	return true;
}

bool ComputingCentre::removeBy(const char* brand){
	bool removed = false;
	for (int i = 0;i < size;i++) {
		if (strcmp(devices[i]->getBrand(), brand) == 0) {
			delete devices[i];

			for (int j = i;j < size-1;j++) {
				devices[j] = devices[j + 1];
			}
			size--;
			devices[size] = nullptr;
			removed = true;
		}
		else {
			i++;
		}
	}
	return true;
}

void ComputingCentre::compute(const std::uint8_t* program, std::size_t size) const{
	if (program == nullptr && size > 0) {
		throw std::invalid_argument("Invalid program");
	}

	for (int i = 0; i < size; i++) {
		std::cout
			<< devices[i]->getBrand()
			<< " "
			<< devices[i]->getModel()
			<< ": "
			<< devices[i]->compute(program, size)
			<< std::endl;
	}
}

void ComputingCentre::free(){
	for (int i = 0;i < size;i++) {
		delete devices[i];
		devices[i] = nullptr;
	}
	size = 0;
}

void ComputingCentre::copyFrom(const ComputingCentre& other) {
	try {
		for (int i = 0;i < other.size;i++) {
			devices[i] = other.devices[i]->clone();
			size++;
		}
	}
	catch (...) {
		free();
		throw;
	}
}

void ComputingCentre::Swap(ComputingCentre& other){
	for (int i = 0;i < MAX_SIZE;i++) {
		std::swap(devices[i], other.devices[i]);
	}
	std::swap(size, other.size);
}

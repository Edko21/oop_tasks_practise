#include "IoT.h"

Iot::Iot(const char* brand, const char* model, double frequency, Type t, const char* sensors):Device(brand,model,frequency,t),sensors(nullptr){

	setSensors(sensors);
}

Iot::Iot(const Iot& other) :Device(other),sensors(nullptr){
	setSensors(other.sensors);
}

Iot& Iot::operator=(const Iot& other){
	if (this != &other) {
        Iot temp(other);
		Swap(temp);
	}
	return *this;
}

Iot::~Iot(){
	delete[] sensors;
	sensors = nullptr;
}

const char* Iot::getSensors() const{
	return sensors;
}

void Iot::setSensors(const char* newSensors){
	dynCpy(sensors, newSensors);
}

Device* Iot::clone() const{
	return new Iot(*this);
}

unsigned int Iot::compute(const std::uint8_t* program, size_t size) const{
    if (program == nullptr || size == 0) {
        return 0;
    }

    const char* found = std::strstr(sensors, "min-calc");

    if (found == nullptr) {
        return 0;
    }

    std::uint8_t min = program[0];

    for (size_t i = 1; i < size; i++) {
        if (program[i] < min) {
            min = program[i];
        }
    }

    return min;
}

void Iot::Swap(Iot& other){
	std::swap(sensors, other.sensors);
}


#include "Laptop.h"

Laptop::Laptop(const char* brand, const char* model, size_t frequency,Type t, size_t ram, size_t hdd):Device(brand,model,frequency,t),ram(ram),hdd(hdd){
	if (ram < 0 || hdd < 0)
		throw std::invalid_argument("Invalid");
	if (t!=Type::x86_x64 || t!=Type::ARM)
		throw std::invalid_argument("invalid");
}

size_t Laptop::getRam() const{
	return ram;
}

size_t Laptop::getHdd() const{
	return hdd;
}

void Laptop::setRam(size_t newRam){
	if (newRam < 0)
		throw std::invalid_argument("Invalid");
	ram = newRam;
}

void Laptop::setHdd(size_t newHdd){
	if (newHdd < 0)
		throw std::invalid_argument("Invalid");
	hdd = newHdd;
}

Device* Laptop::clone() const{
	return new Laptop(*this);
}

unsigned int Laptop::compute(const std::uint8_t* program, size_t size) const{
	if (program == nullptr, size > 0)
		throw std::invalid_argument("Invalid");
	if (ram <= size)
		throw std::invalid_argument("Invalid");
	unsigned int res = 0;
	for (int i = 0;i < size;i++) {
		res += program[i];
	}
	return res;
}

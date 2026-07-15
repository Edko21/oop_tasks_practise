#pragma once
#include "Device.h"

class Laptop :public Device {
public:
	Laptop(const char* brand, const char* model, size_t frequency,Type t, size_t ram, size_t hdd);
	
	size_t getRam() const;
	size_t getHdd() const;
	void setRam(size_t newRam);
	void setHdd(size_t newHdd);

	Device* clone() const override;
	unsigned int compute(const std::uint8_t* program, size_t size) const override;

private:
	size_t ram;
	size_t hdd;
};
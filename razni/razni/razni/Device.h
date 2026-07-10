#pragma once
#include <iostream>
#include"DeviceUtils.hpp"

enum class Type {
	x86_x64,
	ARM,
	RISC_V,
	MIPS,
	Other_RISC,
	Other_CISC
};

class Device {
public:
	Device(const char* brand, const char* model, double frequency, Type t);
	Device(const Device& other);
	Device& operator=(const Device& other);
	virtual ~Device();

	const char* getBrand() const;
	const char* getModel() const;
	double getFrequency() const;
	Type getType() const;
	void setBrand(const char* newBrand);
	void setModel(const char* newModel);
	void setFrequency(double newFrequency);

	virtual Device* clone() const = 0;
	virtual unsigned int compute(const std::uint8_t* program, size_t size) const = 0;

private:
	char* brand;
	char* model;
	double frequency;
	const Type t;
};
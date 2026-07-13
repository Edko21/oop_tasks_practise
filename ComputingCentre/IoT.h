#pragma once
#include "Device.h"

class Iot :public Device {
public:
	Iot(const char* brand, const char* model, double frequency, Type t, const char* sensors);
	Iot(const Iot& other);
	Iot& operator=(const Iot& other);
	~Iot() override;

	const char* getSensors() const;
	void setSensors(const char* newSensors);

	Device* clone() const override;
	unsigned int compute(const std::uint8_t* program, size_t size) const override;
private:
	char* sensors;
	void Swap(Iot& other);
};
#pragma once
#include "Device.h"

class ComputingCentre {
public:
	ComputingCentre(int size);
	ComputingCentre(const ComputingCentre& other);
	ComputingCentre& operator=(const ComputingCentre& other);
	~ComputingCentre();

	int getCap() const;
	bool addDevice(const Device& device);
	bool removeBy(const char* brand);
	void compute(const std::uint8_t* program,std::size_t size) const;
private:
	static constexpr int MAX_SIZE = 16;
	Device* devices[MAX_SIZE];
	int size;
	void free();
	void copyFrom(const ComputingCentre& other);
	void Swap(ComputingCentre& other);
};
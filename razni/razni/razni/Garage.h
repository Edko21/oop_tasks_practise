#pragma once
#include "Vehicle.h"


class Garage {
public:
	Garage(size_t cap);
	Garage(const Garage& other);
	Garage& operator=(const Garage& other);
	~Garage();

	size_t getSize() const;
	size_t getCap() const;
	
	Vehicle* operator[](int ind);
	const Vehicle* operator[](int ind) const;

	bool addV(const Vehicle& v);
	bool removeBy(const char* brand, const char* model);
	int getCars() const;
	double getAllTax() const;
	int getFreeSpaces();

private:
	Vehicle** vehicles;
	size_t size;
	size_t cap;

	void free();
	void copyFrom(const Garage& other);
};
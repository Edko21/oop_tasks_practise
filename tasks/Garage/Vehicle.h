#pragma once
#include <iostream>
#include "Utils.hpp"

class Vehicle {
public:
	Vehicle(const char* brand, const char* model, const char* regNum);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	virtual ~Vehicle();

	const char* getBrand() const;
	const char* getModel() const;
	const char* getReg() const;

	void setBrand(const char* newBrand);
	void setModel(const char* newModel);
	void setReg(const char* newReg);

	virtual Vehicle* clone() const = 0;
	virtual double getDanak() const = 0;

protected:
	void Swap(Vehicle& other);
private:
	char* brand;
	char* model;
	char* regNum;
};
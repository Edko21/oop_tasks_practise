#pragma once
#include <iostream>
#include <cctype>
#include "Garage_Utils.hpp"

class Vehicle {
public:
	Vehicle(const char* brand, const char* model, const char* regNum);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	virtual ~Vehicle();

	const char* getBrand() const;
	const char* getModel() const;
	const char* getRegNum() const;
	

	void setBrand(const char* newBrand);
	void setModel(const char* newModel);
	void setRegNum(const char* newRegNum);

	virtual double getTax() const = 0;
	virtual Vehicle* clone() const = 0;

protected:
	void Swap(Vehicle& other);
private:
	char* brand;
	char* model;
	char* regNum;
	bool isValidRegNum(const char* regNum);
};
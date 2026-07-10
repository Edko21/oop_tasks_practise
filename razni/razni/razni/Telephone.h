#pragma once
#include <iostream>
#include "TelephoneUtils.hpp"

class Telephone {
public:
	Telephone(const char* model, const char* marka, double price);
	Telephone(const Telephone& other);
	Telephone& operator=(const Telephone& other);
	virtual ~Telephone();
	virtual double getPrice() const = 0;

	const char* getModel() const;
	const char* getMarka() const;
	void setModel(const char* newModel);
	void setMarka(const char* newMarka);

	
private:
	char* model;
	char* marka;
	double price;
};
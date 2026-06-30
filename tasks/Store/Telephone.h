#pragma once
#include <iostream>
#include "UtilsSmartphone.hpp"


class Telephone {
public:
	Telephone(const char* model, const char* brand, double price);
	Telephone(const Telephone& other);
	Telephone& operator=(const Telephone& other);
	virtual ~Telephone();

	const char* getModel() const;
	const char* getBrand() const;
	virtual Telephone* clone() const;
	virtual double getPrice() const;

	void setModel(const char* newModel);
	void setBrand(const char* newBrand);
	void setPrice(double newPrice);

protected:
	void Swap(Telephone& other);
private:
	char* model;
	char* brand;
	double price;
};
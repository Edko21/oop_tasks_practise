#pragma once
#include "Policy.h"

class CargoCarPolicy :public Policy {
public:
	CargoCarPolicy(const char* description, double sum, const char* brand, const char* pathDescription, double value, double maxWeight);
	CargoCarPolicy(const CargoCarPolicy& other);
	CargoCarPolicy& operator=(const CargoCarPolicy& other);

	const char* getBrand() const;
	const char* getPathDescription() const;
	double getValue() const;
	double getMaxWeight() const;

	void setBrand(const char* newBrand);
	void setPathDescription(const char* newPahtDescription);
	void setValue(double newValue);
	void setMaxWeight(double newMaxWeight);

	CargoCarPolicy* clone() const override;
	double getPaid(double sum) const override;
	~CargoCarPolicy() override;
	void print() const override;

protected:
	void Swap(CargoCarPolicy& other);

private:
	char* brand;
	char* pathDescription;
	double value;
	double maxWeight;
};
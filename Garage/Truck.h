#pragma once
#include "Vehicle.h"

class Truck :public Vehicle {
public:
	Truck(const char* brand, const char* model, const char* regNum, double load, const char* description);
	Truck(const Truck& other);
	Truck& operator=(const Truck& other);
	~Truck() override;

	double getLoad() const;
	const char* getDescription() const;
	void setLoad(double newLoad);
	void setDescription(const char* newDescription);

	double getTax() const override;
	Vehicle* clone() const override;
private:
	double load;
	char* description;
	void Swap(Truck& other);
};
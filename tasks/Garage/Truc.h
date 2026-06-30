#pragma once
#include "Vehicle.h"

class Truc :public Vehicle {
public:
	Truc(const char* brand, const char* model, const char* regNum, double load, const char* description);
	Truc(const Truc& other);
	Truc& operator=(const Truc& other);
	~Truc() override;

	double getLoad() const;
	const char* getDescription() const;

	void setLoad(double newLoad);
	void setDescription(const char* newDescription);

	Truc* clone() const override;
	double getDanak() const override;

protected:
	void Swap(Truc& other);
private:
	double load;
	char* description;
};
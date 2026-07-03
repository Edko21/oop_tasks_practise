#pragma once
#include "Utility.hpp"
#include <iostream>

enum class TypeEnsurance{
	UNKNOWN=-1,
	CARGO,
	PROPERTY,
	ELECTRONIC,
	PropertyAndEquipment
};

class Policy {
public:
	Policy(const char* description, double sum, TypeEnsurance type);
	Policy(const Policy& other);
	Policy& operator=(const Policy& other);


	const char* getDescription() const;
	double getSum() const;
	TypeEnsurance getType() const;

	void setDescription(const char* newDescription);
	void setSum(double newSum);
	void setType(TypeEnsurance newType);

	virtual ~Policy() = 0;
	virtual Policy* clone() const = 0;
	virtual void print() const = 0;
	virtual double getPaid(double sum) const = 0;

protected:
	void Swap(Policy& other);

private:
	char* description;
	double sum;
	TypeEnsurance type;
};

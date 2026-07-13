#pragma once
#include "Policy.h"

class PropertyFirePolicy :virtual public Policy {
public:
	PropertyFirePolicy(const char* description, double sum, double propertyVal, double area, int yearBuilt, bool hasFireSystem);
	
	double getPropertyVal() const;
	double getArea() const;
	int getYear() const;
	bool getFireSystem() const;

	void setPropertyVal(double newVal);
	void setArea(double newArea);
	void setYear(int newYear);
	void setFireSystem(bool newFireSystem);

	PropertyFirePolicy* clone() const override;
	double getPaid(double sum) const override;
	void print() const override;
	
private:
	double propertyVal;
	double area;
	int yearBuilt;
	bool hasFireSystem;
};
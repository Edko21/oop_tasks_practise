#pragma once
#include "Policy.h"

class ElectronicEquipmentPolicy :virtual public Policy {
public:
	ElectronicEquipmentPolicy(const char* description, double sum, const char* type, int yearBuildE, double valueE);
	ElectronicEquipmentPolicy(const ElectronicEquipmentPolicy& other);
	ElectronicEquipmentPolicy& operator=(const ElectronicEquipmentPolicy& other);
	~ElectronicEquipmentPolicy() override;

	const char* getType() const;
	int getYearBuildE() const;
	double getValueE() const;

	void setType(const char* newType);
	void setYearBuildE(int newYear);
	void setVelueE(double newVal);

	ElectronicEquipmentPolicy* clone() const override;
	void print() const override;
	double getPaid(double sum) const override;

protected:
	void Swap(ElectronicEquipmentPolicy& other);
private:
	char* type;
	int yearBuildE;
	double valueE;
};
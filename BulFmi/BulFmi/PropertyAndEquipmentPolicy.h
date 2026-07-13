#pragma once
#include "PropertyFirePolicy.h"
#include "ElectronicEquipmentPolicy.h"

class PropertyAndEquipmentPolicy :public PropertyFirePolicy,public ElectronicEquipmentPolicy {
public:
	PropertyAndEquipmentPolicy(const char* description,
		double sum,
		double propertyVal,
		double area,
		int yearBuilt,
		bool hasFireSystem,
		const char* equipmentType,
		int yearBuildE,
		double valueE,
		int combinedRisk,
		double totalAssetsValue);

	int getCombinedRisk() const;
	double getSumA() const;
	void setCombinedRisk(int newCombinedRisk);
	void setSumA(double newSumA);

	PropertyAndEquipmentPolicy* clone() const override;
	double getPaid(double sum) const override;
	void print() const override;

private:
	int combinedRisk;
	double sumA;
};
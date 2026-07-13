#include "PropertyAndEquipmentPolicy.h"

PropertyAndEquipmentPolicy::PropertyAndEquipmentPolicy(const char* description,
	double sum,
	double propertyVal,
	double area,
	int yearBuilt,
	bool hasFireSystem,
	const char* equipmentType,
	int yearBuildE,
	double valueE,
	int combinedRisk,
	double totalAssetsValue):Policy(description,sum,TypeEnsurance::PropertyAndEquipment),PropertyFirePolicy(propertyVal,area,yearBuilt,hasFireSystem),ElectronicEquipmentPolicy(equipmentType,yearBuildE,valueE), {

}

int PropertyAndEquipmentPolicy::getCombinedRisk() const {
	return combinedRisk;
}

double PropertyAndEquipmentPolicy::getSumA() const {
	return sumA;
} 

void PropertyAndEquipmentPolicy::setCombinedRisk(int newCombinedRisk) {
	if (newCombinedRisk < 0)
		throw std::invalid_argument("invalid");
	combinedRisk = newCombinedRisk;
}

void PropertyAndEquipmentPolicy::setSumA(double newSumA) {
	if (sumA < 0)
		throw std::invalid_argument("invalid");
	sumA = newSumA;
}

PropertyAndEquipmentPolicy* PropertyAndEquipmentPolicy::clone() const {
	return new PropertyAndEquipmentPolicy(*this);
}

double PropertyAndEquipmentPolicy::getPaid(double sum) const{

}

void PropertyAndEquipmentPolicy::print() const {

}

#pragma once
#include "Appliance.h"

class HiFi:public Appliance	 {
public:
	HiFi(const char* marka, const char* model, const int id, bool isPlugged, bool turnedOn, int maxPower,int percent);
	int getMaxPower() const;
	int getPercentege() const;
	Appliance* clone() const override;
	int consumedEnergy() const override;

private:
	int maxPower;
	int percent;
};
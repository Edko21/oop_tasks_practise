#include "HiFi.h"

HiFi::HiFi(const char* marka, const char* model, const int id, bool isPlugged, bool turnedOn, int maxPower, int percent)
	:Appliance(marka,model,id,isPlugged,turnedOn),maxPower(maxPower),percent(percent){
	if (maxPower < 0)
		throw std::invalid_argument("Invalid");
	if(percent<0||percent>100)
		throw std::invalid_argument("Invalid");
}

int HiFi::getMaxPower() const{
	return maxPower;
}

int HiFi::getPercentege() const{
	return percent;
}

Appliance* HiFi::clone() const{
	return new HiFi(*this);
}

int HiFi::consumedEnergy() const{
	if (off)
		return 1;
	if (on)
		return percent + 10;
}
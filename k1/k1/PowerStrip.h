#pragma once
#include "EMachine.h"

class PowerStrip {
public:
	PowerStrip(int socketsCount,double maxCurrent);
	PowerStrip(const PowerStrip& other);
	PowerStrip& operator=(const PowerStrip& other);
	~PowerStrip();

	int getSockets() const;
	int getUsed() const;
	double getMax() const;
	double getCurrent() const;
	bool isBurned() const;

	void setMax(double newMax);
	bool plugDevice(const EMachine& other);
	bool unplugDevice(int slotInd);
	bool turnOn(int slotInd);
	bool turnOff(int slotInd);

	void print() const;;
private:
	const int socketsCount;
	double maxCurrent;

	EMachine** machines;
	int usedCount;
	bool burned;

	int findFreeSlot() const;
	bool isValid(int slotInd) const;
	void burn();
	void checkLoadAndBurn();


	void free();
	void copyFrom(const PowerStrip& other);
};

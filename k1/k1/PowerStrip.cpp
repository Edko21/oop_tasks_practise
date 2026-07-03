#include "PowerStrip.h"

PowerStrip::PowerStrip(int socketsCount, double maxCurrent):socketsCount(socketsCount),maxCurrent(maxCurrent),machines(nullptr),usedCount(usedCount),burned(false){
	if (socketsCount < 0)
		throw std::invalid_argument("Invalid");
	if (maxCurrent < 0)
		throw std::invalid_argument("Invalid");
	machines = new EMachine * [socketsCount];
	for (int i = 0;i < socketsCount;i++) {
		machines[i] = nullptr;
	}
}

PowerStrip::PowerStrip(const PowerStrip& other):socketsCount(other.socketsCount),maxCurrent(other.maxCurrent),machines(nullptr),usedCount(other.usedCount),burned(other.burned){
	machines = new EMachine * [socketsCount];
	for (int i = 0;i < socketsCount;i++) {
		machines[i] = nullptr;
	}
}

PowerStrip& PowerStrip::operator=(const PowerStrip& other){
	if (this != &other) {
		if (other.socketsCount > socketsCount)
			throw std::logic_error("Invalid");
	}
	PowerStrip temp(socketsCount, other.maxCurrent);
	temp.burned = other.burned;
}


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
		PowerStrip temp(socketsCount, other.maxCurrent);
		temp.burned = other.burned;

		if (!other.burned) {
			temp.copyFrom(other);
		}
		Swap(temp);
	}
	return *this;
}

PowerStrip::~PowerStrip(){
	free();
	delete[] machines;
}

int PowerStrip::getSockets() const{
	return socketsCount;
}

int PowerStrip::getUsed() const{
	return usedCount;
}

double PowerStrip::getMax() const{
	return maxCurrent;
}

double PowerStrip::getCurrent() const
{
	double sum = 0;
	for (int i = 0;i < socketsCount;i++) {
		if (machines[i] != nullptr && machines[i]->isActiveM()) {
			sum += machines[i]->getPower();
		}
	}
	return sum;
}

bool PowerStrip::isBurned() const{
	return burned;
}

void PowerStrip::setMax(double newMax){
	if (newMax <= 0)
		throw std::invalid_argument("Invalid");
	maxCurrent = newMax;
	checkLoadAndBurn();
}

bool PowerStrip::plugDevice(const EMachine& other){
	if (burned) {
		return false;
	}

	int freeSlot = findFreeSlot();
	if (freeSlot == -1)
		return false;
	EMachine* newM = new EMachine(machine);
	try {
		newM->plugIn("Power strip");
	}
	catch (...) {
		delete newM;
		throw;
	}

	machines[freeSlot] = newM;
	usedCount++;

	checkLoadAndBurn();

	return !burned;
}

bool PowerStrip::unplugDevice(int slotInd){
	if (!isValid(slotInd))
		return false;
	if (machines[slotInd] == nullptr)
		return false;
	machines[slotInd]->unplug();
	delete machines[slotInd];
	machines[slotInd] = nullptr;

	usedCount--;
	return true;
}

bool PowerStrip::turnOn(int slotInd){
	if (burned)
		return false;
	if (!isValid(slotInd))
		return false;
	if (machines[slotInd] == nullptr)
		return false;

	machines[slotInd]->turnOn();
	checkLoadAndBurn();

	return !burned;
}

bool PowerStrip::turnOff(int slotInd){
	if (!isValid(slotInd))
		return false;
	if (machines[slotInd] == nullptr)
		return false;
	machines[slotInd]->turnOff();
	return true;
}

int PowerStrip::findFreeSlot() const{
	for (int i = 0;i < socketsCount;i++) {
		if (machines[i] == nullptr)
			return i;
	}
	return -1;
}

bool PowerStrip::isValid(int slotInd) const{
	return slotInd < socketsCount;
}

void PowerStrip::burn(){
	free();
	burned = true;
}

void PowerStrip::checkLoadAndBurn(){
	if (!burned && getCurrent() > maxCurrent)
		burn();
}

void PowerStrip::free(){
	for (unsigned i = 0; i < socketsCount; i++) {
		if (machines[i] != nullptr) {
			machines[i]->unplug();

			delete machines[i];
			machines[i] = nullptr;
		}
	}

	usedCount = 0;
}

void PowerStrip::copyFrom(const PowerStrip& other){
	if (other.socketsCount > socketsCount) {
		throw std::logic_error("Not enough sockets.");
	}

	try {
		for (unsigned i = 0; i < other.socketsCount; i++) {
			if (other.machines[i] != nullptr) {
				machines[i] = new EMachine(*other.machines[i]);

				machines[i]->plugIn("Power strip");

				if (other.machines[i]->isActiveM()) {
					machines[i]->turnOn();
				}

				usedCount++;
			}
		}
	}
	catch (...) {
		free();
		throw;
	}

	checkLoadAndBurn();
}

void PowerStrip::Swap(PowerStrip& other){
	std::swap(maxCurrent, other.maxCurrent);
	std::swap(machines, other.machines);
	std::swap(usedCount, other.usedCount);
	std::swap(burned, other.burned);
}

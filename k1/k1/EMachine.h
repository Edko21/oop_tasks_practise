#pragma once
#include "Utils.hpp"
#include <fstream>
#include <iostream>
class EMachine {
public:
	EMachine(const char* description, const char* brand, int power);
	EMachine(const EMachine& other);
	EMachine& operator=(const EMachine& other);
	~EMachine();

	const char* getDescripiton() const;
	const char* getBrand() const;
	int getPower() const;
	bool isPluggedM() const;
	bool isActiveM() const;
	const char* getPluggedPlace() const;
	void turnOn();
	void turnOff();

	void setDescription(const char* newDescription);
	void setBrand(const char* newBrand);
	void setPower(int newPower);
	void setPlugged(const char* place);
	void setActive(bool isA);

	void print(std::ostream& os) const;
	void unplug();

	bool saveToFile(const char* filePath, const EMachine& machine);
	bool loadFromFile(const char* filePath, EMachine& machine);
protected:
	void Swap(EMachine& other);
private:
	static int nextId;
	const int id;
	char* description;
	char* brand;
	int power;
	bool isPlugged;
	bool isActive;

	char* pluggedPlace;
};
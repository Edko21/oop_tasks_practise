#pragma once
#include "Utils.hpp"
#include <fstream>
#include <iostream>
class EMachine {
public:
	EMachine(const char* description, const char* brand, int power, bool isPlugged, bool isActive,static int id);
	EMachine(const EMachine& other);
	EMachine& operator=(const EMachine& other);
	~EMachine();

	const char* getDescripiton() const;
	const char* getBrand() const;
	int getPower() const;
	bool isPluggedM() const;
	bool isActiveM() const;

	void setDescription(const char* newDescription);
	void setBrand(const char* newBrand);
	void setPower(int newPower);
	void setPlugged(bool isP);
	void setActive(bool isA);

	bool saveToFile(const char* filePath, const EMachine& machine);
	bool loadFromFile(const char* filePath, EMachine& machine);
protected:
	void Swap(EMachine& other);
private:
	char* description;
	char* brand;
	int power;
	bool isPlugged;
	bool isActive;
	static int id;
	int cnt;
};
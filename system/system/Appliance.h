#pragma once
#include <fstream>
#include "Utils.hpp"

class Appliance {
public:
	Appliance(const char* marka, const char* model,const int id,bool isPlugged,bool turnedOn);
	Appliance(const Appliance& other);
	Appliance& operator=(const Appliance& other);
	virtual ~Appliance();
	virtual Appliance* clone() const = 0;
	virtual int consumedEnergy() const = 0;
	
	virtual bool on();
	virtual bool off();

	const char* getMarka() const;
	const char* getModel() const;
	bool getPlugged() const;
	virtual bool isOn() const;
	void setMarka(const char* newMarka);
	void setModel(const char* newModel);
protected:
	void Swap(Appliance& other);
private:
	char* marka;
	char* model;
	const int id;
	int cnt;
	bool isPlugged;
	bool turnedOn;
};
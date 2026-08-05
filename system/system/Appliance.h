#pragma once
#include <fstream>
#include "Utils.hpp"

class Appliance {
public:
	Appliance(const char* marka, const char* model,const int id,bool isPlugged);
	Appliance(const Appliance& other);
	Appliance& operator=(const Appliance& other);
	virtual ~Appliance();
	virtual Appliance* clone() const = 0;
	virtual int consumedEnergy() const = 0;
	
	bool on();
	bool off();

	const char* getMarka() const;
	const char* getModel() const;
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
};
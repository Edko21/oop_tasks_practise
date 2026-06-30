#pragma once
#include "Vehicle.h"

class Car :public Vehicle {
public:
	Car(const char* brand, const char* model, const char* regNum,const char* typeEngine,int hp);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car() override;

	const char* getType() const;
	int getHp() const;

	void setType(const char* newType);
	void setHp(int newHp);

	Car* clone() const override;
	double getDanak() const override;

protected:
	void Swap(Car& other);
private:
	char* typeEngine;
	int hp;
};
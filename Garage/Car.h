#pragma once
#include "Vehicle.h"

class Car :public Vehicle {
public:
	Car(const char* brand, const char* model, const char* regNum, const char* engine, int hp);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car() override;

	const char* getEngine() const;
	int getHp() const;
	void setEngine(const char* newEngine);
	void setHp(int newHp);

	double getTax() const override;
	Vehicle* clone() const override;

private:
	char* engine;
	int hp;
	void Swap(Car& other);
};
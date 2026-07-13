#pragma once
#include "Telephone.h"


class Smartphone :public Telephone {
public:
	Smartphone(const char* model, const char* marka, double price, const char* os, unsigned memory);
	Smartphone(const Smartphone& other);
	Smartphone& operator=(const Smartphone& other);
	~Smartphone() override;

	const char* getOs() const;
	unsigned getMemory() const;
	void setOs(const char* newOs);
	void setMemory(unsigned newMemory);

	Telephone* clone() const override;
	double getPrice() const override;

private:
	char* os;
	unsigned memory;
	void Swap(Smartphone& other);
};
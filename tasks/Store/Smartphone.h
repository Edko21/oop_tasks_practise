#pragma once
#include "Telephone.h"

class Smartphone :public Telephone {
public:
	Smartphone(const char* model, const char* brand, double price, const char* os, unsigned int mem);
	Smartphone(const Smartphone& other);
	Smartphone& operator=(const Smartphone& other);
	~Smartphone() override;

	const char* getOs() const;
	unsigned int getMem() const;

	void setOs(const char* newOs);
	void setMem(unsigned int newMem);
	double getPrice() const override;

	Telephone* clone() const override;

protected:
	void Swap(Smartphone& other);
private:
	char* os;
	unsigned int mem;
};
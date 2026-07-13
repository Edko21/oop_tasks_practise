#pragma once
#include "Telephone.h"

class Store {
public:
	Store(double avaliableBudget);
	~Store();

	bool addPhone(const Telephone& phone);
	bool removeBy(const char* marka, const char* model);
	double getAvaliable() const;
	double getInitial() const;
	size_t getSize() const;

private:
	Telephone** telephones;
	size_t size;
	size_t cap;
	double avaliableBudget;
	double initialBudget;

	void free();
};
#pragma once
#include "Telephone.h"

class Store {
public:
	Store(double budget);
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	const double getInitialBudget() const;
	const double getAvalableBudget() const;

	bool addPhone(const Telephone& p);
	void removeBy(const char* model, const char* brand);

private:
	Telephone** phones;
	size_t cap;
	size_t size;

	double initialBudget;
	double availableBudget;

	void free();
	void copyFrom(const Store& other);
	void resize(int newCap);
};
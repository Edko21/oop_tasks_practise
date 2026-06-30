#pragma once
#include "Plant.h"

class Garden {
public:
	Garden();
	Garden(const Garden& other);
	Garden& operator=(const Garden & other);
	~Garden();

	void plant(const Plant& plant);
	void eradicate();
private:
	Plant** plants;
	size_t size;
	size_t cap;

	void free();
	void copyFrom(const Garden& other);
	void resize(size_t newCap);
};
#pragma once
#include "Plant.h"

class Garden {
public:
	Garden(int cap);
	Garden(const Garden& other);
	Garden& operator=(const Garden& other);
	~Garden();

	int getSize() const;
	int getCap() const;
	
	bool addPlant(const Plant& plant);
	bool eradicate(const char* vid);

private:
	Plant** plants;
	int size;
	int cap;

	void free();
	void copyFrom(const Garden& other);
	void Swap(Garden& other);
};
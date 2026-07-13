#pragma once
#include "Meal.h"
static const int MAX_SIZE = 100;

class Menu {
public:
	Menu(int maxKal);
	Menu(const Menu& other) = delete;
	Menu& operator=(const Menu& other) = delete;
	~Menu();

	int getMaxKal() const;
	int getSize() const;
	int getCurrKal() const;

	Menu& operator+=(const Meal& meal);
	Menu& operator-=(const Meal& meal);
	
	Meal* operator[](int ind);
	const Meal* operator[](int ind) const;
	int operator()(char* ingredient) const;
private:
	Meal* m[MAX_SIZE];
	int size;
	const int maxKal;

	void free();
};


Menu& operator+(const Meal& lhs, const Meal& rhs);
Menu& operator-(const Meal& lhs, const Meal& rhs);
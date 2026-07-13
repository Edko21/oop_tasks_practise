#pragma once
#include <iostream>
#include "Utils.hpp"

class Meal {
public:
	Meal(const char* name, const char* recipe, int kal);
	Meal(const Meal& other);
	Meal& operator=(const Meal& other);
	~Meal();

	const char* getName() const;
	const char* getRecipe() const;
	int getKal() const;

	void setName(const char* newName);
	void setRecipe(const char* newRecipe);
	void setKal(int newKal);

	friend bool operator==(const Meal& lhs, const Meal& rhs);
	friend bool operator!=(const Meal& lhs, const Meal& rhs);
private:
	char* name;
	char* recipe;
	int kal;

	void Swap(Meal& other);
};

bool operator>(const Meal& lhs, const Meal& rhs);
bool operator<(const Meal& lhs, const Meal& rhs);
bool operator<=(const Meal& lhs, const Meal& rhs);
bool operator>=(const Meal& lhs, const Meal& rhs);
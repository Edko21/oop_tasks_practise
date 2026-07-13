#include "Meal.h"

Meal::Meal(const char* name, const char* recipe, int kal) :name(nullptr), recipe(nullptr), kal(kal) {
	if (kal < 0)
		throw std::invalid_argument("Invalid");
	try {
		setName(name);
		setRecipe(recipe);
	}
	catch (...) {
		delete[] this->name;
		delete[] this->recipe;
		throw;
	}
}

Meal::Meal(const Meal& other):kal(other.kal){
	try {
		setName(other.name);
		setRecipe(other.recipe);
	}
	catch (...) {
		delete[] this->name;
		delete[] this->name;
		throw;
	}
}

Meal& Meal::operator=(const Meal& other){
	if (this != &other) {
		Meal temp(other);
		Swap(temp);
	}
	return *this;
}

Meal::~Meal(){
	delete[] name;
	delete[] recipe;
}

const char* Meal::getName() const{
	return name;
}

const char* Meal::getRecipe() const{
	return recipe;
}

int Meal::getKal() const{
	return kal;
}

void Meal::setName(const char* newName){
	dynCpy(name, newName);
}

void Meal::setRecipe(const char* newRecipe){
	dynCpy(recipe, newRecipe);
}

void Meal::setKal(int newKal){
	if(newKal<0)
		throw std::invalid_argument("Invalid");
	kal = newKal;
}

void Meal::Swap(Meal& other){
	std::swap(name, other.name);
	std::swap(recipe, other.recipe);
	std::swap(kal, other.kal);
}

bool operator==(const Meal& lhs, const Meal& rhs){
	return strcmp(lhs.getName(), rhs.getName()) == 0 &&
		strcmp(lhs.getRecipe(), rhs.getRecipe()) == 0 &&
		lhs.getKal() == rhs.getKal();
}

bool operator!=(const Meal& lhs, const Meal& rhs){
	return !(lhs == rhs);
}

bool operator>(const Meal& lhs, const Meal& rhs){
	return rhs < lhs;
}

bool operator<(const Meal& lhs, const Meal& rhs)
{
	if (lhs.getKal() < rhs.getKal())
		return true;

	if (lhs.getKal() > rhs.getKal()) {
		return false;
	}

	return strcmp(lhs.getName(), rhs.getName()) < 0;
}

bool operator<=(const Meal& lhs, const Meal& rhs){
	return !(rhs < lhs);
}

bool operator>=(const Meal& lhs, const Meal& rhs){
	return !(lhs < rhs);
}

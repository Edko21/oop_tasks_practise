#include "Menu.h"

void Menu::free(){
	for (int i = 0;i < MAX_SIZE;i++) {
		delete m[i];
		m[i] = nullptr;
	}
	size = 0;
}

Menu::Menu(int maxKal):size(0),maxKal(maxKal){
	if (maxKal < 0)
		throw std::invalid_argument("Invalid");
	for (int i = 0;i < MAX_SIZE;i++) {
		m[i] = nullptr;
	}
}

Menu::~Menu(){
	free();
}

int Menu::getMaxKal() const{
	return maxKal;
}

int Menu::getSize() const{
	return size;
}

int Menu::getCurrKal() const{
	int sum = 0;
	for (int i = 0;i < size;i++) {
		sum += m[i]->getKal();
	}
	return sum;
}

Menu& Menu::operator+=(const Meal& meal){
	if (size >= MAX_SIZE)
		return *this;
	if (getCurrKal() + meal.getKal() > maxKal)
		return *this;

	m[size] = new Meal(meal);
	size++;

	return *this;
}

Menu& Menu::operator-=(const Meal& meal){
	for (int i = 0;i < size;i++) {
		if (*m[i] == meal)
			delete m[i];
		for (int j = i;j < size - 1;j++)
			m[j] = m[j + 1];
		m[size - 1] = nullptr;
		size--;
		i--;
	}
	return *this;
}

Meal* Menu::operator[](int ind){
	return m[ind];
}

const Meal* Menu::operator[](int ind) const{
	return m[ind];
}

int Menu::operator()(char* ingredient) const{
	if (ingredient == nullptr) {
		return -1;
	}

	int bestIndex = -1;

	for (int i = 0; i < size; i++) {
		if (std::strstr(m[i]->getRecipe(), ingredient) != nullptr) {
			if (bestIndex == -1 ||
				m[i]->getKal() < m[bestIndex]->getKal()) {
				bestIndex = i;
			}
		}
	}

	return bestIndex;
}

Menu& operator+=(const Meal& lhs, const Meal& rhs){
	Meal temp(lhs);
	temp += rhs;
}

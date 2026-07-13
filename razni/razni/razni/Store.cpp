#include "Store.h"

Store::Store(double initialeBudget):telephones(nullptr),size(0),cap(0),avaliableBudget(avaliableBudget),initialBudget(initialBudget){
	for (int i = 0;i < size;i++)
		telephones[i] = nullptr;
}

Store::~Store(){
	free();
}

bool Store::addPhone(const Telephone& phone) {
	double price = phone.getPrice();
	if (price>=avaliableBudget)
		return false;
	telephones[size] = phone.clone();
	size++;
	avaliableBudget -= price;

	return true;
}

bool Store::removeBy(const char* marka, const char* model){
	for (int i = 0;i < size;i++) {
		if (strcmp(telephones[i]->getMarka(), marka) == 0 &&
			strcmp(telephones[i]->getModel(), model) == 0) {
			delete telephones[i];

			double price = telephones[i]->getPrice();

			for (int j = i;j < size - 1;j++) {
				telephones[j] = telephones[j + 1];
			}
			size--;
			telephones[i] = nullptr;
			avaliableBudget += price;
			return true;
		}
	}
	return false;
}

double Store::getAvaliable() const{
	return avaliableBudget;
}

double Store::getInitial() const{
	return initialBudget;
}

size_t Store::getSize() const{
	return size;
}

void Store::free(){
	for (int i = 0;i < size;i++) {
		delete telephones[i];
	}
	delete[] telephones;

	telephones = nullptr;
	size = 0;
	cap = 0;
}

#include "BulFmi.h"

BulFmi::BulFmi(double budget) :size(0),budget(budget) {
	if (budget < 0)
		throw std::invalid_argument("Cant be -");
	for (int i = 0;i < MAX_SIZE;i++)
		p[i] = nullptr;
}

BulFmi::BulFmi(const BulFmi& other):size(0),budget(other.budget) {
	for (int i = 0;i < MAX_SIZE;i++) {
		p[i] =nullptr;
	}
	copyFrom(other);
}

BulFmi& BulFmi::operator=(const BulFmi& other) {
	if (this != &other) {
		clear();
		budget = other.budget;
		copyFrom(other);
	}
	return *this;
}

BulFmi::~BulFmi() {
	clear();
}

bool BulFmi::addPolicy(Policy* policy) {
	if (!canAdd(policy))
		return false;
	double neededMoney = policy->getPaid(policy->getSum());
	p[size] = policy->clone();
	size++;

	budget -= neededMoney;

	return true;

}

bool BulFmi::removePolicy(int ind) {
	if (ind < 0 || ind >= size)
		throw std::out_of_range("invalid");

	double restoredMoney = p[ind]->getPaid(p[ind]->getSum());
	budget += restoredMoney;

	delete p[ind];

	for (int i = 0;i < size - 1;i++)
		p[i] = p[i + 1];

	size--;
	p[size] = nullptr;
	return true;
}

Policy* BulFmi::getPolicy(int ind) {
	if (ind < 0 || ind >= size)
		throw std::invalid_argument("invalid");
	return p[ind];
}
const Policy* BulFmi::getPolicy(int ind) const {
	if (ind < 0 || ind >= size)
		throw std::invalid_argument("invalid");
	return p[ind];
}

double BulFmi::getInsuranceAmount(int ind) const {
	if (ind < 0 || ind >= size)
		throw std::out_of_range("invalid");

	return p[ind]->getPaid(p[ind]->getSum());
}

void BulFmi::printAll() const {

}

int BulFmi::getSize() const {

}
double BulFmi::getBudget() const {
	return budget;
}

bool BulFmi::canAdd(const Policy* p) {
	if (p == nullptr)
		return false;
	if (size >= MAX_SIZE)
		return false;
	double neededMoney = p->getPaid(p->getSum());
	return neededMoney <= budget;
}

void BulFmi::clear() {
	for (int i = 0;i < size;i++) {
		delete p[i];
		p[i] = nullptr;
	}
	size = 0;
}

void BulFmi::copyFrom(const BulFmi& other) {
	for (int i = 0;i < other.size;i++) {
		p[i] = other.p[i]->clone();
	}
	size = other.size;
}
#include "Mage.h"

Mage::Mage(int health, const char* name,Position p,int damage, const char* magicSkill, int coef):Player(health,name,p,Weapon::Staff,damage),magicSkill(nullptr),coef(coef){
	if (coef <= 0 || coef >= 1)
		throw std::invalid_argument("Invalid");
	setSkill(magicSkill);
}

Mage::Mage(const Mage& other):Player(other),magicSkill(nullptr),coef(other.coef){
	setSkill(other.magicSkill);
}

Mage& Mage::operator=(const Mage& other){
	if (this != &other) {
		Mage temp(other);
		Swap(temp);
	}
	return *this;
}

Mage::~Mage(){
	delete[] magicSkill;
	magicSkill = nullptr;
}

const char* Mage::getSkill() const{
	return magicSkill;
}

int Mage::getCoef() const{
	return coef;
}

void Mage::setSkill(const char* newSkill){
	dynCpy(magicSkill, newSkill);
}

void Mage::print() const{
	Player::print();
	std::cout << "MagicSkill" << getSkill() << "Coef" << getCoef() << std::endl;
}

Player* Mage::clone() const{
	return new Mage(*this);
}

void Mage::attack(Player& target){
	int	targetHealth = target.getHealth();
	int reduceHealth = static_cast<int>(target.getHealth() * (1.0 - coef));
	target.setHealth(reduceHealth);
	target.handleAttack(power());
}

void Mage::Swap(Mage& other){
	Player::Swap(other);
	std::swap(magicSkill, other.magicSkill);
	std::swap(coef, other.coef);
}



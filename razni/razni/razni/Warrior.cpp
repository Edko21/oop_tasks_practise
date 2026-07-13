#include "Warrior.h"

Warrior::Warrior(int health, const char* name, Position position, Weapon weapon, int damage, int armor):Player(health,name,position,weapon,damage),armor(armor){
	if (armor < 0)
		throw std::invalid_argument("Invalid");

}

int Warrior::getArmor() const{
	return armor;
}

void Warrior::setArmor(int newArmor) {
    if (newArmor < 0) {
        throw std::invalid_argument("Invalid armor");
    }

    armor = newArmor;
}

void Warrior::print() const{
    std::cout << "Armor" << getArmor() << std::endl;
}

Player* Warrior::clone() const{
    return new Warrior(*this);
}

void Warrior::handleAttack(int damage){
    if (damage <= 0)
        return;
    if (armor >= damage)
        armor -= damage;
    else {
        int remainingDamage = damage - armor;
        armor = 0;

        if (remainingDamage >= getHealth())
            setHealth(0);
        else {
            setHealth(getHealth() - remainingDamage);
        }
    }
}

 
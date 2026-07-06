#include "Warrior.h"

Warrior::Warrior(int health, const char* name, Position position, Weapon weapon, int damage, int armor):Player(health,name,position,weapon,damage),armor(armor){
	if (armor < 0)
		throw std::invalid_argument("Invalid");

}

int Warrior::getArmor() const{
	return armor;
} 

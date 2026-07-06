#pragma once
#include "Player.h"

class Warrior:public Player {
public:
	Warrior(int health, const char* name, Position position, Weapon weapon, int damage, int armor);
	int getArmor() const;
	void setArmor(int newArmor);
	void handleAttack(int damage, int healt,int armor) override;

private:
	int armor;

};
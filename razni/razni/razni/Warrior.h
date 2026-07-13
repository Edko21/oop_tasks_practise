#pragma once
#include "Player.h"

class Warrior:public Player {
public:
	Warrior(int health, const char* name, Position position, Weapon weapon, int damage, int armor);
	int getArmor() const;
	void handleAttack(int power) override;
	void setArmor(int newArmor);

	void print() const override;
	Player* clone() const override;
private:
	int armor;
};
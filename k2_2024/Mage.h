#pragma once
#include "Player.h"

class Mage :public Player {
public:
	Mage(int health, const char* name,Position p, int damage,const char* magicSkill, int coef);
	Mage(const Mage& other);
	Mage& operator=(const Mage& other);
	~Mage() override;

	const char* getSkill() const;
	int getCoef() const;

	void setSkill(const char* newSkill);
	void print() const override;
	Player* clone() const override;
	void handleAttack(int power) override;

	void attack(Player& target) const override;
private:
	char* magicSkill;
	int coef;

	void Swap(Mage& other);
};
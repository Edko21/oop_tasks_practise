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
	void attack(Player& target) override;
private:
	char* magicSkill;
	double coef;

	void Swap(Mage& other);
};
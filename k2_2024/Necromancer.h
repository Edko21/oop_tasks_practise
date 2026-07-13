#pragma once
#include "Mage.h"

static const int MAX_DEFEATED = 100;

class Necromancer :public Mage {
public:
	Necromancer(int health, const char* name, Position p, int damage, const char* magicSkill, int coef);
	Necromancer(const Necromancer& other);
	Necromancer& operator=(const Necromancer& other);
	~Necromancer() override;

	void attack(Player& target) const override;
	int getCount() const;	
	void print() const override;
	Player* clone() const override;

private:
	Player* defeated[MAX_DEFEATED];
	int defeatedCount;
	void free();
	void copyFrom(const Necromancer& other);
	void addDefeated(const Player& player);
};
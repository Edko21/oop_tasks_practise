#include "Position.hpp"
#include "Weapon.h"
#include "Utils.hpp"
#include <iostream>

class Player {
public:
	Player(int health, const char* name, Position position, Weapon weapon, int damage);
	virtual ~Player();

	virtual void print() const = 0;
	virtual Player* clone() const = 0;

	virtual int power() const;
	virtual void handleAttack(int power);

	int getHealth() const;
	const char* getName() const;
	Weapon getWeapon() const;
	bool isDead();
	void attack(Player& target) const;

	void setHealth(int newH);
	void setWeapon(Weapon newW);
	void setDamage(int newD);	
protected:
	void reduceHealth(int amount);
private:
	int health;
	const char* name;
	Position position;
	Weapon weapon;
	int damage;
};
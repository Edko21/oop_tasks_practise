#include "Position.hpp"
#include "Weapon.h"
#include"Utils.hpp"
#include <iostream>

class Player {
public:
	Player(int health, const char* name, Position position, Weapon weapon, int damage);
	Player(const Player& other);
	Player(Player&& other);
	Player& operator=(const Player& other);
	Player& operator=(Player&& other);
	virtual ~Player();

	virtual void print() const = 0;
	virtual Player* clone() const = 0;
	virtual int getDamage() const;


	int getHealth() const;
	const char* getName() const;
	Weapon getWeapon() const;
	
	void setHealth(int newH);
	void setWeapon(Weapon newW);
	void setDamage(int newD);

	virtual void handleAttack(int damage, int health, int position);

protected:
	void Swap(Player& other);
private:
	int health;
	const char* name;
	Position position;
	Weapon weapon;
	int damage;

	void moveFrom(Player&& other);

};
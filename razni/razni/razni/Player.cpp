#include "Player.h"

Player::Player(int health, const char* name, Position position, Weapon weapon, int damage):health(health),name(nullptr),position(position),weapon(weapon),damage(damage){
	if (health < 0)
		throw std::invalid_argument("Invalid");
	if (damage < 0)
		throw std::invalid_argument("Invalid");
}

Player::Player(const Player& other):health(other.health),position(other.position),weapon(other.weapon),damage(other.damage){

}

Player& Player::operator=(const Player& other){
	if (this != &other) {
		health = other.health;
		position = other.position;
		weapon = other.weapon;
		damage = other.damage;
	}
	return *this;
}

int Player::getHealth() const{
	return health;
}

const char* Player::getName() const{
	return name;
}

Weapon Player::getWeapon() const{
	return weapon;
}

int Player::getDamage() const{
	return damage;
}

void Player::setHealth(int newH){
	if (newH < 0)
		throw std::invalid_argument("Invalid");
	health = newH;
}

void Player::setWeapon(Weapon newW){
	switch (newW) {
	case Weapon::Sword:std::cout << "Sword";
	case Weapon::Wand:std::cout << "Wand";
	case Weapon::Staff:std::cout << "Staff";
	case Weapon::Axe:std::cout << "Axe";
	default:Weapon::UNKNOWN;
	}
}

void Player::setDamage(int newD){
	if (newD < 0)
		throw std::invalid_argument("Invalid");
	damage = newD;
}

void Player::handleAttack(int damage, int health, int position)
{
}

void Player::Swap(Player& other){
	std::swap(health, other.health);
	std::swap(name, other.name);
	std::swap(weapon, other.weapon);
	std::swap(damage, other.damage);
}

void Player::moveFrom(Player&& other){
	health = other.health;
	position = other.position;
	weapon = other.weapon;
	damage = other.damage;

	name = other.name;
	other.name = nullptr;
}



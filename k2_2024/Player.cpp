#include "Player.h"

Player::Player(int health, const char* name, Position position, Weapon weapon, int damage):health(health),name(nullptr),position(position),weapon(weapon),damage(damage){
	if (health < 0)
		throw std::invalid_argument("Invalid");
	if (damage < 0)
		throw std::invalid_argument("Invalid");
	setName(name);
}

Player::Player(const Player& other):Player(other.health,other.name,other.position,other.weapon,other.damage){}

Player& Player::operator=(const Player& other){
	if (this != &other) {
		char* newName = nullptr;
		try {
			newName = new char[strlen(other.name) + 1];
			strcpy(newName, other.name);
		}
		catch (...) {
			delete[] newName;
			throw;
		}
		delete[] name;
		name = newName;

		health = other.health;
		position = other.position;
		weapon = other.weapon;
		damage = other.damage;
	}
	return *this;
}

Player::~Player(){
	delete[] name;
}

void Player::print() const{
	std::cout << "Health" << getHealth() << "Name" << getName() << "Position" << getPosition() << "Weapon" << getWeapon() << "Damage" << getDamage() << std::endl;
}

int Player::power() const{
	return damage;
}

int Player::getHealth() const{
	return health;
}

const char* Player::getName() const{
	return name;
}

Position Player::getPosition() const{
	return position;
}

Weapon Player::getWeapon() const{
	return weapon;
}

bool Player::isDead() const {
	return health==0;
}

void Player::attack(Player& target) {
	if (!areNeightboors(position, target.position))
		return;
	target.handleAttack(power());
}

void Player::setHealth(int newH){
	if (newH < 0)
		throw std::invalid_argument("Invalid");
	health = newH;
}

void Player::setName(const char* newName){
	dynCpy(name, newName);
}

void Player::setDamage(int newD){
	if (newD <= 0)
		throw std::invalid_argument("Invalid");
	damage = newD;
}

void Player::handleAttack(int power){
	reduceHealth(power);
}


void Player::reduceHealth(int amount){
	if (amount <= 0)
		throw std::invalid_argument("Invalud");
	if (amount >= health)
		health = 0;
	else
		health -= amount;
}

void Player::Swap(Player& other){
	std::swap(health, other.health);
	std::swap(name, other.name);
	std::swap(position, other.position);
	std::swap(weapon, other.weapon);
	std::swap(damage, other.damage);
}


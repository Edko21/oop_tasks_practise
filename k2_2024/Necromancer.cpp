#include "Necromancer.h"

Necromancer::Necromancer(int health, const char* name, Position p, int damage, const char* magicSkill, int coef){
    for (int i = 0;i < MAX_DEFEATED;i++) {
        defeated[i] = nullptr;
    }
}

Necromancer::Necromancer(const Necromancer& other) :Mage(other), defeatedCount(0) {
    for (int i = 0;i < MAX_DEFEATED;i++) {
        defeated[i] = nullptr;
    }
    copyFrom(other);
}

Necromancer& Necromancer::operator=(const Necromancer& other){
    if (this != &other) {
        Mage::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Necromancer::~Necromancer(){
    free();
}

void Necromancer::attack(Player& target) const{ 

}

int Necromancer::getCount() const{
    return defeatedCount;
}

void Necromancer::print() const{
    Mage::print();
    std::cout << "Defeated count" << getCount() << std::endl;
}

Player* Necromancer::clone() const{
    return new Necromancer(*this);
}

void Necromancer::free(){
    for (int i = 0;i < MAX_DEFEATED;i++) {
        delete defeated[i];
        defeated[i] = nullptr;
    }
    defeatedCount = 0;
}

void Necromancer::copyFrom(const Necromancer& other){
    for (int i = 0;i < defeatedCount;i++) {
        defeated[i] = other.defeated[i]->clone();
    }
    for (int i = 0;i < MAX_DEFEATED;i++) {
        defeated[i] = nullptr;
    }
}

void Necromancer::addDefeated(const Player& player){
    if (defeatedCount >= MAX_DEFEATED) {
        return;
    }
    defeated[defeatedCount] = player.clone();
    defeatedCount++;
}

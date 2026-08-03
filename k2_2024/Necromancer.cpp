#include "Necromancer.h"

Necromancer::Necromancer(int health, const char* name, Position p, int damage, const char* magicSkill, int coef)
    :Mage(health, name, p, damage, magicSkill, coef),defeated{},defeatedCount(0){
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

void Necromancer::attack(Player& target){ 
    if (target.isDead())
        return;

    Position currPos = getPosition();
    Position targetPos = target.getPosition();

    if (std::abs(currPos.x - targetPos.x) != 1 || std::abs(currPos.y - targetPos.y) != 1)
        return;
    Mage::attack(target);

    if (!target.isDead() && defeatedCount > 0) {
        size_t randomInd = std::rand() % defeatedCount;
        int additionalPower = defeated[randomInd]->power();
        target.handleAttack(additionalPower);
    }

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
    Player* defeated[MAX_DEFEATED]{};
    for (int i = 0;i < other.defeatedCount;i++) {
        defeated[i] = other.defeated[i]->clone();
    }
    for (int i = 0;i < MAX_DEFEATED;i++) {
        delete defeated[i];
    }
    delete[] defeated;
}

void Necromancer::addDefeated(const Player& player){
    if (defeatedCount >= MAX_DEFEATED) {
        return;
    }
    defeated[defeatedCount] = player.clone();
    defeatedCount++;
}

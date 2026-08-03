#include "PlayerCollection.h"

PlayerCollection::PlayerCollection(size_t cap):players(nullptr),size(0),cap(cap){
	players = new Player * [cap] {};
	for (int i = 0;i < size;i++) {
		players[i] = nullptr;
	}
}

PlayerCollection::~PlayerCollection(){
	free();
}

bool PlayerCollection::addPlayer(const Player& player){	
	if (size >= cap)
		return false;

	for (int i = 0;i < size;i++) {
		if (strcmp(players[i]->getName(), player.getName()) == 0)
			return false;
	}
	players[size] = player.clone();
	size++;
	return true;
}

bool PlayerCollection::removeBy(const char* name){
	for (int i = 0;i < size;i++) {
		if (strcmp(players[i]->getName(), name) == 0) {
			delete players[i];

			for (size_t j = i;j+1 < size ;j++) {
				players[j] = players[j + 1];
			}
			size--;
			players[i] = nullptr;
			return true;
		}
	}
	return false;
}

const Player* PlayerCollection::operator[](int ind) const{
	if (ind >= size)
		throw std::out_of_range("Invalid");
	return players[ind];
}

size_t PlayerCollection::getSize() const{
	return size;
}

void PlayerCollection::free(){
	for (size_t i = 0;i < size;i++) {
		delete players[i];
	}
	delete[] players;
	players = nullptr;
}

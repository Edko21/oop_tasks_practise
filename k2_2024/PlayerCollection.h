#pragma once
#include "Player.h"

class PlayerCollection {
public:
	PlayerCollection(size_t cap);
	PlayerCollection(const PlayerCollection& other);
	PlayerCollection& operator=(const PlayerCollection& other);
	~PlayerCollection();

	bool addPlayer(const Player& player);
	bool removeBy(const char* name);
	const Player* operator[](int ind) const;

	size_t getSize() const;

private:
	Player** players;
	size_t size;
	size_t cap;

	void free();
};
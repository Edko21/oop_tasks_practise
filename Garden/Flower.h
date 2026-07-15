#pragma once
#include "Plant.h"


class Flower :public Plant {
public:
	Flower(const char* vid, const char* sort, int height, Type type,const bool months[12]);
	Flower(const Flower& other);
	Flower& operator=(const Flower& other);
	~Flower() override = default;

	Plant* clone() const override;
	char* getDescription() const override;
private:
	bool bloomingMonths[12];
	static const char* getBloomingM(int month);
};
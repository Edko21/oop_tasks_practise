#pragma once
#include "Plant.h"


class Flower :public Plant {
public:
	Flower(const char* vid, const char* sort, int height,const bool months[12]);
	Flower(const Flower& other);
	Flower& operator=(const Flower& other) = delete;
	~Flower() override;

	Plant* clone() const override;
	void getDescription() override;
private:
	bool bloomingMonths[12];
	static const bool getBloomingM(int month);
};
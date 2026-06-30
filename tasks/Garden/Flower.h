#pragma once
#include "Plant.h"

class Flower :public Plant {
public:
	Flower(const char* vid, const char* sort, int height, const bool months[12]);
	Flower(const Flower& other);
	Flower& operator=(const Flower& other) = delete;

	Plant* clone() const override;
	char* getDescription() const override;



private:
	bool bloomingMonths[12];

	static const bool getMName(size_t month) {
		static const char* months[12] = {
			"january","february","march","april","may","june","july","august",
			"september","october","november","december"
		};
		return months[month];
	}
};
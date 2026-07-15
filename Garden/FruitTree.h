#pragma once
#include "Plant.h"


class FruitTree :public Plant {
public:
	FruitTree(const char* vid, const char* sort, int height,Type type, const char* recipe);
	FruitTree(const FruitTree& other);
	FruitTree& operator=(const FruitTree& other);
	~FruitTree() override;

	const char* getRecipe() const;
	void setRecipe(const char* newRecipe);

	Plant* clone() const override;
	char* getDescription() const override;
protected:
	void Swap(FruitTreet& other);
private:
	char* recipe;
};
#pragma once
#include "Plant.h"


class TreeBush :public Plant {
public:
	TreeBush(const char* vid, const char* sort, int height, const char* recipe);
	TreeBush(const TreeBush& other);
	TreeBush& operator=(const TreeBush& other);
	~TreeBush() override;

	const char* getRecipe() const;
	void setRecipe(const char* newRecipe);

	Plant* clone() const override;
	char* getDescription() const override;

private:
	char* recipe;

};
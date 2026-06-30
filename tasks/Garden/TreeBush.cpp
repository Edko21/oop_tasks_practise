#include "TreeBush.h"

TreeBush::TreeBush(const char* vid, const char* sort, int height, const char* recipe) :Plant(vid, sort, height, Type::Bush), recipe(nullptr) {
	setRecipe(recipe);
}

TreeBush::TreeBush(const TreeBush& other):Plant(other){
	setRecipe(other.recipe);
}

TreeBush& TreeBush::operator=(const TreeBush& other){
	if (this != &other) {
		TreeBush temp(other);
		Swap(temp);
	}
	return *this;
}

TreeBush::~TreeBush(){
	delete[] recipe;
	recipe = nullptr;
}

const char* TreeBush::getRecipe() const{
	return recipe;
}

void TreeBush::setRecipe(const char* newRecipe){
	dynCpy(recipe, newRecipe);
}

Plant* TreeBush::clone() const{
	return new TreeBush(*this);
}

char* TreeBush::getDescription() const{
	size_t len = strlen(getVid()) + strlen(getSort()) + strlen(recipe) + 3;
	char* desc = new char[len + 1];
	desc[0] = '\0';

	strcat(desc, getVid());
	strcat(desc, " ");
	strcat(desc, getSort());
	strcat(desc, " ");
	strcat(desc, recipe);

	return desc;
}

void TreeBush::Swap(TreeBush& other){
	Plant::Swap(other);
	std::swap(recipe, other.recipe);
}







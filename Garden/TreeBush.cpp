#include "TreeBush.h"

TreeBush::TreeBush(const char* vid, const char* sort, int height, const char* recipe):Plant(vid,sort,height),recipe(nullptr){
    setRecipe(recipe);
}

TreeBush::TreeBush(const TreeBush& other) :Plant(other) {
    setRecipe(other.recipe);
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

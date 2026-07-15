#include "FruitTree.h"

FruitTree::FruitTree(const char* vid, const char* sort, int height,Type type, const char* recipe):Plant(vid,sort,height),recipe(nullptr){
    if (type != Type::Tree && type != Type::Bush)
        throw std::invalid_argument("Invalid type");
    setRecipe(recipe);
}

FruitTree::FruitTree(const FruitTree& other) :Plant(other) {
    setRecipe(other.recipe);
}

FruitTree& FruitTree::operator=(const FruitTree& other) {
    if (this != &other) {
        FruitTree temp(other);
        Swap(other);
    }
    return *this;
}

FruitTree::~FruitTree(){
    delete[] recipe;
    recipe = nullptr;
}

const char* FruitTree::getRecipe() const{
    return recipe;
}

void FruitTree::setRecipe(const char* newRecipe){
    dynCpy(recipe, newRecipe);
}

Plant* FruitTree::clone() const{
    return new FruitTree(*this);
}

char* FruitTree::getDescription() const{
    int len =std::strlen(getVid()) + 1 + std::strlen(getSort()) + 1 + std::strlen(recipe);

    char* desc = new char[len + 1];

    std::strcpy(desc, getVid());
    std::strcat(desc, " ");
    std::strcat(desc, getSort());
    std::strcat(desc, " ");
    std::strcat(desc, recipe);

    return desc;
}

void FruitTree::Swap(FruitTreet & other) {
    Plant::Swap(other);
    std::swap(recipe, other.recipe);
}
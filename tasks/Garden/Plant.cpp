#include "Plant.h"

Plant::Plant(const char* vid, const char* sort, int height, Type t):vid(nullptr),sort(nullptr),height(height),t(t){
	if (height < 0)
		throw std::invalid_argument("Invalid");
	try {
		setVid(vid);
		setSort(sort);
	}
	catch (...) {
		delete[] this->vid;
		delete[] this->sort;
		this->vid = nullptr;
		this->sort = nullptr;

		throw;
	}
}

Plant::Plant(const Plant& other):height(other.height),t(other.t){
		setVid(other.vid);
		setSort(other.sort);
}

void Plant::Swap(Plant& other){
	std::swap(vid, other.vid);
	std::swap(sort, other.sort);
	std::swap(height, other.height);
}

Plant::~Plant(){
	delete[] vid;
	delete[] sort;
	vid = nullptr;
	sort = nullptr;
}

const char* Plant::getVid() const{
	return vid;
}

const char* Plant::getSort() const{
	return sort;
}

int Plant::getHeight() const{
	return height;
}

void Plant::setVid(const char* newVid){
	dynCpy(vid, newVid);
}

void Plant::setSort(const char* newSort){
	dynCpy(sort, newSort);
}

void Plant::setHeight(int newHeight){
	if (height < 0)
		throw std::invalid_argument("Invalid");
	height = newHeight;
}







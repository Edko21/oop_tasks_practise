#include "Plant.h"

Plant::Plant(const char* vid, const char* sort, int height,Type type):vid(nullptr),sort(nullptr),height(height),type(type){
	if (height < 0)
		throw std::invalid_argument("Invalid");
	try {
		setVid(vid);
		setSort(sort);
	}
	catch (...) {
		delete[] this->vid;
		delete[] this->sort;
		throw;
	}
}

Plant::Plant(const Plant& other):vid(nullptr),sort(nullptr),height(other.height){
	try {
		setVid(other.vid);
		setSort(other.sort);
	}
	catch (...) {
		delete[] vid;
		delete[] sort;
		throw;
	}
}

Plant& Plant::operator=(const Plant& other){
	if (this != &other) {
		char* newVid = nullptr;
		char* newSort = nullptr;
		try {
			newVid = new char[strlen(other.vid) + 1];
			strcpy(newVid, other.vid);

			newSort = new char[strlen(other.sort) + 1];
			strcpy(newSort, other.sort);
		}
		catch (...) {
			delete[] newVid;
			delete[] newSort;
			throw;
		}
		delete[] vid;
		delete[] sort;
		vid = nullptr;
		sort = nullptr;
	}
	return *this;
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

Type Plant::getType() const{
	return type;
}

void Plant::setVid(const char* newVid){
	dynCpy(vid, newVid);
}

void Plant::setSort(const char* newSort){
	dynCpy(sort, newSort);
}

void Plant::setHeight(int newHeight){
	if(newHeight<0)
		throw std::invalid_argument("Invalid");
	height = newHeight;
}


#pragma once
#include "Utils.hpp"
#include <iostream>

enum class Type {
	UNKNOWN = -1,
	Grass,
	Tree,
	Bush,
	Moss,
	Other
};

class Plant {
public:
	Plant(const char* vid, const char* sort, int height, Type t);
	
	Plant& operator=(const Plant& other) = delete;
	virtual ~Plant();

	const char* getVid() const;
	const char* getSort() const;
	int getHeight() const;

	void setVid(const char* newVid);
	void setSort(const char* newSort);
	void setHeight(int newHeight);

	virtual char* getDescription() const = 0;
	virtual Plant* clone() const = 0;

protected:
	Plant(const Plant& other);
	void Swap(Plant& other);
private:
	char* vid;
	char* sort;
	int height;
	const Type t;
};
#pragma once
#include "GardenUtils.hpp"

enum class Type{
	Grass,
	Tree,
	Bush,
	Moss,
	Other
};

class Plant {
public:
	Plant(const char* vid, const char* sort, int height,Type type);
	Plant(const Plant& other);
	Plant& operator=(const Plant& other);
	virtual ~Plant();

	const char* getVid() const;
	const char* getSort() const;
	int getHeight() const;
	Type getType() const;

	void setVid(const char* newVid);
	void setSort(const char* newSort);
	void setHeight(int newHeight);

	virtual Plant* clone() const = 0;
	virtual char* getDescription() const = 0;
private:
	char* vid;
	char* sort;
	int height;
	Type type;
};
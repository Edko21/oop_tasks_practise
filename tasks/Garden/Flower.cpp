#include "Flower.h"

Flower::Flower(const char* vid, const char* sort, int height, const bool months[12]) :Plant(vid, sort, height, Type::Grass){
	for (int i = 0;i < 12;i++) {
		bloomingMonths[i] = months[i];
	}
}

Flower::Flower(const Flower& other):Plant(other){
	for (int i = 0;i < 12;i++)
		bloomingMonths[i] = other.bloomingMonths[i];
}

Plant* Flower::clone() const{
	return new Flower(*this);
}

char* Flower::getDescription() const{
	size_t len = strlen(getSort()) + strlen(getVid()) + 2;

	for (int i = 0;i < 12;i++) {
		if (bloomingMonths[i])
			len += strlen(getMName(i)) + 1;
	}
	
	char* desc = new char[len + 1];
	desc[0] = '\0';

	strcat(desc, getVid());
	strcat(desc, " ");
	strcat(desc, getSort());

	for (int i = 0;i < 12;i++) {
		if (bloomingMonths[i]) {
			strcat(desc, " ");
			strcat(desc, getMName(i));
		}
	}
}






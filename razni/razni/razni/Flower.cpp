#include "Flower.h"

Flower::Flower(const char* vid, const char* sort, int height,const bool months[12]) :Plant(vid, sort, height, Type::Grass), months(months) {
    for (int i = 0;i < 12;i++) {
        bloomingMonths[i] = months[i];
    }
}

Flower::Flower(const Flower& other):Plant(other){
    for (int i = 0;i < 12;i++) {
        bloomingMonths[i] = other.bloomingMonths[i];
    }
}

Plant* Flower::clone() const{
    return new Flower(*this);
}

const bool Flower::getBloomingM(int month)
{
    const char* months[12] = {
        "january","february","march","april","may","june","july","august",
            "september","october","november","december"
    };
    return months[month];
}

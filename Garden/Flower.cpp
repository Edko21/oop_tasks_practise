#include "Flower.h"

Flower::Flower(const char* vid, const char* sort, int height, Type type, const bool months[12]) :Plant(vid, sort, height, type), months(months) {
    for (int i = 0;i < 12;i++) {
        bloomingMonths[i] = months[i];
    }
}

Flower::Flower(const Flower& other):Plant(other){
    for (int i = 0;i < 12;i++) {
        bloomingMonths[i] = other.bloomingMonths[i];
    }
}

Flower& Flower::operator=(const Flower& other){
    if (this != &other) {
        Flower temp(other);
        Swap(temp);
   }
    return *this;
}

Plant* Flower::clone() const{
    return new Flower(*this);
}

char* Flower::getDescription() const{
    int len = strlen(getVid()) + 1 + strlen(getSort());
    for (int i = 0;i < 12;i++) {
        if (bloomingMonths[i])
            len += 1 + strlen(getBloomingM());
    }
    char* desc = new char[len + 1];
    std::strcpy(desc, getVid());
    std::strcat(desc, " ");
    std::strcat(desc, getSort());

    for (size_t i = 0; i < 12; i++) {
        if (bloomingMonths[i]) {
            std::strcat(desc, " ");
            std::strcat(desc,getMonthName(i));
        }
    }

    return desc;
}

const char* Flower::getBloomingM(int month)
{
    const char* months[12] = {
        "january","february","march","april","may","june","july","august",
            "september","october","november","december"
    };
    return months[month];
}

#pragma once
#include "Vehicle.h"

class Garage {
public:
    Garage(size_t cap);

    Garage(const Garage& other);
    Garage& operator=(const Garage& other);
    ~Garage();

    void add(const Vehicle& vehicle);
    void remove(const char* brand, const char* model);

    size_t getSize() const;
    size_t getCap() const;
    size_t getFreePlaces() const;
    size_t getCarsCount() const;

    double getAllDanak() const;

    Vehicle* operator[](size_t ind);
    const Vehicle* operator[](size_t ind) const;

private:
    Vehicle** v;
    size_t size;
    size_t cap;

    void free();
    void copyFrom(const Garage& other);
};
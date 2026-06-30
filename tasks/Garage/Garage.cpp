#include "Garage.h"
#include "Car.h"
#include <cstring>
#include <stdexcept>

Garage::Garage(size_t cap) : size(0), cap(cap) {
    if (cap == 0) {
        throw std::invalid_argument("Invalid capacity");
    }

    v = new Vehicle * [cap];

    for (size_t i = 0; i < cap; i++) {
        v[i] = nullptr;
    }
}

Garage::Garage(const Garage& other) {
    copyFrom(other);
}

Garage& Garage::operator=(const Garage& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Garage::~Garage() {
    free();
}

void Garage::add(const Vehicle& vehicle) {
    if (size >= cap) {
        throw std::out_of_range("Garage is full");
    }

    v[size] = vehicle.clone();
    size++;
}

void Garage::remove(const char* brand, const char* model) {
    for (size_t i = 0; i < size;) {
        if (strcmp(v[i]->getBrand(), brand) == 0 &&
            strcmp(v[i]->getModel(), model) == 0) {

            delete v[i];

            for (size_t j = i; j < size - 1; j++) {
                v[j] = v[j + 1];
            }

            size--;
            v[size] = nullptr;
        }
        else {
            i++;
        }
    }
}

size_t Garage::getSize() const {
    return size;
}

size_t Garage::getCap() const {
    return cap;
}

size_t Garage::getFreePlaces() const {
    return cap - size;
}

size_t Garage::getCarsCount() const {
    size_t carsCount = 0;

    for (size_t i = 0; i < size; i++) {
        if (dynamic_cast<Car*>(v[i]) != nullptr) {
            carsCount++;
        }
    }

    return carsCount;
}

double Garage::getAllDanak() const {
    double total = 0;

    for (size_t i = 0; i < size; i++) {
        total += v[i]->getDanak();
    }

    return total;
}

Vehicle* Garage::operator[](size_t ind) {
    if (ind >= size) {
        throw std::out_of_range("Invalid index");
    }

    return v[ind];
}

const Vehicle* Garage::operator[](size_t ind) const {
    if (ind >= size) {
        throw std::out_of_range("Invalid index");
    }

    return v[ind];
}

void Garage::free() {
    for (size_t i = 0; i < size; i++) {
        delete v[i];
    }

    delete[] v;

    v = nullptr;
    size = 0;
    cap = 0;
}

void Garage::copyFrom(const Garage& other) {
    size = other.size;
    cap = other.cap;

    v = new Vehicle * [cap];

    for (size_t i = 0; i < size; i++) {
        v[i] = other.v[i]->clone();
    }

    for (size_t i = size; i < cap; i++) {
        v[i] = nullptr;
    }
}
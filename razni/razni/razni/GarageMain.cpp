#include <iostream>
#include <cstring>
#include <exception>

#include "Garage.h"
#include "Car.h"
#include "Truck.h"

int main() {
    try {
        size_t garageCap;
        std::cout << "Garage capacity: ";
        std::cin >> garageCap;
        std::cin.ignore();

        Garage garage(garageCap);

        int count;
        std::cout << "Count: ";
        std::cin >> count;
        std::cin.ignore();

        for (int i = 0; i < count; i++) {
            if (garage.getSize() >= garage.getCap()) {
                std::cout << "Garage is full!\n";
                break;
            }

            int type;
            char brand[100];
            char model[100];
            char regNum[20];

            std::cout << "Vehicle " << i + 1 << std::endl;
            std::cout << "1 - Car, 2 - Truck: ";
            std::cin >> type;
            std::cin.ignore();

            std::cout << "Brand: ";
            std::cin.getline(brand, 100);

            std::cout << "Model: ";
            std::cin.getline(model, 100);

            std::cout << "Registration number: ";
            std::cin.getline(regNum, 20);

            if (type == 1) {
                char engine[100];
                int hp;

                std::cout << "Engine: ";
                std::cin.getline(engine, 100);

                std::cout << "Horse power: ";
                std::cin >> hp;
                std::cin.ignore();

                Car car(brand, model, regNum, engine, hp);
                garage.addV(car);
            }
            else if (type == 2) {
                double load;
                char description[100];

                std::cout << "Load: ";
                std::cin >> load;
                std::cin.ignore();

                std::cout << "Description: ";
                std::cin.getline(description, 100);

                Truck truck(brand, model, regNum, load, description);
                garage.addV(truck);
            }
            else {
                std::cout << "Invalid type!\n";
            }
        }

        std::cout << "All vehicles:\n";
        for (size_t i = 0; i < garage.getSize(); i++) {
            std::cout << "Brand: " << garage[i]->getBrand() << std::endl;
            std::cout << "Model: " << garage[i]->getModel() << std::endl;
            std::cout << "Reg number: " << garage[i]->getRegNum() << std::endl;
            std::cout << "Tax: " << garage[i]->getTax() << std::endl;
            std::cout << std::endl;
        }

        if (garage.getSize() > 0) {
            size_t maxIndex = 0;

            for (size_t i = 1; i < garage.getSize(); i++) {
                if (garage[i]->getTax() > garage[maxIndex]->getTax()) {
                    maxIndex = i;
                }
            }

            char brandToRemove[100];
            char modelToRemove[100];

            strcpy(brandToRemove, garage[maxIndex]->getBrand());
            strcpy(modelToRemove, garage[maxIndex]->getModel());

            garage.removeBy(brandToRemove, modelToRemove);

            std::cout << "Vehicle with highest tax removed.\n";
        }

        std::cout << "Total tax: " << garage.getAllTax() << std::endl;

        std::cout << "Mercedes models:\n";
        bool foundMercedes = false;

        for (size_t i = 0; i < garage.getSize(); i++) {
            if (strcmp(garage[i]->getBrand(), "Mercedes") == 0) {
                std::cout << garage[i]->getModel() << std::endl;
                foundMercedes = true;
            }
        }

        if (!foundMercedes) {
            std::cout << "No Mercedes vehicles.\n";
        }

        std::cout << "Free spaces: " << garage.getFreeSpaces() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
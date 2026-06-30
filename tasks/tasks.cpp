#include <iostream>
#include "Garage.h"
#include "Car.h"
#include "Truc.h"

int main() {
    try {
        Garage garage(5);

        Car c1("BMW", "E90", "CA1234AB", "diesel", 150);
        Car c2("Audi", "A4", "CB5678CD", "gasoline", 180);
        Car c3("BMW", "E90", "CA9999EE", "gasoline", 120);

        Truc t1("Volvo", "FH", "PB1111AA", 12.5, "Furniture");
        Truc t2("Mercedes", "Actros", "PB2222BB", 20.0, "");

        garage.add(c1);
        garage.add(c2);
        garage.add(c3);
        garage.add(t1);
        garage.add(t2);

        std::cout << "Capacity: " << garage.getCap() << std::endl;
        std::cout << "Vehicles count: " << garage.getSize() << std::endl;
        std::cout << "Free places: " << garage.getFreePlaces() << std::endl;
        std::cout << "Cars count: " << garage.getCarsCount() << std::endl;

        std::cout << "Total tax: " << garage.getAllDanak() << std::endl;

        std::cout << std::endl;
        std::cout << "Vehicle at index 0: ";
        std::cout << garage[0]->getBrand() << " "
            << garage[0]->getModel() << std::endl;

        std::cout << "Tax of vehicle at index 0: "
            << garage[0]->getDanak() << std::endl;

        std::cout << std::endl;
        std::cout << "Removing BMW E90..." << std::endl;

        garage.remove("BMW", "E90");

        std::cout << "Vehicles count after remove: "
            << garage.getSize() << std::endl;

        std::cout << "Cars count after remove: "
            << garage.getCarsCount() << std::endl;

        std::cout << "Total tax after remove: "
            << garage.getAllDanak() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
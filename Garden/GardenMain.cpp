#include <iostream>

#include "Garden.h"
#include "Flower.h"
#include "FruitTree.h"

int main() {
    try {
        bool roseMonths[12] = {
            false, false, false,
            true, true, true,
            false, false, false,
            false, false, false
        };

        bool tulipMonths[12] = {
            false, false, true,
            true, true, false,
            false, false, false,
            false, false, false
        };

        Flower rose(
            "Rose",
            "Damask",
            120,
            Type::Bush,
            roseMonths
        );

        Flower tulip(
            "Tulip",
            "Queen of Night",
            50,
            Type::Grass,
            tulipMonths
        );

        FruitTree apple(
            "Apple",
            "Golden",
            350,
            Type::Tree,
            "Apple pie"
        );

        FruitTree raspberry(
            "Raspberry",
            "Heritage",
            150,
            Type::Bush,
            "Raspberry jam"
        );

        Garden garden(10);

        garden.addPlant(rose);
        garden.addPlant(tulip);
        garden.addPlant(apple);
        garden.addPlant(raspberry);

        std::cout << "Plants:\n";
        garden.info();

        std::cout << "Size: "
            << garden.getSize() << '\n';

        std::cout << "Removing apple plants \n";

        if (garden.eradicate("Apple")) {
            std::cout << "Plants removed\n";
        }
        else {
            std::cout << "No found.\n";
        } 

        std::cout << "Plants eradicate:\n";
        garden.info();

        std::cout << "Size: "
            << garden.getSize() << '\n';

        std::cout << "Copy:\n";

        Garden copiedGarden(garden);
        copiedGarden.info();

        std::cout << "Assigned garden:\n";

        Garden assignedGarden(2);
        assignedGarden = garden;
        assignedGarden.info();
    }
    catch (const std::exception& exception) {
        std::cout << "Error: "
            << exception.what() << '\n';
    }

    return 0;
}
#include <iostream>
#include "BulFmi.h"
#include "CargoCarPolicy.h"
#include "PropertyFirePolicy.h"
#include "ElectronicEquipmentPolicy.h"
#include "PropertyAndEquipmentPolicy.h"

int main() {
    CargoCarPolicy cargo(
        "Cargo car insurance",
        10000,
        "Mercedes",
        "Sofia - Varna",
        50000,
        4000
    );

    PropertyFirePolicy property(
        "House fire insurance",
        80000,
        120000,
        95.5,
        2010,
        true
    );

    ElectronicEquipmentPolicy equipment(
        "Laptop insurance",
        3000,
        "Laptop",
        2022,
        2500
    );

    PropertyAndEquipmentPolicy combined(
        "Property and equipment insurance",
        100000,
        120000,
        95.5,
        2010,
        true,
        "Computers",
        2021,
        5000,
        30,
        125000
    );

    std::cout << "===== TEST PRINT =====" << std::endl;

    cargo.print();
    property.print();
    equipment.print();
    combined.print();

    std::cout << std::endl;
    std::cout << "===== TEST BULFMI =====" << std::endl;

    BulFmi company(500000);

    company.addPolicy(&cargo);
    company.addPolicy(&property);
    company.addPolicy(&equipment);
    company.addPolicy(&combined);

    company.printAll();

    std::cout << std::endl;
    std::cout << "Policies count: " << company.getSize() << std::endl;
    std::cout << "Remaining budget: " << company.getBudget() << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST COPY CONSTRUCTOR =====" << std::endl;

    CargoCarPolicy cargoCopy(cargo);
    cargoCopy.print();

    std::cout << std::endl;
    std::cout << "===== TEST OPERATOR= =====" << std::endl;

    ElectronicEquipmentPolicy equipment2(
        "Phone insurance",
        1000,
        "Phone",
        2023,
        900
    );

    equipment2 = equipment;
    equipment2.print();

    std::cout << std::endl;
    std::cout << "===== TEST POLYMORPHISM =====" << std::endl;

    Policy* p = combined.clone();
    p->print();

    delete p;

    return 0;
}
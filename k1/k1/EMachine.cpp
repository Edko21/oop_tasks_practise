#include "EMachine.h"

int EMachine::nextId = 1;

EMachine::EMachine(const char* description, const char* brand, int power)
	:id(nextId++),description(nullptr), brand(nullptr), power(power), isPlugged(isPlugged), isActive(isActive),pluggedPlace(nullptr){ 
	if (power < 0)
		throw std::invalid_argument("Invalid");
	try {
		setDescription(description);
		setBrand(brand);
	}
	catch (...) {
		delete[] this->description;
		delete[] this->brand;

		throw;
	}
}

EMachine::EMachine(const EMachine& other):id(nextId++),power(other.power),isPlugged(false),isActive(false){
	try {
		setDescription(other.description);
		setBrand(other.brand);
	}
	catch (...) {
		delete[] description;
		delete[] brand;
		delete[] pluggedPlace;
		throw;
	}
}


EMachine& EMachine::operator=(const EMachine& other){
	if (this != &other) {
		EMachine temp(other);
		Swap(temp);
	}
	return *this;
}

EMachine::~EMachine(){
	delete[] description;
	delete[] brand;
	delete[] pluggedPlace;
}

const char* EMachine::getDescripiton() const{
	return description;
}

const char* EMachine::getBrand() const{
	return brand;
}

int EMachine::getPower() const{
	return power;
}

bool EMachine::isPluggedM() const{
	return isPlugged;
}

bool EMachine::isActiveM() const{
	return isActive;
}

void EMachine::turnOn(){
	if (!isPlugged)
		throw std::logic_error("Invalid");
	isActive = true;
}

void EMachine::turnOff(){
	isActive = false;
}

void EMachine::setDescription(const char* newDescription){
	dynCpy(description, newDescription);
}

void EMachine::setBrand(const char* newBrand){
	dynCpy(brand, newBrand);
}

void EMachine::setPower(int newPower){
	if (newPower < 0)
		throw std::invalid_argument("Invalid");
	if (isPlugged)
		throw std::runtime_error("Cant change when plugged in");
	power = newPower;
}

void EMachine::setPlugged(const char* place){
	dynCpy(pluggedPlace, place);
	isActive = true;
}

void EMachine::setActive(bool isA){
	if (isA) {
		turnOn();
	}
	else {
		turnOff();
	}
}

void EMachine::print(std::ostream& os) const{
	os << "Serial number: " << id << '\n';
	os << "Description: " << description << '\n';
	os << "Brand: " << brand << '\n';
	os << "Power: " << power << '\n';

	os << "Plugged in: " << (isPlugged ? "yes" : "no") << '\n';

	if (isPlugged) {
		os << "Plugged place: " << pluggedPlace << '\n';
	}

	os << "Turned on: " << (isActive ? "yes" : "no") << '\n';
}

void EMachine::unplug(){
	isPlugged = false;
	isActive = false;
	delete[] pluggedPlace;
	pluggedPlace = nullptr;
}

bool EMachine::saveToFile(const char* filePath, const EMachine& machine){
	std::ofstream of(filePath, std::ios::binary);

	if (!of) {	
		std::cout << "Cant open file" << filePath;
		return false;
	}

	const size_t descLen = strlen(machine.description);
	of.write(reinterpret_cast<const char*>(&descLen), sizeof(descLen));
	of.write(machine.description, descLen);

	const size_t brandLen = strlen(machine.brand);
	of.write(reinterpret_cast<const char*>(&brandLen), sizeof(brandLen));
	of.write(machine.description, brandLen);

	of.write(reinterpret_cast<const char*>(&machine.power), sizeof(machine.power));
	of.write(reinterpret_cast<const char*>(&machine.isPlugged), sizeof(machine.isPlugged));
	of.write(reinterpret_cast<const char*>(&machine.isActive), sizeof(machine.isActive));
	of.write(reinterpret_cast<const char*>(&machine.id), sizeof(machine.id));

	of.close();
	return true;
}

bool EMachine::loadFromFile(const char* filePath, EMachine& outMachine){
	std::ifstream is(filePath, std::ios::binary);
	if (!is) {
		std::cout << "Cant open file" << filePath;
		return false;
	}

	size_t descLen = 0;
	is.read(reinterpret_cast<char*>(&descLen), sizeof(descLen));
	outMachine.description = new(std::nothrow) char[descLen + 1];
	if (!outMachine.description) {
		std::cout << "Couldn't allocate enough memory for the description\n";
		return false;
	}

	size_t brandLen = 0;
	is.read(reinterpret_cast<char*>(&brandLen), sizeof(brandLen));
	outMachine.brand = new(std::nothrow) char[brandLen + 1];
	if (!outMachine.brand) {
		std::cout << "Couldn't allocate enough memory for the brand\n";
		return false;
	}

	is.read(outMachine.description, descLen);
	outMachine.description[descLen + 1] = '\n';


	is.read(outMachine.brand, brandLen);
	outMachine.brand[brandLen + 1] = '\n';

	is.read(reinterpret_cast<char*>(&outMachine.power), sizeof(outMachine.power));
	is.read(reinterpret_cast<char*>(&outMachine.isPlugged), sizeof(outMachine.isPlugged));
	is.read(reinterpret_cast<char*>(&outMachine.isActive), sizeof(outMachine.isActive));
	is.read(reinterpret_cast<char*>(&outMachine.id), sizeof(outMachine.id));

	is.close();
	return true;
}

void EMachine::Swap(EMachine& other){
	std::swap(description, other.description);
	std::swap(brand, other.brand);
	std::swap(power, other.power);
	std::swap(isActive, other.isActive);
	std::swap(pluggedPlace, other.pluggedPlace);
}















#pragma once

class ParkingMachine {
public:
	ParkingMachine(const char* regno, size_t size, int time, double price);
	ParkingMachine(const ParkingMachine& other);
	ParkingMachine& operator=(const ParkingMachine& other);
	~ParkingMachine();


private:
	static constexpr int MAX_NUM = 7;
	char* regno[MAX_NUM];
	size_t size;
	int time;
	double price;
	void resize();

};
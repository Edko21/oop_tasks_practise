#pragma once

class EMachine {
public:
	EMachine(const char* description, const char* brand, int power, bool isPlugged, bool isActive, static int id);
	EMachine(const EMachine& other);
	EMachine& operator=(const EMachine& other);
	~EMachine();

	const char* getDescripiton() const;
	const char* getBrand() const;
	int getPower() const;
	bool isPlugged() const;
	bool isActive() const;

	void setDescription(const char* newDescription);
	void setBrand(const char* newBrand);
	void setPower(int newPower);
	void setPlugged(bool isP);
	void setActive(bool isA);

protected:
	void Swap(EMachine& other);
private:
	char* description;
	char* brand;
	int power;
	bool isPlugged;
	bool isActive;
	static int id;
	int cnt;
};
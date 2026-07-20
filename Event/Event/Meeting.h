#pragma once
#include "Event.h"

class Meeting :public Event {
public:
	Meeting(const char* name, const char* description, unsigned int duration, bool isRepeating, char** guests, size_t size,size_t cap);
	Meeting(const Meeting& other);
	Meeting& operator=(const Meeting& other);
	~Meeting() override;

	size_t getSize() const;
	size_t getCap() const;
	void setSize(size_t newSize);
	void setCap(size_t newCap);

private:
	char** guests;
	size_t size;
	size_t cap;

	void free();
	void copyFrom(const Meeting& other);
};
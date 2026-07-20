#pragma once
#include <iostream>
#include "Utils.hpp"

class Event {
public:
	Event(const char* name, const char* description, unsigned int duration, bool isRepeating);
	Event(const Event& other);
	Event& operator=(const Event& other);
	virtual ~Event();

	const char* getName() const;
	const char* getDescription() const;
	unsigned int getDuration() const;
	bool getRepeating() const;
	void setName(const char* newName);
	void setDescription(const char* newDescription);
	void setDuration(unsigned int newDuration);
	void setRepeating(bool newRepeating);

	virtual Event* clone() const;
	friend bool operator==(const Event& lhs, const Event& rhs);
	friend bool operator!=(const Event& lhs, const Event& rhs);
protected:
	void Swap(Event& other);
private:
	char* name;
	char* description;
	unsigned int duration;
	bool isRepeating;
};
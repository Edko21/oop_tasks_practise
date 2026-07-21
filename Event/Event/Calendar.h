#pragma once
#include "Event.h"


class Calendar {
public:
	Calendar(unsigned month);
	Calendar(const Calendar& other);
	Calendar& operator=(const Calendar& other);
	~Calendar();

	bool addEvent(const Event& event, unsigned day, unsigned hour);
	size_t getSize() const;
	unsigned getMonth() const;

	Event* operator[](int ind);
	const Event* operator[](int ind) const;

private:
	struct CalendarEntry {
		Event* event;
		unsigned day;
		unsigned hour;
	};
	unsigned month;
	CalendarEntry* entries;
	size_t size;
	size_t cap;

	void free();
	void copyFrom(const Calendar& other);
	void Swap(Calendar& other);
};
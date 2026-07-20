#pragma once
#include "Event.h"

class Task :public Event {
public:
	Task(const char* name, const char* description, unsigned int duration, bool isRepeating, Date deadline);
	Task(const Task& other) = default;
	Task& operator=(const Task& other) = default;
	~Task() override = default;

	Event* clone() const override;

	Date getDeadline() const;
	void setDeadline(Date newD);
private:
	Date deadline;
};

bool operator>(const Task& lhs, const Task& rhs);
bool operator<(const Task& lhs, const Task& rhs);
bool operator>=(const Task& lhs, const Task& rhs);
bool operator<=(const Task& lhs, const Task& rhs);

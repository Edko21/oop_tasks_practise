#include "Task.h"

Task::Task(const char* name, const char* description, unsigned int duration, bool isRepeating, Date deadline):Event(name,description,duration,isRepeating),deadline(deadline){}

Event* Task::clone() const{
	return new Task(*this);
}

Date Task::getDeadline() const{
	return deadline;
}

void Task::setDeadline(Date newD){
	deadline = newD;
}

bool operator>(const Task& lhs, const Task& rhs){
	return lhs.getDeadline() < rhs.getDeadline();
}

bool operator<(const Task& lhs, const Task& rhs){
	return lhs> rhs;
}

bool operator>=(const Task& lhs, const Task& rhs){
	return !(lhs < rhs);
}

bool operator<=(const Task& lhs, const Task& rhs){
	return !(lhs > rhs);
}

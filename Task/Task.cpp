#include "Task.h"

Task::Task(const int taskId, const char* taskName, int priority, Status status):taskId(cnt++),taskName(nullptr),priority(priority),status(status){
	setTaskName(taskName);
}

Task::Task(const Task& other):taskId(other.taskId),taskName(nullptr),priority(other.priority),status(other.status){
	setTaskName(other.taskName);
}

Task& Task::operator=(const Task& other){
	if (this != &other) {
		char* newTaskName = nullptr;
		newTaskName = new char[strlen(other.taskName) + 1];
		strcpy(newTaskName, other.taskName);

		priority = other.priority;
		status = other.status;
	}
	return *this;
}

Task::~Task(){
	delete[] taskName;
	taskName = nullptr;
}

const char* Task::getTaskName() const{
	return taskName;
}

Status Task::getStatus() const{
	return status;
}




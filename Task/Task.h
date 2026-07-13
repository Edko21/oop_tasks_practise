#pragma once
#include <iostream>

enum class Status {
	Not_Completed,
	Running,
	Completed
};

class Task {
public:
	Task(const int taskId, const char* taskName, int priority, Status status);
	Task(const Task& other);
	Task& operator=(const Task& other);
	virtual ~Task();

	const char* getTaskName() const;
	Status getStatus() const;
	void setTaskName(const char* newTaskName);
	void setPriority(int newPriority);
	void execute();
	virtual void dysplayTaskInfo();
	virtual Task* clone() const = 0;
private:
	const int taskId;
	int cnt;
	char* taskName;
	int priority;
	Status status;
};
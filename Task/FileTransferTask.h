#pragma once
#include "Task.h"

class FileTransferTask :public Task {
public:
	FileTransferTask(const int taskId, const char* taskName, int priority, Status status, const char* srcPath, const char* destPath, size_t fileSize);
	FileTransferTask(const FileTransferTask& other);
	FileTransferTask& operator=(const FileTransferTask& other);
	~FileTransferTask() override;

	const char* getSrc() const;
	const char* getDest() const;
	size_t getSize() const;

	void setSrc(const char* newSrc);
	void setDest(const char* newDest);
	void setSize(size_t newSize);
	Task* clone() const override;
protected:
	void Swap(FileTransferTask& other);
private:
	char* srcPath;
	char* destPath;
	size_t fileSize;
};
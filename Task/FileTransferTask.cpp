#include "FileTransferTask.h"

FileTransferTask::FileTransferTask(const int taskId, const char* taskName, int priority, Status status, const char* srcPath, const char* destPath, size_t fileSize) 
	:Task(taskId,taskName,priority,status),srcPath(nullptr),destPath(nullptr),fileSize(fileSize){
	setSrc(srcPath);
	setDest(destPath);
}

FileTransferTask::FileTransferTask(const FileTransferTask& other):Task(other),fileSize(other.fileSize){
	setSrc(other.srcPath);
	setDest(other.destPath);
}

FileTransferTask& FileTransferTask::operator=(const FileTransferTask& other){
	if (this!=&other) {
		FileTransferTask temp(other);
		Task::operator=(other);
		Swap(temp);
	}
	return *this;
}

FileTransferTask::~FileTransferTask(){
	delete[] srcPath;
	delete[] destPath;
	srcPath = nullptr;
	destPath = nullptr;
}

const char* FileTransferTask::getSrc() const{
	return srcPath;
}

const char* FileTransferTask::getDest() const{
	return destPath;
}

size_t FileTransferTask::getSize() const{
	return fileSize;
}

void FileTransferTask::setSrc(const char* newSrc){
	dynCpy(srcPath, newSrc);
}

void FileTransferTask::setDest(const char* newDest){
	dynCpy(destPath, newDest);
}

void FileTransferTask::setSize(size_t newSize){
	fileSize = newSize;
}

Task* FileTransferTask::clone() const{
	return new FileTransferTask(*this);
}

void FileTransferTask::Swap(FileTransferTask& other){
	std::swap(srcPath, other.srcPath);
	std::swap(destPath, other.destPath);
	std::swap(fileSize, other.fileSize);
}


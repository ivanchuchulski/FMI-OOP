#include "Task.h"
#include <iostream>
#include <string.h>



char* Task::SetCString(const char* source) {

	char* bufferPtr = nullptr;

	if (source != nullptr) {
		int len = strlen(source);
		bufferPtr = new char[len + 1];
		strcpy_s(bufferPtr, len + 1, source);
		return bufferPtr;
	}
	else {
		bufferPtr = new char[4] {"N/A"};
		return bufferPtr;
	}

}


Task::Task()
	:	m_Finished(false),
		m_TaskNum(123),
		m_Name(SetCString())
{}

Task::Task(bool finished, int num, const char* name)
	:	m_Finished(finished),
		m_TaskNum(num),
		m_Name(SetCString(name))
{}

Task::Task(const Task& someTask)
	:	m_Finished(someTask.m_Finished),
		m_TaskNum(someTask.m_TaskNum),
		m_Name(SetCString(someTask.m_Name))
{}


Task::~Task() {
	if (m_Name != nullptr) {
		delete[] m_Name;
		m_Name = nullptr;
	}
}


Task& Task::operator=(const Task& someTask) {

	if (this != &someTask) {
		//free current memory first
		if (m_Name != nullptr) {
			delete[] m_Name;
			m_Name = nullptr;
		}

		//copy from the source
		m_Finished = someTask.m_Finished;
		m_TaskNum = someTask.m_TaskNum;
		m_Name = SetCString(someTask.m_Name);

	}

	return *this;			// TODO: insert return statement here
}


bool Task::IsFinished() const {
	return m_Finished;
}

void Task::PrintInfo() const {
	std::cout << "Name : " << m_Name << ", Num : " << m_TaskNum << '\n';
}
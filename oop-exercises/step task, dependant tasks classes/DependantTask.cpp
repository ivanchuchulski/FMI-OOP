#include "DependantTask.h"
#include <iostream>


DependantTask::DependantTask()
	:	Task(),
		m_Condition(nullptr)
{}


DependantTask::DependantTask(bool finished, int num, const char* name, const Task& conditionTask)
	:	Task(finished, num, name),
		m_Condition(&conditionTask)
{}


DependantTask::~DependantTask()
{}

bool DependantTask::CanStart() const {
	//true if it is not finished AND the condition is finished or there is no condition
	return (IsFinished() == false) && 
			(m_Condition->IsFinished() == true || (m_Condition == nullptr)) ;
}

void DependantTask::DoWork() {

	if (CanStart() == true) {
		//the task finishes in one step
		m_Finished = true;
	}
	else {
		return;
	}
}

void DependantTask::PrintInfo() const {

	//printing about current task
	std::cout << "Dependant task := ";
	Task::PrintInfo();

	//then printing about its dependency
	if (m_Condition == nullptr) {
		std::cout << "It has no condition \n";
	}
	else {
		std::cout << "And its condition is : ";
		m_Condition->PrintInfo();
	}

}
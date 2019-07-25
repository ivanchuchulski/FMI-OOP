#include "StepTask.h"
#include "iostream"


StepTask::StepTask()
	:	Task(),
		m_StepsNeeded(5)
{}

StepTask::StepTask(bool finished, int num, const char * id, int steps)
	:	Task(finished, num, id),
		m_StepsNeeded(5)
{
	if (steps > 0) {
		m_StepsNeeded = steps;
	}
}

StepTask::~StepTask()
{}

bool StepTask::CanStart() const {
	return (	(m_StepsNeeded > 0) && (IsFinished() == false)	);
}

void StepTask::DoWork() {

	if (CanStart() == true) {

		m_StepsNeeded--;

		if (m_StepsNeeded == 0) {
			m_Finished = true;
		}

	}
	else {
		return;
	}
}

void StepTask::PrintInfo() const {
	std::cout << "Step task := ";
	Task::PrintInfo();
}

#pragma once
#include "Task.h"


class StepTask
	:	public Task		//inheritance from the Task class
{

private:
	int m_StepsNeeded;

public:

	StepTask();
	StepTask(bool finished, int num, const char* id, int steps);
	~StepTask();

	bool CanStart() const override;

	void DoWork() override;

	void PrintInfo() const override;

};


#pragma once
#include "Task.h"


class DependantTask
	:	public Task
{

private:
	const Task* m_Condition;

public:

	DependantTask();
	DependantTask(bool finished, int num, const char* name, const Task& conditionTask);
	~DependantTask();

	bool CanStart() const override;

	void DoWork() override;

	void PrintInfo() const override;



};


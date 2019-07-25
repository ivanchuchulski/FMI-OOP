#pragma once


/*		Abstract class, describing a task		*/
class Task {

protected:
	bool m_Finished;
private:
	int m_TaskNum;
	char* m_Name;

protected:
	char* SetCString(const char* source = nullptr);

public:
	Task();
	Task(bool finished, int num, const char* name);
	Task(const Task& someTask);
	virtual ~Task();

	Task& operator=(const Task& someTask);

	bool IsFinished() const;

	/*_>pure virtual, have to implement in the derived class*/
	virtual bool CanStart() const = 0;

	/*_>pure virtual, have to implement in the derived class*/
	virtual void DoWork() = 0;

	/*_>virtual function, derived classes can provide better implementation*/
	virtual void PrintInfo() const;


};


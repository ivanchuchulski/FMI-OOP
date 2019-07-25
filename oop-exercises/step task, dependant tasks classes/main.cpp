#include <iostream>
#include "Task.h"
#include"StepTask.h"
#include "DependantTask.h"

void completeAll(Task* tasksArr[], int N) {

	int availableTasks = 0;

	//loop to do the work in the tasks, that can be started
	do {

		availableTasks = 0;					//nullifying for potential next loop in the do - while
		for (int i = 0; i < N; i++) {
			if (tasksArr[i]->CanStart()) {
				availableTasks++;
				tasksArr[i]->DoWork();
			}
		}

	} while (availableTasks != 0);

	//print info about the tasks that have or have not been finished
	for (int k = 0; k < N; k++)
	{
		if (tasksArr[k]->IsFinished() == true) {
			std::cout << "Finished a : ";
			tasksArr[k]->PrintInfo();
		}
		else {
			std::cout << "Not finished a : ";
			tasksArr[k]->PrintInfo();
		}
	}
}



int main() {


	Task** someTasks = new Task*[2];
	
	someTasks[0] = new StepTask(false, 123, "Opa", 2);
	someTasks[1] = new DependantTask(false, 124, "Zavisi ot Opa", *(someTasks[0]));

	completeAll(someTasks, 2);

	std::cin.get();
	return 0;
}
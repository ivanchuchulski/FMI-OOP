#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define spacingMsg std::cout << std::endl

template<typename T>
void showVector(std::vector<T>& myVec) {

	std::vector<T>::size_type j = 0;

	for (j; j != myVec.size(); ++j) {
		if (j == myVec.size() - 1) {
			std::cout << myVec[j];
			break;
		}

		std::cout << myVec[j]<< ", ";
	}
	spacingMsg;

}

int main() {


	//generating a random seed
	srand(time_t(NULL));

	/*
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int counter = 10;

	while (counter != 0) {

		num1 = rand() % 5;				// generates a number between [0, 4]
		num2 = (rand() % 5) + 1;		// generates a number between [1, 5]
		num3 = -(rand() % 5 + 1);		//random between [-5, -1]

		std::cout << num1 << ", " << num2 << ", " << num3 << std::endl;

		counter--;
	}

	std::cout << std::endl;

	std::cout << -1 % 7 << std::endl;
	*/

	std::vector<int> vec1;
	int sizeVec = 10;
	int randValue = 0;

	vec1.reserve(sizeVec);		//reserve space for 10 vec1 vectors

	int ctr = 10;
	while (ctr != 0) {
		randValue = rand() % 10;		// [0, 9]
		vec1.push_back(randValue);
		--ctr;
	}

	for (std::vector<int>::iterator i = vec1.begin(); i != vec1.end(); ++i) {
		if (i == vec1.end() - 1) {
			std::cout << *i;
			break;
		}
		std::cout << *i << ", ";
	}

	spacingMsg;

	showVector<int>(vec1);

	std::cout << vec1.size();

	//clearing the vector _> freeing up memory
	vec1.clear();
	
	spacingMsg;
	std::cin.get();
	return 0;
}
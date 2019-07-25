#include <iostream>

//typedef unsigned int size_t;
//typedef double doubleNum;

void printArrElements(int* pArr, size_t colNum) {
	/* because we CAST when we pass the array, we can work with it like :  
		pointer arythmetic and dereferencing -> 	*(pArray + rowIndex*ColumnNum + colIndex)
		 <--> 
		1d array ->									pArray[rowIndex*ColumnNum + colIndex]
	*/

	/*
	std::cout << "address of first element : " << pArr << std::endl;
	std::cout << "value of first element : " << *(pArr) << std::endl;
	std::cout << "value of first element : " << pArr[0] << std::endl;

	std::cout << "value of first element : " << pArr[0][0] << std::endl; ->wont work here
	*/

	//the element [0][2] : 
	std::cout << "address of [0][2] : " << (pArr + 1 * 1 + 1) << std::endl;
	std::cout << "value of [0][2] : " << *(pArr + 1 * 1 + 1) << std::endl;

}

void printOneDArr(int* pArr, int arrSize) {

	for (size_t k = 0; k < arrSize; k++) {
		if (k == (arrSize - 1)) {
			//for the final iteration
			std::cout << pArr[k] << std::endl;
		}
		else {
			std::cout << pArr[k] << ", ";
		}
	}

}

//1d array sorting algorithm  ?could be used for 2d array
void selectionSort(int* pArr, size_t arrSize) {
	size_t indexOfSmallest;

	std::cout << "array size : " << arrSize << std::endl << "Starting to sort : " << std::endl;

	for (size_t i = 0; i < arrSize; i++) {
		indexOfSmallest = i;
		for (size_t j = i + 1; j < arrSize; j++) {
			//comparisson to check if the next element is smaller
			if (pArr[j] < pArr[indexOfSmallest])
				indexOfSmallest = j;
		}
		if (indexOfSmallest != i)
			std::swap(pArr[i], pArr[indexOfSmallest]);

		std::cout << i << std::endl;
		//print to check array
		printOneDArr(pArr, arrSize);
	}
}

int main() {
	
	int firstArr[3][3] = { 1, 2, 3,
							4, 5, 6,
							7, 8, 9 };
	int secondArr[4] = { 3, 4, 2, 1 };

	//fancy way of typing it in the main func, need cast and dereference
	std::cout << "address of [0][0] : " << firstArr << std::endl;
	std::cout << *((int*)firstArr[0]) << std::endl;
	std::cout << firstArr[0][0] << std::endl;

//	printArrElements((int*)firstArr, 3);

	std::cout << "original array : " << std::endl;
	printOneDArr(secondArr, (unsigned int)(sizeof(secondArr) / sizeof(int)));

	selectionSort(secondArr, (unsigned int)(sizeof(secondArr) / sizeof(int)));

	std::cout << std::endl;
	system("pause");
	return 0;
}
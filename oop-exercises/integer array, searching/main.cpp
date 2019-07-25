#include <iostream>

void printArrayCheck(int* arr, size_t startIndex, size_t endIndex) {

	std::cout << "Print check : ";
	for (size_t i = startIndex; i <= endIndex; i++) {
		if (i == endIndex) {
			std::cout << arr[i] << std::endl;;
		}
		else {
			std::cout << arr[i] << ", ";
		}
	}

}

//linear search - go through all elements and compare
int linearSearch(int* pArr, size_t arrSize, int elementToFind) {

	for (size_t i = 0; i < arrSize; i++) {
		if (pArr[i] == elementToFind) {
			std::cout << "found, position : " << i << std::endl;
			return i;
		}
	}
	//element not found
	return -1;

}


//array need to be sorted
int binarySearch(int* pArr, size_t arrSize, int elementToFind) 
{
	size_t leftIndex = 0;
	size_t rightIndex = arrSize - 1;

	printArrayCheck(pArr, leftIndex, rightIndex);

	while (leftIndex <= rightIndex) {
		int middleIndex = (leftIndex + rightIndex) / 2;

		if (elementToFind == pArr[middleIndex]) {
			//element is found -> break return out
			return middleIndex;
		}
		else if (elementToFind > pArr[middleIndex]) {
			leftIndex = middleIndex + 1;
			printArrayCheck(pArr, leftIndex, rightIndex);
		}
		else {
			rightIndex = middleIndex - 1;
			printArrayCheck(pArr, leftIndex, rightIndex);
		}
	}

	//if element not found
	return -1;
}


int main() {

	int testArr1[6] = { 1, 14, 11, 4, 6, 7 };
	int testArr2[6] = { 1, 3 ,5, 7, 11, 13 };

	int foundPos1 = linearSearch(testArr1, 6, 3);

	if (foundPos1 == -1) {
		std::cout << "Element not found : " << foundPos1 << std::endl;
	}
	else {
		std::cout << "Element on position :" << foundPos1 << std::endl;
	}

	int foundPos2 = binarySearch(testArr2, 6, 3);

	if (foundPos2 == -1) {
		std::cout << "Element not found : " << foundPos2 << std::endl;
	}
	else {
		std::cout << "Element on position :" << foundPos2 << std::endl;
	}


	//if-else flow check
/*
	int a = 10;
	int counter = 0;

	if (a > 5) {
		counter++;
	}
	else if (a >= 7) {
		counter++;
	}
	else {
		counter++;
	}
	*/

	std::cout << 1 / 2 << std::endl;
	std::cout << 1 % 2 << std::endl;


	std::cout << std::endl;
	system("pause");
	return 0;
}
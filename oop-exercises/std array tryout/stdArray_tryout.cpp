#include <iostream>
#include <array>

//macro for output formatting
#define print_emptyLine std::cout << std::endl

typedef std::size_t plusInt;

template <int arrSize>
void printingLoop(std::array<int, arrSize> inputArr) {

	std::cout << "Now printing... " << std::endl;
	for (plusInt i = 0; i < inputArr.size(); i++) {
		std::cout << inputArr[i] << " ";
	}
	print_emptyLine;

}

//passing the array by reference
template <int arrSize>
void fillArray(std::array<int, arrSize> &inputArr, int valuePassed) {

	std::cout << "Setting the values..." << std::endl;
	for (plusInt i = 0; i < inputArr.size(); i++) {
		inputArr [i] = valuePassed;
	}
	print_emptyLine;

}

int main() {

	std::array<int, 10> myArr;		//defining the array
	plusInt i;
	int userValue;

	//getting user input
	std::cout << "Enter a integer to fill the array : ";
	std::cin >> userValue;
	print_emptyLine;

	fillArray<myArr.size()>(myArr, userValue);

	printingLoop<myArr.size()>(myArr);		//passing the myArr.size() method to the template

	//setting the first and last element to something
	myArr.front() = 12;
	myArr.back() = 18;

	printingLoop<myArr.size()>(myArr);

	//ending lines
	print_emptyLine;
	system("pause");
	return 0;
}
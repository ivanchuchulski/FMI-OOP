/*
	_> variants to get the address of a character in std::cout << ...

	std::cout << static_cast<void*>(&var1) << std::endl;
	std::cout << (void*)&var1 << std::endl;

	void* p_var1 = (void*)(&var1);
*/
#include <iostream>

void func1() {
	std::cout << "func1 " << std::endl;
}

void func2() {
	std::cout << "func2" << std::endl;
	func1();
}

int ascii_To_int(char sym) {

	if (sym >= '0' || sym <= '9') {
		return (sym - '0');
	}

}

int getDigitNum(int num) {
	int counter = 0;

	if (num == 0) {
		return 0;
	}

	while (num != 0) {
		counter++;
		num /= 10;
	}

	return counter;
}

char int_To_ascii(int num) {

	if (num >= 0 || num <= 9) {
		//result = char(num + '0');
		return (num + '0');
	}

}

int powerFunc(int base, int power) {

	int result = 1;

	if (power == 0) {
		return 1;
	}
	else {
		for (int i = 1; i <= power; i++) {
			result *= base;
		}
	}

	return result;
}

void int_To_ascii_array(int num, char* arr) {

	//counter for the digits
	int digitCount = getDigitNum(num);
	int ind = 0;

	for (ind = 0; ind < digitCount; ind++) {
		int digit = num % 10;
		arr[ind] = int_To_ascii(digit);
		num /= 10;
	}
	//adding the null character
	arr[ind] = '\0';

	//reversing the array

	//for loop variant
/*	for (int k = 0, m = (ind -1); k < digitCount / 2; ++k, --m) {
		//swapping the values
		char temp = arr[m];
		arr[m] = arr[k];
		arr[k] = temp;
	}*/

	//while loop variant
	int k = 0;
	int m = ind - 1;
	while (k < (digitCount) / 2) {
		std::swap(arr[k], arr[m]);
		k++;
		m--;
	}

}

void printArray(char* arr, int sizeArr) {
	//loop to print
	for (int i = 0; i < sizeArr; i++) {
		if (i == (sizeArr - 1)) {
			std::cout << arr[i] << std::endl;
			return;
		}
		else
			std::cout << arr[i] << " _ ";
	}
}
int main() {

	int var1 = 123;
	int var2 = 7;

	int& r_var1 = var1;				//reference to var1
	int* p_var1 = &(var1);			//pointer to var1

	//const T* _> the pointer cannot change the value at its address (Tconst* the same)
	const int* p1_var1 = &(var1);

	// T* const _> the pointer has a constant address, it cannot be changed to point to something else
	int* const p2_var2 = &(var1);

	int* & refTo_p_var1 = p_var1;		//reference to the pointer to var1
	const int*& refTo_p1_var1 = p1_var1;	//ref to const T* pointer
	int* const & refTo_p2_var1 = p2_var2;	//ref to T* const pointer

	*(p_var1) += 2;
	p_var1 = &(var2);
	r_var1 += 2;
	*(refTo_p_var1) += 2;

	int num1 = ascii_To_int('1');

	char sym1 = int_To_ascii(9);
	char sym2 = '9';
	char sym3 = 57;
	char sym4[4] = "\0";

	int_To_ascii_array(123, sym4);
	
	std::cout << num1 << '\n';
	std::cout << (int)sym1 << '\n';
	std::cout << sym2 << '\n';
	std::cout << sym3 << '\n';

	printArray(sym4, 4);

	std::cin.get();
	return 0;
}
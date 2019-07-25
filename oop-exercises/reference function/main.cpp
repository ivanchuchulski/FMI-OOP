/*		You should NOT return (by) a reference in a function to something, that goes out of scope:
	=> it is declared on the stack in the function,  
	=> it is declared on the heap, but is destroyed in the end of the function
*/

#include <iostream>
#define spacingMsg std::cout << std::endl
#define PrintOut(x) std::cout << x << std::endl

//the function takes a rvalue reference => 100, true, false, ...
/*int function1(int&& var) {

	int* ptr_var = &var;		//pointer to var
	int& ref_var = var;			//reference to var

	var++;

	return var;

}
*/


//_>template to capture the type and the size of the array at compile time
//template <typename T, int sizeArr>
//void incremetElements(int (&ref_Arr)[sizeArr]) {
void incrementElements(int* const & ref_Arr, int sizeArr) {

	int i = 0;
	while (i < sizeArr) {
		ref_Arr[i] += 1;
		i++;
	}

}

int main() {

	/*
	int a = 7;
	int& r_a = a;
	int b = 10;

	a = function1(100);
	b = r_a;

	PrintOut(a);
	PrintOut(r_a);
	PrintOut(b);
	*/

	const char var1 = 'a';
	const char& r_var1 = var1;

	int myArr[5] = { 1, 2, 3, 4, 5 };

	//incremetElements<int, 5>(myArr);
	incrementElements(myArr, 5);

	//reference to a constant pointer to int
	int* const & r_myArr = myArr;
//	int* const * ptr = myArr;

	*(r_myArr + 2) += 1;


	spacingMsg;
	std::cin.get();
	return 0;
}
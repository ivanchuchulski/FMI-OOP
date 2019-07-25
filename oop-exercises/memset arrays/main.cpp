/*
	void * memset ( void * ptr, int value, size_t num );
		->ptr : Pointer to the block of memory to fill.
		->value : Value to be set. The value is passed as an int, 
		but the function fills the block of memory using the unsigned char conversion 
		of this value.
		->num : Number of bytes to be set to the value.

		for 2d arrays(Type**), the ptr should be casted to Type*
*/

#include <iostream>
#include <iomanip>

int strLength (char* pArr) {

	char *pLink = pArr;

	while (*(pLink) != '\0') {
		pLink++;
	}

	//returning the length
//	std::cout << (pLink - pArr) << std::endl;
	return (pLink - pArr);

}

void printIntOneDimArray(int* pArr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		std::cout << pArr[i] << " ";
	}
	std::cout << std::endl;
}

void printCharOneDimArray(char* pArr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		std::cout << pArr[i] << " ";
	}
	std::cout << std::endl;
}

void printMatrix(int *pArr, int n) {

	std:: cout << "Your matrix: " << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(4) << pArr[i * n + j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void printWordArray(char *wordArr, int rowCount, int columnCount) {

	for (int i = 0; i < rowCount; i++) {
		//for (int j = 0; j < columnCount; j++) {
		std::cout << "(" << i << ") -> ";
		for (int j = 0; wordArr[i * columnCount + j] != '\0'; j++) {
			std::cout << "(" << j << "):" << wordArr[i * columnCount + j] << ' ';
		}
		std::cout << std::endl;
	}

}
int main() {

	int a[5];
	char b[5];

	int number1 = 19;

	std::cout << number1 << std::endl;

	int d[3][3];
	char e[3][3];

	int c[3][3] = { 1, 2, 3,
					4 , 5 ,6,
					7, 8, 9 };

	//a arryay -> 1d integer
	memset(a, 0, 20);
	printIntOneDimArray(a, 5);

	//b-array -> 1d char
	memset(b, '-', 4);				//filling with whatever signs
	memset((b + 4), '\0', 1);		//ending with terminating null, (b + 4) === b[4]
	printCharOneDimArray(b, 5);

	//d-array -> 2d int
	memset((int*)d, 0, 36);
	//memset(d, 0, 36);				//also works
	printMatrix((int*)d, 3);

	//e-array -> 2d char	
	/*
		* * \0
		* * \0
		* * \0
	*/
	//3 being the columnNum of e_arr
	for (int i = 0; i < 3; i++) {
		memset(((char*)e + i * 3), '*', 2);
		memset(((char*)e + i * 3 + 2), '\0', 1);
	}
	printWordArray((char*)e, 3, 3);


	//c-array -> 2d int
	std::cout << "Nullifying some elements on c-matrix : " << std::endl;
	memset(((int*)c + 3), 0, 8);
	printMatrix((int*)c, 3);

	std::cout << "Nullifying the whole c-matrix : " << std::endl;
	memset((int*)c, 0, 36);
	printMatrix((int*)c, 3);
 
	std::cout << std::endl;
	system("pause");
	return 0;
}
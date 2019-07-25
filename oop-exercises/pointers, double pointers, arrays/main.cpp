#include <iostream>


typedef const char spacingMessage[];
spacingMessage outMessg1 = { "		<->		" };

void myFunc(int** ptrBuffer, int rowSize, int columnSize) {

	//int* ptr1 = (int*)ptrBuffer;
	//int* pInFunc = *(ptrBuffer);

	//(ptrBuffer + 1);
	//(pInFunc + 1);

	std::cout << "Printing the matrix : \n";
	for (int i = 0; i < rowSize; i++) {
		int* rowPtr = ptrBuffer[i];
		for (int j = 0; j < columnSize; j++) {
			std::cout << *(	*(ptrBuffer + i) + j) << "\t\t";
			std::cout << *(rowPtr + j) << "  ";
		}
		std::cout << '\n';
	}

}

void PrintPositions (unsigned int rows, unsigned int cols, float ** arr) 
{

	for (unsigned i = 0; i < rows; ++i)
	{
		for (unsigned j = 0; j < cols; ++j)
		{
			std::cout << arr[i][j];
		}
		std::cout << '\n';
	}


}
int main() {

	{
		//int arr1[][2] = { {1, 2,},
		//					{3, 4 } };

		//int a[2] = { 3, 5 };
		//int b[2] = { 7, 11 };
		//int* arr2[2] = { a, b };			// array of two pointers

		//int** p1 = (int**)arr1;

		//(arr1 + 1);
		//(p1 + 1);

		//int** ptrIntBuffer_dyn = new int*[5];
		//for (int i = 0; i < 5; ++i) {
		//	ptrIntBuffer_dyn[i] = new int[2]{ i, i + 1 };
		//}

		//int* ptrIntBuffer_st = new int[2 * 4]{ 0, 1, 2, 3,
		//										4, 5, 6, 7 };

		//myFunc(ptrIntBuffer_dyn, 5, 2);

		////free memory
		//for (int k = 0; k < 5; ++k) {
		//	delete[] ptrIntBuffer_dyn[k];		//deleting each array pointed by the buffer
		//}
		//delete[] ptrIntBuffer_dyn;			//deleting the integer pointers in the  buffer

		//delete[] ptrIntBuffer_st;
	}

	const unsigned arr_size = 3;
	float positions[arr_size][arr_size] {0.0f};

	PrintPositions(arr_size, arr_size, (float **)positions);

	std::cout << std::endl;
	std::cin.get();
	return 0;
}
#include <iostream>
#include <iomanip>

void InitArray(float ** arr, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			arr[i][j] = i * j;
		}
	}

}

void PrintArray(float ** arr, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			std::cout << arr[i][j] << std::setw(4);
		}

		std::cout << '\n';
	}

	std::cout << '\n';
}

void PrintArray(int ** arr, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			std::cout << arr[i][j] << std::setw(4);
		}

		std::cout << '\n';
	}

	std::cout << '\n';
}

unsigned Factorial(int num)
{
	if (num < 0)
	{
		std::cerr << "Invalid input, no negative numbers!\n";
		return 0;
	}

	unsigned fact = 1;
	for (unsigned i = 1; i <= num; ++i)
		fact *= i;

	return fact;
}

int GCD(int a, int b)
{
	if (a == b)
		return a;
	else if (a > b)
		return GCD(a - b, b);
	else
		return GCD(a, a - b);
}



/*
	
		1 2 3
		_____
	1 |	1 2 3
	2 |	2 4 6
	3 | 3 6 9

*/
void PrintMultiplicationTable(int n)
{
	if (n < 1)
		return;

	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n] {0};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = (i + 1) * (j + 1);

	PrintArray(arr, n);

	//free memory
	for (int i = 0; i < n; i++)
		delete[] arr[i];

	delete[] arr;
}

int main() {

	{
		const size_t size_arr = 3;

		// a 3x3 matrix
		float** arr = new float*[size_arr] {};
		for (size_t i = 0; i < size_arr; ++i)
			arr[i] = new float[size_arr] {1.0f};

		InitArray(arr, size_arr);
		PrintArray(arr, size_arr);


		// freeing memory
		for (size_t i = 0; i < size_arr; ++i)
			delete[] arr[i];

		delete[] arr;
	}

	Factorial(3);
	PrintMultiplicationTable(3);






	std::cin.get();
	return 0;
}
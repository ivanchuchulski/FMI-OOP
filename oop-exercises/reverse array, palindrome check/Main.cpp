#include <iostream>
#include <cstdlib>
#include <array>
#include <cstring>
#include "Lecture1.h"

template<typename T>
void Swap(T* a, T* b)
{

	if (a != b)
	{
		T temp = *a; 
		*a = *b;
		*b = temp;
	}

}


/*
		0 1 2 3 4,		size := 5
		- - - - -
		1 3 5 7 9

		0 1 2 3,		size := 4
		- - - -
		1 3 5 7

		0 1 2 3 4 5,	len = 5, size = 6 bytes
		- - - - - -
		a b c d e \0
*/


void ReverseArray(int* arr, size_t size)
{
	if (arr == nullptr)
		return;

	for (size_t i = 0; i < size / 2; i++)
		Swap(&arr[i], &arr[size - 1 - i]);

}

void ReveseString(char* str, size_t len)
{
	if (str == nullptr)
		return;

	for (size_t i = 0; i < len / 2; i++)
		Swap(str + i, str + len - 1 - i);

}

bool IsPalindrome(const char* str, size_t len)
{
	for (size_t i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			return false;
	}

	return true;
}

int main()
{

	std::array<int, 5> a1 = { 1, 3, 5, 7, 9 };

	char* s1 = new char[6]{'a', 'b', 'c', 'b', 'a', '\0'};

	ReverseArray(a1.data(), a1.size());

	ReveseString(s1, std::strlen(s1));

	IsPalindrome(s1, std::strlen(s1));

	int arr1[] = { 1, 2, 3, 3, 5 };

	MostFrequentV1(arr1, 5);
	MostFrequentV2(arr1, 5);


	//free memory
	delete[] s1;

	std::system("pause");
	return 0;
}
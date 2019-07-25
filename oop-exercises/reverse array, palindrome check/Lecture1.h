#pragma once
#include <utility>


void MostFrequentV1(int* arr, size_t size)
{
	int most_frequest = arr[0];
	int frequency = 1;

	for (size_t i = 0; i < size; i++)
	{
		int i_freq = 0;
		for (size_t j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
				i_freq++;
		}

		if (i_freq > frequency)
		{
			frequency = i_freq;
			most_frequest = arr[i];
		}
	}
}

void MostFrequentV2(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				std::swap(arr[i], arr[j]);
		}
	}

	int most_frequent = arr[0];
	int	max_frequency = 1;
	int current = arr[0];
	int current_frequecy = 1;

	for (size_t i = 1; i < size; i++)
	{
		if (current != arr[i])
		{
			if (current_frequecy > max_frequency)
			{
				max_frequency = current_frequecy;
				most_frequent = arr[i - 1];
			}

			current = arr[i];
			current_frequecy = 0;
		}
		current_frequecy++;
	}

}

















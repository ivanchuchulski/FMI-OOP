/*

	->faculty num : 62167
	->OOP_HW2_Task2
	->compiler : Visual C++

*/
#include <iostream>
#include "Pair.h"
#include "Settings.h"


int main () {

	int zeroValue = 0;
	int firstValue = 1;
	int secondValue = 2;

	char zeroKey[] = "key0";
	char firstKey[] = "key1";
	char secondKey[] = "key2";

	{


		Pair<int> zeroPair(zeroKey, zeroValue);
		Pair<int> firstPair(firstKey, firstValue);
		Pair<int> secondPair(secondKey, secondValue);

		//initializing
		Settings<int> MySettings(5);

		MySettings.Set(zeroPair.GetKey(), zeroPair.GetValue());
		MySettings.Set(firstPair.GetKey(), firstPair.GetValue());
		MySettings.Set(secondPair.GetKey(), secondPair.GetValue());

		zeroPair.SetValue(10);
		MySettings.Set(zeroPair.GetKey(), zeroPair.GetValue());	//changing the value in the setting

		Settings<int> CousingSettings;
		CousingSettings = MySettings;

		{
			Settings<int> UncleSetings = Settings<int>(MySettings);
		}

	}



	std::cin.get();
	return 0;
}
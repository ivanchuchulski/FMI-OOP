/*
	-compiler : Visual C++
		compiled with std:c++17
*/

#include <iostream>

#include "Pair.h"
#include "Settings.h"

template<typename T>
void Print(const String& name, const T& type)
{
	std::cout << "Printing " << name << '\n' << type << '\n';
}

int main () 
{
	int value0 = 0;
	int firstValue = 1;
	int secondValue = 2;

	String key0 = "key0";
	String key1 = "key1";
	String key2 = "key2";

	Print("key0", key0);
	Print("key1", key1);
	Print("key2", key2);

	Pair<int> pair0(key0, value0);
	Pair<int> pair1(key1, firstValue);
	Pair<int> pair2(key2, secondValue);

	Print("pair0", pair0);
	Print("pair1", pair1);
	Print("pair2", pair2);

	{
		Settings<int> settings1(5);

		settings1.Set(pair0.GetKey().Data(), pair0.GetValue());
		settings1.Set(pair1.GetKey().Data(), pair1.GetValue());
		settings1.Set(pair2.GetKey().Data(), pair2.GetValue());

		Print("settings1", settings1);

		//changing the value in the settings
		pair0.SetValue(10);
		settings1.Set(pair0.GetKey().Data(), pair0.GetValue());	

		std::cout << "printing settings1\n";
		Print("settings 1", settings1);

		{
			// copy ctor
			Settings<int> settings2(settings1);
			Print("settings 2", settings2);

			settings2.Set("key0", 50);
			Print("modified settings 2", settings2);

			// copy=
			Settings<int> settings3;
			settings3 = settings1;
			Print("settings 3", settings3);

			{
				Settings<int> settings4;
				settings4.Set(pair1.GetKey().Data(), pair1.GetValue());
				settings4.Set(pair2.GetKey().Data(), pair2.GetValue());

				Print("settings 4", settings4);

				settings3 = settings4;
			}

			Print("modified settings 3", settings3);
		}

	}


	return 0;
}
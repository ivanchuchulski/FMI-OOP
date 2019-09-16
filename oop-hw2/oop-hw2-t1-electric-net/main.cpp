/*
	->faculty num : 62167
	->OOP_HW2_Task1
	->compiler : Visual C++

*/


#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

#include "ElectricDevice.h"
#include "ElectricNet.h"


void Func(const char* str)
{
	std::cout << str;
}

int main() 
{
	{
		std::cout << std::is_trivially_copyable<String>::value << '\n';
		std::cout << std::is_trivially_copyable<Vector<String>>::value << '\n';

		String str1 = "first string";
		String str2("second string");
		const String str3("third string(it's constant)");

		str1 = str2;
		str2 = "modified second string";

		const char* str3Data = str3.Data();

		std::cout << str1;
		std::cout << str2;

		Vector<int> vec1;
		Vector<int> vec2(3, 1);

		std::cout << vec1;
		std::cout << vec2;

		vec1.Clear();
		
		vec2 = vec1;

		std::cout << vec1;
		std::cout << vec2;

	//	std::exit(0);
	}

	ElectricDevice* phone1 = new ElectricDevice(4, "Samsung Galaxy");
	ElectricDevice* laptop = new ElectricDevice(40, "Lenovo Y500");
	ElectricDevice* phone2 = new ElectricDevice(2, "Huaweii P20");
	ElectricDevice* toaster = new ElectricDevice(10, "Phillips");
	ElectricDevice* smartTV = new ElectricDevice(80, "Samsung Smart");
	

	phone1->PrintDeviceInfo();
	laptop->PrintDeviceInfo();
	phone2->PrintDeviceInfo();
	toaster->PrintDeviceInfo();
	smartTV->PrintDeviceInfo();

	
	try
	{
		ElectricNet test_electricNet1 = ElectricNet(200);
	
		test_electricNet1 + *(phone1);
		test_electricNet1 + *(laptop);
		test_electricNet1 + *(phone2);
		test_electricNet1 + *(toaster);
		test_electricNet1 + *(smartTV);
	
		std::cout << "printing test_electricNet1\n";
		test_electricNet1.PrintNet();
	
		test_electricNet1.AddDevice(*phone1);
	
		std::cout << "printing test_electricNet1\n";
		test_electricNet1.PrintNet();
	
		test_electricNet1.RemoveDevice("Phillips");

		std::cout << "printing test_electricNet1\n";
		test_electricNet1.PrintNet();
	
		// doubling the power with the ++ operator
		++test_electricNet1;
	
		 std::cout << test_electricNet1[phone2->GetName().Data()];

		// raises exception
		//std::cout << test_electricNet1["alabala"];
	
		{
			ElectricNet test_electricNet2 = ElectricNet(test_electricNet1);
	
			std::cout << "printing test_electricNet2\n";
			test_electricNet2.PrintNet();
		}
	}
	catch (std::exception& exception) 
	{
		std::cout << exception.what() << '\n';
	}


	/*free heap memory*/
	delete smartTV;
	delete toaster;
	delete phone2;
	delete laptop;
	delete phone1;


	std::cin.get();
	return 0;
}
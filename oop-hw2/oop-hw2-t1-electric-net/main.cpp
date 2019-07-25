/*
	->faculty num : 62167
	->OOP_HW2_Task1
	->compiler : Visual C++

*/


#include <iostream>
#include "ElectricDevice.h"
#include "ElectricNet.h"




int main() {


	ElectricDevice* phone1 = new ElectricDevice(4, "Samsung Galaxy");
	ElectricDevice* laptop = new ElectricDevice(40, "Lenovo Y500");
	ElectricDevice* phone2 = new ElectricDevice(2, "Huaweii P20");
	ElectricDevice* toaster = new ElectricDevice(10, "Phillips");
	ElectricDevice* smartTV = new ElectricDevice(80, "Samsung Smart");
	

	phone1->PrintDeviceInfo();

	{
		ElectricNet someElectricNet = ElectricNet(200);


		someElectricNet + *(phone1);
		someElectricNet + *(laptop);
		someElectricNet + *(phone2);
		someElectricNet + *(toaster);
		someElectricNet + *(smartTV);

		someElectricNet.PrintNet();

		someElectricNet.AddDevice(*phone1);

		someElectricNet.RemoveDevice("Phillips");
		someElectricNet.PrintNet();

		//doubling the power with the ++ operator
		++someElectricNet;

		try 
		{

			std::cout << someElectricNet[phone2->getName()];
			//std::cout << someElectricNet["alabala"];

		}
		catch (std::exception& someExcept) 
		//catch (std::out_of_range& someExcept) if we know that the exception is out_of_range specificly
		{
			//printing what the error whas with the what() method
			std::cout << "Error with the [] operator : " << someExcept.what() << '\n';
		}

		ElectricNet anotherNet = ElectricNet(someElectricNet);

		anotherNet.PrintNet();


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
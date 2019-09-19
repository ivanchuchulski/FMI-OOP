/*

	->faculty num : 62167
	->OOP_HW2_Task2
	->compiler : Visual C++

*/

#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

int main() 
{
	{
		Truck tr1 = Truck(Red, 2008, 300000, "Man", "M1", 25);
		Car car1 = Car(White, 2005, 200000, "VW", "Golf5");
		Motorcycle m1 = Motorcycle(Black, 2003, 70000, "Yamaha", "YZ1", Racing);

		std::cout << "tr1\n";
		tr1.Details();

		{
			// copy ctor
			Truck tr2(tr1);
			std::cout << "tr2\n";
			tr2.Details();

			tr2.SetColor(VehicleColor::Blue);
			tr2.SetModel("M5");

			std::cout << "modified tr2\n";
			tr2.Details();

			// default ctor
			Truck tr3;

			std::cout << "default tr3\n";
			tr3.Details();

			// copy=
			tr3 = tr1;
			std::cout << "modified tr3\n";
			tr3.Details();
		}
		
		std::cout << "car1\n";
		car1.Details();

		car1.SetColor(VehicleColor::Green);
		car1.SetMilege(car1.GetMilege() + 50000);

		std::cout << "modified car1\n";
		car1.Details();

		m1.Details();

	}



	return 0;
}

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

int main() {


	Car car1 = Car(White, 2005, 200000, "VW", "Golf5");
	Truck tr1 = Truck(Red, 2008, 300000, "Man", "M1", 25);
	Motorcycle m1 = Motorcycle(Black, 2003, 70000, "Yamaha", "YZ1", Racing);


	car1.Details(std::cout);

	tr1.Details(std::cout);

	m1.Details(std::cout);

	car1.SetColor(Color::Green);
	car1.SetMilege(car1.GetMilege() + 50000);

	car1.Details(std::cout);

//	std::cin.get();
	return 0;
}
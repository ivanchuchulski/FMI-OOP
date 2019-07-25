#include "Car.h"

Car::Car()
		//calling the default constructor in the base class
	:	Vehicle()
{}

Car::Car(const Color paint, const int year, const int milege, const char* marque, const char* model)
		//base constructor with arguments
	:	Vehicle(paint, year, milege, marque, model)
{}


Car::Car(const Car & someCar)
		//calling the copy constructor of base class
	:	Vehicle(someCar)
{}

Car::~Car()
{}

Car& Car::operator=(const Car& someCar)
{
	if (this != &(someCar)) {
		//calling the operator= of Vehicle
		Vehicle::operator=(someCar);
	}

	return *this;		// TODO: insert return statement here
}


std::ostream& operator<<(std::ostream& outStream, const Car& someCar)
{
	const Vehicle& refToVeh = someCar;

	outStream << "Car details : \n";
	outStream << refToVeh;

	return outStream;		// TODO: insert return statement here
}

std::ostream& Car::Details(std::ostream& outStream) const
{
	outStream << *(this);

	return outStream;		// TODO: insert return statement here

}
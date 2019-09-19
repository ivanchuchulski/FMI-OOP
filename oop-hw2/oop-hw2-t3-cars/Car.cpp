#include "Car.h"

Car::Car()
		//calling the default constructor in the base class
	:	Vehicle()
{}

Car::Car(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model)
	: Vehicle(paint, productionYear, mileage, maker, model)
{}


Car::Car(const Car & someCar)
	:	Vehicle(someCar)
{}

Car::~Car()
{}

Car& Car::operator=(const Car& other)
{
	if (this != &other) 
	{
		Vehicle::operator=(static_cast<const Vehicle&>(other));
	}

	return *this;
}


// virtual override methods
void Car::Details() const
{
	std::cout << *this << '\n';
}

// friend methods
std::ostream& operator<<(std::ostream& outStream, const Car& car)
{
	outStream << "Car details :\n";
	outStream << static_cast<const Vehicle&>(car) << '\n';

	return outStream;
}
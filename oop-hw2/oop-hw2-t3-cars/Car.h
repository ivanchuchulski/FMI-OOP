#pragma once
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"


class Car
	: public Vehicle
{

public:
	/*constructors*/
	Car();
	Car(const Color paint, const int year, const int milege, const char* marque, const char* model);
	Car(const Car& someCar);

	/*destructor*/
	~Car();

	/*copy assignment*/
	Car& operator=(const Car& someCar);

	friend std::ostream& operator<<(std::ostream& outStream, const Car& someCar);

	/*overriding the virtual method in the base class*/
	std::ostream& Details(std::ostream& outStream) const override;

};

#endif // !CAR_H


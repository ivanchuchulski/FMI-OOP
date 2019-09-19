#pragma once

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car
	: public Vehicle
{
public:
	Car();
	Car(const Car& other);
	Car(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model);

	~Car();

	Car& operator=(const Car& other);

	// virtual override methods
	virtual void Details() const override;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Car& someCar);
};

#endif // !CAR_H


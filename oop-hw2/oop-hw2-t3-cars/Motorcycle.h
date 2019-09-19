#pragma once

#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

enum BikeType 
{
	UndefinedBike = 0,
	Chopper = 1,
	Cruiser = 2,
	DirtBike = 3,
	Touring = 4,
	Racing = 5
};

class Motorcycle 
	: public Vehicle
{
public:
	Motorcycle();
	Motorcycle(const Motorcycle& someMotor);
	Motorcycle(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model, const BikeType type);

	~Motorcycle();

	Motorcycle& operator=(const Motorcycle& other);

	//setters
	void SetBikeType(const BikeType bikeType);

	//getters
	int GetBikeType() const;

	// virtual override methods
	virtual void Details() const override;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Motorcycle& other);

private:
	static const BikeType M_BIKE_TYPE_DEFAULT;

private:
	BikeType m_bikeType;
};

#endif // !MOTORCYCLE_H
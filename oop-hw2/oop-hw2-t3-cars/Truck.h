#pragma once

#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck
	:	public Vehicle
{

public:
	Truck();
	Truck(const Truck& other);
	Truck(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model, const unsigned truckLength);

	~Truck();

	Truck& operator=(const Truck& other);

	// setters
	void SetTruckLength(const int truckLength);

	//getters
	int GetTruckLength() const;

	// virtual override methods
	virtual void Details() const override;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Truck& TruckObj);

private:
	static const int SIZE_DEFAULT;

private:
	int m_truckLength;		// lenght of the truck in meters

};

#endif // !TRUCK_H
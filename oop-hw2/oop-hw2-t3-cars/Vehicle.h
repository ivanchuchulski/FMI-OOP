#pragma once

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

#include "String.h"

// enum, representing the color of the vehicle
enum VehicleColor 
{
	Unpainted = 0,
	Red = 1,
	Green = 2,
	Blue = 3,
	White = 4,
	Black = 5
};

class Vehicle 
{
public:
	Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model);

	~Vehicle();
	
	Vehicle& operator=(const Vehicle& other);
	
	// setters
	void SetColor(const VehicleColor paint);
	void SetYear(const int year);
	void SetMilege(const int milege);
	void SetMaker(const String& maker);
	void SetModel(const String& model);

	// setters
	int GetColor() const;
	int GetYear() const;
	int GetMilege() const;
	const String GetMaker() const;
	const String GetModel() const;

	// virtual methods
	virtual void Details() const;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Vehicle& vehicle);

private:
	static const VehicleColor M_PAINT_DEFAULT;
	static const int YEAR_DEFAULT;
	static const int MILEGE_DEFUALT;
	static const String M_MAKER_DEFAULT;
	static const String MODEL_DEFUALT;

private:
	VehicleColor m_vehicleColor;
	unsigned int m_productionYear;
	unsigned int m_mileage;
	String m_maker;
	String m_model;
};

#endif // !VEHICLE_H




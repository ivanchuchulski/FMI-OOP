#pragma once

#ifndef ELECTRIC_NET_H
#define ELECTRIC_NET_H

#include <stdexcept>			//header for using exceptions in the [] operator

#include "String.h"
#include "Vector.h"
#include "ElectricDevice.h"	

class ElectricNet 
{
public:
	ElectricNet();
	ElectricNet(int power);
	ElectricNet(const ElectricNet& someNet);

	~ElectricNet();

	ElectricNet& operator=(const ElectricNet& someNet);

	bool Empty() const;
	int NumberOfConnectedDevices() const;

	void PrintNet() const;

	void AddDevice(const ElectricDevice& deviceToAdd);
	void RemoveDevice(const String& deviceName);

	void IncreaseMaxPowerCapacity();
	void ReduceMaxPowerCapacity();

	// adds a device to the network
	ElectricNet& operator+(const ElectricDevice& deviceToAdd);
	void operator+=(const ElectricDevice& deviceToAdd);

	// removes a device from the network
	ElectricNet& operator-(const ElectricDevice& deviceToRemove);
	void operator-=(const ElectricDevice& deviceToRemove);

	// access a device by its name
	ElectricDevice& operator[](const char* nameToFind);
	const ElectricDevice& operator[](const char* nameToFind) const;

	// checks if there are any connected devices in the net
	bool operator!() const;

	// prefix ++ that doubles the max power
	void operator++();

	// prefix -- that divides the max power by half, if it is possible
	void operator--();

protected:
	int FindByName(const String& deviceName) const;

private:
	const int M_POWER_BY_DEFAULT = 500;

private:
	int m_maxPower;							//maximum power of the electric net, an integer in kiloWats
	int m_activePower;						//current power of the electric net, an integer in kiloWats
	Vector<ElectricDevice> m_devices;
};
#endif // !ELECTRIC_NET_H
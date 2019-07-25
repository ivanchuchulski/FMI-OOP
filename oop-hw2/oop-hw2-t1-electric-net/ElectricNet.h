#pragma once

#ifndef ELECTRIC_NET_H
#define ELECTRIC_NET_H

#include "ElectricDevice.h"	
#include <stdexcept>			//header for using exceptions in the [] operator


class ElectricNet {

/*constants for ElectricNet class*/
private:
	const int POWER_BY_DEFAULT = 500;
	const int SIZE_BY_DEFAULT = 5;

/*data members*/
private:
	int m_MaxPower;			//maximum power of the electric net, an integer in kiloWats
	int m_ActivePower;		//current power of the electric net, an integer in kiloWats

	int m_MaxNetSize;
	int m_ConnectedCount;		//the current size of the array
	ElectricDevice* m_DeviceNet;

	/*helper methods*/
protected:
	void ExpandNet();
	int FindByName(const char* deviceName) const;
	ElectricDevice* MakeDeviceNet(const ElectricDevice* sourceNet, int maxSize_source, int curentSize_source);

public:
	/*constructors*/
	ElectricNet();
	ElectricNet(int power);
	ElectricNet(const ElectricNet& someNet);

	/*destructor*/
	~ElectricNet();

	/*copy assigment operator*/
	ElectricNet& operator=(const ElectricNet& someNet);

	void PrintNet() const;

	void AddDevice(const ElectricDevice& DeviceToAdd);
	void RemoveDevice(const char* DeviceName);

	ElectricNet& operator+(const ElectricDevice& DeviceToAdd);
	void operator+=(const ElectricDevice& DeviceToAdd);

	ElectricNet& operator-(const ElectricDevice& DeviceToRemove);
	void operator-=(const ElectricDevice& DeviceToRemove);

	/*checks if there are any connected devices in the net*/
	bool operator!() const;

	/*prefix ++ that doubles the max power*/
	void operator++();

	/*prefix -- that divides the max power by half, if it is possible*/
	void operator--();

	/*throws exception if there is no EectriclDevice with nameToFind*/
	ElectricDevice& operator[](const char* nameToFind) const;



};


#endif // !ELECTRIC_NET_H






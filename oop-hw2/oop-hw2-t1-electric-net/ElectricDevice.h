#pragma once

#ifndef ELECTRIC_DEVICE_H
#define ELECTRIC_DEVICE_H

#include <iostream>

#include "String.h"

class ElectricDevice 
{
public:
	ElectricDevice();
	ElectricDevice(int devicePower, const char* deviceName);
	ElectricDevice(const ElectricDevice& someDevice);

	~ElectricDevice();

	ElectricDevice& operator=(const ElectricDevice& someDevice);

	void SetPower(const int devicePower);
	void SetName(const String& deviceName);

	int GetPower() const;
	String GetName() const;

	void PrintDeviceInfo() const;

	friend std::ostream& operator<<(std::ostream& outStream, const ElectricDevice& electricDevice);

private:
	const int M_LENGTH_DEFAULT = 7;
	const char* NAME_DEFAULT = "Unknown";
	const int M_DEVICE_POWER_DEFAULT = 0;

private:
	int m_devicePower;		//power in kiloWatts, consumed by the device
	String m_deviceName;
};

#endif // !ELECTRIC_DEVICE_H
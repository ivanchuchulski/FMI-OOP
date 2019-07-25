#pragma once

#ifndef ELECTRIC_DEVICE_H
#define ELECTRIC_DEVICE_H

#include <iostream>


class ElectricDevice {

/*constants for class ElectricDevice*/
private:
	const char NAME_DEFAULT[8] = "Unknown";
	const int LENGTH_DEFAULT = 7;
	const int MAX_POWER_DEFAULT = 0;

/*data members*/
private:
	int m_Power;		//power in kiloWatts, consumed by the device
	char* m_Name;

protected:
	/*helper method do set a c-style null-terminated string*/
	char* MakeCString(const char* source = nullptr);

public:
	/*constructors*/
	ElectricDevice();
	ElectricDevice(int power, const char* name);
	ElectricDevice(const ElectricDevice& someDevice);

	/*destructor*/
	~ElectricDevice();

	/*copy assigment operator*/
	ElectricDevice& operator=(const ElectricDevice& someDevice);

	/*setters*/
	void setPower(int power);
	void setName(const char* name);

	/*getters*/
	int getPower() const;
	const char* getName() const;

	void PrintDeviceInfo() const;

	friend std::ostream& operator<<(std::ostream& outStream, const ElectricDevice& Device);

};



#endif // !ELECTRIC_DEVICE_H
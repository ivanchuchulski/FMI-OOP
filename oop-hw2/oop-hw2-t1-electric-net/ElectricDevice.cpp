#include "ElectricDevice.h"

#include <string.h>


ElectricDevice::ElectricDevice()
	:	m_devicePower(M_DEVICE_POWER_DEFAULT),
		m_deviceName()
{}

ElectricDevice::ElectricDevice(int devicePower, const char* deviceName)
	:	m_devicePower((devicePower > 0) ? devicePower : M_DEVICE_POWER_DEFAULT),
		m_deviceName(deviceName)
{}

ElectricDevice::ElectricDevice(const ElectricDevice& someDevice)
	:	m_devicePower(someDevice.m_devicePower),
		m_deviceName(someDevice.m_deviceName)
{}

ElectricDevice::~ElectricDevice() 
{}

ElectricDevice & ElectricDevice::operator=(const ElectricDevice & someDevice) 
{
	if (this != &someDevice) 
	{
		m_devicePower = someDevice.m_devicePower;
		m_deviceName = someDevice.m_deviceName;
	}

	return *this;
}

void ElectricDevice::SetPower(const int devicePower) 
{
	m_devicePower = ((devicePower > 0) ? devicePower : M_DEVICE_POWER_DEFAULT);
}

void ElectricDevice::SetName(const String& deviceName) 
{
	m_deviceName = deviceName;
}

int ElectricDevice::GetPower() const 
{
	return m_devicePower;
}

String ElectricDevice::GetName() const 
{
	return m_deviceName;
}

std::ostream& operator<<(std::ostream& outStream, const ElectricDevice& electricDevice) 
{
	outStream << "\tdevice details : power : " << electricDevice.m_devicePower << "kW, name : " << electricDevice.m_deviceName << '\n';

	return outStream;
}

void ElectricDevice::PrintDeviceInfo() const 
{

	std::cout << *(this);
}
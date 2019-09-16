#include "ElectricNet.h"

#include <iostream>
#include <cstring>


ElectricNet::ElectricNet()
	:	m_maxPower(M_POWER_BY_DEFAULT),
		m_activePower(0),
		m_devices()
{}

ElectricNet::ElectricNet(int max_power)
	:	m_maxPower((max_power > 0) ? max_power : M_POWER_BY_DEFAULT),
		m_activePower(0),
		m_devices()
{}

ElectricNet::ElectricNet(const ElectricNet& other)
	:	m_maxPower(other.m_maxPower),
		m_activePower(other.m_activePower),
		m_devices(other.m_devices)
{}

ElectricNet::~ElectricNet() 
{}

ElectricNet& ElectricNet::operator=(const ElectricNet& other) 
{
	if (this != &other) 
	{
		m_maxPower = other.m_maxPower;
		m_activePower = other.m_activePower;
		m_devices = other.m_devices;
	}

	return *this;
}

int ElectricNet::FindByName(const String& deviceName) const
{
	if (deviceName.Empty())
		return -1;

	for (int i = 0; i < NumberOfConnectedDevices(); i++)
	{
		if (m_devices[i].GetName() == deviceName)
		{
			return i;
		}
	}

	return -1;
}

bool ElectricNet::Empty() const
{
	return m_devices.Empty();
}

int ElectricNet::NumberOfConnectedDevices() const
{
	return m_devices.Size();
}

void ElectricNet::PrintNet() const
{
	if (Empty())
	{
		std::cout << "empty net, nothing to print\n";
		return;
	}

	std::cout << "printing an electric net... \n";
	for (int i = 0; i < NumberOfConnectedDevices(); i++) 
	{
		std::cout << m_devices[i];
	}
}

void ElectricNet::AddDevice(const ElectricDevice& deviceToAdd) 
{
	if ((deviceToAdd.GetPower() + m_activePower) > m_maxPower) 
	{
		std::cout << "error : not enough power, can't add device";
		return;
	}

	m_activePower += deviceToAdd.GetPower();
	m_devices.PushBack(deviceToAdd);
}

void ElectricNet::RemoveDevice(const String& deviceName) 
{
	if (Empty()) 
	{
		std::cout << "error : electric net is empty, no devices to remove";
		return;
	}

	int foundIndex = FindByName(deviceName);

	if (foundIndex == -1) 
	{
		std::cout << "error : no such device name found";
		return;
	}

	std::cout << "removing a device from the net...\n";

	//subtract the power
	m_activePower -= m_devices[foundIndex].GetPower();

	m_devices.Erase(foundIndex);
}

void ElectricNet::IncreaseMaxPowerCapacity()
{
	m_maxPower *= 2;

	std::cout << "|max power doubled|\n";
}

void ElectricNet::ReduceMaxPowerCapacity()
{
	int reducedPower = m_maxPower / 2;

	if (reducedPower < m_activePower)
	{
		std::cout << "error : not enough max power, can't reduce the max power\n";
		return;
	}

	m_maxPower = reducedPower;

	std::cout << "|max power reduced by half|\n";
}

ElectricNet& ElectricNet::operator+(const ElectricDevice& DeviceToAdd) 
{
	AddDevice(DeviceToAdd);

	return *this;
}

void ElectricNet::operator+=(const ElectricDevice& DeviceToAdd) 
{
	AddDevice(DeviceToAdd);
}

ElectricNet& ElectricNet::operator-(const ElectricDevice& DeviceToRemove) 
{
	RemoveDevice(DeviceToRemove.GetName());

	return *this;
}

void ElectricNet::operator-=(const ElectricDevice & DeviceToRemove) 
{
	RemoveDevice(DeviceToRemove.GetName());
}

ElectricDevice& ElectricNet::operator[](const char* nameToFind)
{
	int nameIndex = FindByName(nameToFind);

	if (nameIndex < 0 || nameIndex >= NumberOfConnectedDevices())
		throw std::out_of_range("error : index is out of range\n");

	return m_devices[nameIndex];
}

const ElectricDevice& ElectricNet::operator[](const char* nameToFind) const 
{
	int nameIndex = FindByName(nameToFind);

	if (nameIndex < 0 || nameIndex >= NumberOfConnectedDevices())
		throw std::out_of_range("error : index is out of range\n");

	return m_devices[nameIndex];
}
bool ElectricNet::operator!() const
{
	return NumberOfConnectedDevices() == 0;
}

void ElectricNet::operator++()
{
	IncreaseMaxPowerCapacity();
}

void ElectricNet::operator--()
{
	ReduceMaxPowerCapacity();
}
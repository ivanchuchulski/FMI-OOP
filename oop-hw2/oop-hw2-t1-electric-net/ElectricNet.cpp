#include "ElectricNet.h"
#include <iostream>
#include <string.h>

/*		class ElectricNet methods definition		*/
#pragma region


ElectricDevice* ElectricNet::MakeDeviceNet(const ElectricDevice* sourceNet, int maxSize_source, int curentSize_source) {

	ElectricDevice* NetToBuild = nullptr;

	if (sourceNet != nullptr) {
		//allocate the array
		NetToBuild = new ElectricDevice[maxSize_source];

		//loop to copy, it will be triggered if the current size > 0
		for (int i = 0; i < curentSize_source; i++) {
			NetToBuild[i] = sourceNet[i];
		}

		return NetToBuild;
	}

	else {
		NetToBuild = new ElectricDevice[maxSize_source];
		return NetToBuild;
	}

}

void ElectricNet::ExpandNet() {
	const int expansionSize = m_MaxNetSize + 5;

	ElectricDevice* ExpandedNet = new ElectricDevice[expansionSize];

	for (int i = 0; i < m_ConnectedCount; i++) {
		ExpandedNet[i] = m_DeviceNet[i];
	}


	//free current memory
	if (m_DeviceNet != nullptr) {
		delete[] m_DeviceNet;
	}

	//set up the new net
	m_MaxNetSize = expansionSize;
	m_DeviceNet = ExpandedNet;
}

int ElectricNet::FindByName(const char* deviceName) const {

	if (deviceName == nullptr) { return -1; }

	for (int i = 0; i < m_ConnectedCount; i++) {
		if (strcmp(m_DeviceNet[i].getName(), deviceName) == 0) {
			return i;
		}
	}

	//if the loop has exited, then there is no such device with that name
	return -1;
}

/*defualt constructor*/
ElectricNet::ElectricNet()
	:	m_MaxPower(POWER_BY_DEFAULT),
		m_ActivePower(0),
		m_MaxNetSize(SIZE_BY_DEFAULT),
		m_ConnectedCount(0),
		m_DeviceNet(nullptr)
{
	m_DeviceNet = MakeDeviceNet(nullptr, m_MaxNetSize, m_ConnectedCount);
	//m_DeviceNet = new ElectricDevice[m_MaxNetSize];
}

/*constructor with parameters*/
ElectricNet::ElectricNet(int max_power)
	:	m_MaxPower((max_power > 0) ? max_power : POWER_BY_DEFAULT),		//using ternary operator to set the power
		m_ActivePower(0),
		m_MaxNetSize(SIZE_BY_DEFAULT),
		m_ConnectedCount(0),
		m_DeviceNet(nullptr)
{
	m_DeviceNet = MakeDeviceNet(nullptr, m_MaxNetSize, m_ConnectedCount);
	//m_DeviceNet = new ElectricDevice[m_MaxNetSize];
}

/*copy constructor*/
ElectricNet::ElectricNet(const ElectricNet& someNet)
	:	m_MaxPower(someNet.m_MaxPower),
		m_ActivePower(someNet.m_ActivePower),
		m_MaxNetSize(someNet.m_MaxNetSize),
		m_ConnectedCount(someNet.m_ConnectedCount),
		m_DeviceNet(nullptr)
{
	m_DeviceNet = MakeDeviceNet(someNet.m_DeviceNet, someNet.m_MaxNetSize, someNet.m_ConnectedCount);
	////allocate the array
	//m_DeviceNet = new ElectricDevice[m_MaxNetSize];
	////copy only the connected ones
	//for (int i = 0; i < m_ConnectedCount; i++) {		
	//	m_DeviceNet[i] = someNet.m_DeviceNet[i];
	//}
}

/*destructor*/
ElectricNet::~ElectricNet() {
	if (m_DeviceNet != nullptr) {
		delete[] m_DeviceNet;
	}
}

/*copy assignment*/
ElectricNet& ElectricNet::operator=(const ElectricNet& someNet) {
	if (this != &(someNet)) {
		//free current memory
		if (m_DeviceNet != nullptr) {
			delete[] m_DeviceNet;
		}

		//copy new data
		m_MaxPower = someNet.m_MaxPower;
		m_ActivePower = someNet.m_ActivePower;
		m_MaxNetSize = someNet.m_MaxNetSize;
		m_ConnectedCount = someNet.m_ConnectedCount;

		m_DeviceNet = MakeDeviceNet(someNet.m_DeviceNet, someNet.m_MaxNetSize, someNet.m_ConnectedCount);

		//m_DeviceNet = new ElectricDevice[m_MaxNetSize];
		//for (int i = 0; i < m_ConnectedCount; i++) {
		//	m_DeviceNet[i] = someNet.m_DeviceNet[i];
		//}

	}

	return *this;			// TODO: insert return statement here
}


void ElectricNet::AddDevice(const ElectricDevice& DeviceToAdd) {
	if ((DeviceToAdd.getPower() + m_ActivePower) > m_MaxPower) {
		std::cout << "Cant add device, the net will overload!\n";
		return;
	}

	else {
		if (m_ConnectedCount == m_MaxNetSize) {
			ExpandNet();
			m_DeviceNet[m_ConnectedCount++] = DeviceToAdd;
			m_ActivePower += DeviceToAdd.getPower();
		}
		else {
			m_DeviceNet[m_ConnectedCount++] = DeviceToAdd;
			m_ActivePower += DeviceToAdd.getPower();
		}
	}
}

void ElectricNet::RemoveDevice(const char* deviceName) {
	if (m_ConnectedCount == 0) {
		std::cout << "No devices to remove!\n";
		return;
	}

	else {
		int foundIndex = FindByName(deviceName);

		if (foundIndex == -1) {
			std::cout << "No devices to remove!\n";
			return;
		}
		else {
			std::cout << "->Removing a device from the net...\n";

			//subtract the power
			m_ActivePower -= m_DeviceNet[foundIndex].getPower();

			//allocating new array, with the same size as the current one
			ElectricDevice* buffer = new ElectricDevice[m_MaxNetSize];

			int indForCopying = 0;
			for (int i = 0; i < m_ConnectedCount; i++) {
				if (i == foundIndex) {
					//skip copying the one that has to be removed
					continue;
				}
				else {
					buffer[indForCopying] = m_DeviceNet[i];
					indForCopying++;
				}
			}

			//free current heap memory
			delete[] m_DeviceNet;
			//assign to the newly allocated memory
			m_DeviceNet = buffer;

			/*	just shifing the elements to the left
			for (int i = foundIndex + 1; i < m_ConnectedCount; i++) {
				m_DeviceNet[i - 1] = m_DeviceNet[i];
			}
			*/

			//decrement the counter
			m_ConnectedCount--;
		}
	}
}

ElectricNet& ElectricNet::operator+(const ElectricDevice& DeviceToAdd) {
	AddDevice(DeviceToAdd);
	return *this;				// TODO: insert return statement here
}

void ElectricNet::operator+=(const ElectricDevice& DeviceToAdd) {
	AddDevice(DeviceToAdd);
}

ElectricNet& ElectricNet::operator-(const ElectricDevice& DeviceToRemove) {
	RemoveDevice(DeviceToRemove.getName());
	return *this;				// TODO: insert return statement here
}

void ElectricNet::operator-=(const ElectricDevice & DeviceToRemove) {
	RemoveDevice(DeviceToRemove.getName());
}

bool ElectricNet::operator!() const {
	return (m_ConnectedCount > 0);
}


void ElectricNet::operator++() {
	m_MaxPower *= 2;
	std::cout << "Doubled the max power!\n";
}


void ElectricNet::operator--() {
	if ((m_MaxPower / 2) > m_ActivePower) {
		m_MaxPower /= 2;
		std::cout << "Reduced the max power by half!\n";
	}
	else {
		std::cout << "Can not reduce the max power!\n";
	}
}


ElectricDevice& ElectricNet::operator[](const char * nameToFind) const {

	int foundIndex = FindByName(nameToFind);

	if (foundIndex < m_ConnectedCount && foundIndex >= 0) {
		return m_DeviceNet[foundIndex];
	}
	else {
		//std::cout << "No such device found, here is a default one :\n";
		//return ElectricDevice();	

		throw std::out_of_range("Index is out of range!\n");
	}

}


void ElectricNet::PrintNet() const {

	if (m_ConnectedCount > 0) {
		std::cout << "Printing a Net... \n";
		for (int i = 0; i < m_ConnectedCount; i++) {
			std::cout << m_DeviceNet[i];
		}
	}
	else {
		std::cout << "The Net is empty\n";
	}

}


void ElectricNet::operator!=(const ElectricNet& someNet)
{

}

#pragma endregion
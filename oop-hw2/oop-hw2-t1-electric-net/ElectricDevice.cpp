#include "ElectricDevice.h"
#include <string.h>


/*helper method to set a c-style string*/
char* ElectricDevice::MakeCString(const char* source) {

	char* bufferPtr = nullptr;

	if (source != nullptr) {
		int len = strlen(source);
		bufferPtr = new char[len + 1];
		strcpy_s(bufferPtr, len + 1, source);

		return bufferPtr;
	}
	else {
		bufferPtr = new char[LENGTH_DEFAULT + 1];
		strcpy_s(bufferPtr, LENGTH_DEFAULT + 1, NAME_DEFAULT);
		return bufferPtr;
	}

}


ElectricDevice::ElectricDevice()
	:	m_Power(MAX_POWER_DEFAULT),
		m_Name(MakeCString())
{}

ElectricDevice::ElectricDevice(int power, const char* name)
		//using ternary operator to set the power
	:	 m_Power((power > 0) ? power : MAX_POWER_DEFAULT),
		m_Name(MakeCString(name))
{}

ElectricDevice::ElectricDevice(const ElectricDevice & someDevice)
	:	m_Power(someDevice.m_Power),
		m_Name(MakeCString(someDevice.m_Name))
{}

ElectricDevice::~ElectricDevice() {
	/*free heap memory*/
	if (m_Name != nullptr) {
		delete[] m_Name;
	}
}

ElectricDevice & ElectricDevice::operator=(const ElectricDevice & someDevice) {
	if (this != &someDevice) {

		//free current resouce if needed
		if (m_Name != nullptr) {
			delete[] m_Name;
		}

		//copy new data
		m_Power = someDevice.m_Power;
		m_Name = MakeCString(someDevice.m_Name);
	}

	return *this;		// TODO: insert return statement here
}


void ElectricDevice::setPower(int power) {
	m_Power = ((power > 0) ? power : MAX_POWER_DEFAULT);
}

void ElectricDevice::setName(const char * name) {
	//free current resouce if needed
	if (m_Name != nullptr) {
		delete[] m_Name;
	}
	//copy the new one
	m_Name = MakeCString(name);
}

int ElectricDevice::getPower() const {
	return m_Power;
}

const char* ElectricDevice::getName() const {
	return m_Name;
}


std::ostream& operator<<(std::ostream & outStream, const ElectricDevice& Device) {

	outStream << "\t Device => power : " << Device.m_Power << ", name : " << Device.m_Name << '\n';

	return outStream;		// TODO: insert return statement here
}

void ElectricDevice::PrintDeviceInfo() const {

	std::cout << *(this);
}
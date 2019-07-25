#include "Vehicle.h"




/*		class Vehicle  functions definitions		*/
#pragma region

/*private helper function to set a char pointer string*/
char* Vehicle::SetCString(const char* source) {

	char* buffrerPtr = nullptr;

	if (source != nullptr) {
		int sourceLen = StrLen(source);
		buffrerPtr = new char[sourceLen + 1];
		StrCopy(buffrerPtr, sourceLen, source);
	}
	else {
		buffrerPtr = new char[8]{ "Unknown" };
		return buffrerPtr;
	}

}

/*default ctor*/
Vehicle::Vehicle()
	:	m_Year(1950),
		m_Platform(SetCString()),
		m_Fuel(SetCString()) 
{}

/*ctor with parameters*/
Vehicle::Vehicle(int year, char* platform, char* fuel)
	:	m_Year(1950),
		m_Platform(SetCString(platform)),
		m_Fuel(SetCString(fuel))
{
	//setting m_Year
	if (year > 0) {
		m_Year = year;
	}

}

/*copy ctor*/
Vehicle::Vehicle(const Vehicle& otherVehicle)
	:	m_Year(otherVehicle.m_Year),
		m_Platform(SetCString(otherVehicle.m_Platform)),
		m_Fuel(SetCString(otherVehicle.m_Fuel))
{}

/*dtor*/
Vehicle::~Vehicle() {
	//freeing heap memory
	if (m_Platform != nullptr) {
		delete[] m_Platform;
	}

	if (m_Fuel != nullptr) {
		delete[] m_Fuel;
	}
}

/*copy assignment operator*/
Vehicle& Vehicle::operator=(const Vehicle& otherVehicle) {

	if (this != &otherVehicle) {
		//free current dynamic memory
		if (m_Platform != nullptr) {
			delete[] m_Platform;
			m_Platform = nullptr;
		}
		if (m_Fuel != nullptr) {
			delete[] m_Fuel;
			m_Fuel = nullptr;
		}

		m_Year = otherVehicle.m_Year;
		m_Platform = SetCString(otherVehicle.m_Platform);
		m_Fuel = SetCString(otherVehicle.m_Fuel);
	}
	// TODO: insert return statement here
	return *this;
}

/*setters*/
void Vehicle::setYear(int year) {
	if (year > 0) {
		m_Year = year;
	}
	else {
		m_Year = 1950;
	}
}

void Vehicle::setPlatform(char* platform) {
	if (m_Platform != nullptr) {
		delete[] m_Platform;
		m_Platform = nullptr;
	}
	SetCString(platform);
}

void Vehicle::setFuel(char* fuel) {
	if (m_Fuel != nullptr) {
		delete[] m_Fuel;
		m_Fuel = nullptr;
	}
	SetCString(fuel);
}

/*getters*/
int Vehicle::getYear() const {
	return m_Year;
}

const char* Vehicle::getPlatform() const {
	return m_Platform;
}

const char* Vehicle::getFuel() const {
	return m_Fuel;
}


void Vehicle::GetInfo() const 
{}


#pragma endregion
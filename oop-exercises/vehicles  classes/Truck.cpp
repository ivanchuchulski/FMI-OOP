#include "Truck.h"


/*class Truck function definitions*/
#pragma region

/*default ctor*/
Truck::Truck()
//calling the parent class Vehicle ctor first
	:	Vehicle::Vehicle(),
		m_Load(1000),
		m_Marque(Vehicle::SetCString())
{
}

/*ctor with parameters*/
Truck::Truck(int year_truck, char* platform_truck, char* fuel_truck, int load, char* marque)
	:	Vehicle::Vehicle(year_truck, platform_truck, fuel_truck),			//calling the parent class Vehicle ctor first
		m_Load(1000),
		m_Marque(Vehicle::SetCString(marque))

{
	if (load > 0) {
		m_Load = load;
	}
}

/*copy ctor*/
Truck::Truck(const Truck& otherTruck)
	:	Vehicle::Vehicle(otherTruck),		//must call the copy ctor in the Vehicle base class
		m_Load(otherTruck.m_Load),
		m_Marque(Vehicle::SetCString(otherTruck.m_Marque))
{}


/*dtor*/
Truck::~Truck() {
	//freeing heap memory
	if (m_Marque != nullptr) {
		delete[] m_Marque;
	}
}

/*copy assignment operator*/
Truck& Truck::operator=(const Truck& otherTruck) {
	if (this != &otherTruck) {

		//call the copy= in the Vehicle base class first
		Vehicle::operator=(otherTruck);

		//then copy the data from the derived class
		if (m_Marque != nullptr) {
			delete[] m_Marque;		//free data if needed
			m_Marque = nullptr;
		}

		m_Load = otherTruck.m_Load;
		m_Marque = Vehicle::SetCString(otherTruck.m_Marque);

	}
	// TODO: insert return statement here
	return *this;
}


void Truck::GetInfo() const {
}

void Truck::ShowOff() const {
}

void Truck::setLoad(int load) {
	if(load > 0) {
		m_Load = load;
	}
}

void Truck::setMarque(char * marque) {
	if (m_Marque != nullptr) {
		delete[] m_Marque;
		m_Marque = nullptr;
	}
	m_Marque = Vehicle::SetCString(marque);

}


#pragma endregion
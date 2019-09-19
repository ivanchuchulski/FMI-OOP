#include "Truck.h"


//static members initialization
const int Truck::SIZE_DEFAULT = 20;

Truck::Truck()
	:	Vehicle(),
		m_truckLength(SIZE_DEFAULT)
{}

Truck::Truck(const Truck& other)
	: Vehicle(other),
	m_truckLength(other.m_truckLength)
{}

Truck::Truck(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model, const unsigned truckLength)
	:	Vehicle(paint, productionYear, mileage, maker, model),
		m_truckLength(truckLength)
{}

Truck::~Truck()
{}

Truck & Truck::operator=(const Truck& other)
{
	if (this != &other) 
	{
		Vehicle::operator=(static_cast<const Vehicle&>(other));

		m_truckLength = other.m_truckLength;
	}

	return *this;
}


// setters
void Truck::SetTruckLength(const int truckLength)
{
	if (truckLength > 0)
	{
		m_truckLength = truckLength;
	}
}


// getters
int Truck::GetTruckLength() const
{
	return m_truckLength;
}


// virtual methods
void Truck::Details() const
{
	std::cout << *this << '\n';
}


// friend methods
std::ostream& operator<<(std::ostream& outStream, const Truck& truck)
{
	// first calling the operator<< in the Vehicle class by a cast or by a reference to the base
	outStream << "Truck details :\n";
	outStream << static_cast<const Vehicle&>(truck) << '\n';
	outStream << "\tlenght of the truck : " << truck.m_truckLength << '\n';

	return outStream;		// TODO: insert return statement here
}

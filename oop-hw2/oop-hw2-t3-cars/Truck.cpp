#include "Truck.h"



Truck::Truck()
	:	Vehicle(),
		m_Size(SIZE_DEFAULT)
{}

Truck::Truck(const Color paint, const int year, const int milege, const char* marque, const char* model, const int size)
	:	Vehicle(paint, year, milege, marque, model),
		m_Size((size > 0) ? size: SIZE_DEFAULT)
{}

Truck::Truck(const Truck & someTruck)
	:	Vehicle(someTruck),
		m_Size(someTruck.m_Size)

{}

Truck::~Truck()
{}

Truck & Truck::operator=(const Truck & someTruck)
{
	if (this != &(someTruck)) {
		Vehicle::operator=(someTruck);

		m_Size = someTruck.m_Size;
	}

	return *this;		// TODO: insert return statement here
}


std::ostream & operator<<(std::ostream & outStream, const Truck & someTruck)
{
	const Vehicle& refToBase = someTruck;

	outStream << "Truck details : \n";

	/*calling the operator<< in the Vehicle class by a cast or by a reference to the base
	outStream << (const Vehicle&)someTruck;	
	*/	
	outStream << refToBase;

	outStream << "\tlenght of the truck : " << someTruck.m_Size << '\n';

	return outStream;		// TODO: insert return statement here
}

std::ostream & Truck::Details(std::ostream & outStream) const
{
	//calling the operator<< above
	outStream << *(this);

	return outStream;		// TODO: insert return statement here
}


void Truck::SetSize(const int size)
{
	if (size > 0) {
		m_Size = size;
	}
}

int Truck::GetSize() const
{
	return m_Size;
}
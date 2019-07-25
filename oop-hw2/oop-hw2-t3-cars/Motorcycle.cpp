#include "Motorcycle.h"

const char BikeTypes[6][14] = {
	"UndefinedBike",  "Chopper", "Cruiser", "DirtBike", "Touring", "Racing"
};

Motorcycle::Motorcycle()
	:	Vehicle()
{}


Motorcycle::Motorcycle(const Motorcycle & someMotor)
	:	Vehicle(someMotor),
		m_Type(someMotor.m_Type)
{}

Motorcycle::Motorcycle(const Color paint, const int year, const int milege, const char* marque, const char* model, const BikeType type)
	:	Vehicle(paint, year, milege, marque, model),
		m_Type(type)
{}

Motorcycle::~Motorcycle()
{}

Motorcycle & Motorcycle::operator=(const Motorcycle & someMoto)
{
	if (this != &(someMoto)) {
		Vehicle::operator=(someMoto);

		m_Type = someMoto.m_Type;
	}

	return *this;		// TODO: insert return statement here
}


std::ostream & operator<<(std::ostream & outStream, const Motorcycle & someMotor)
{
	const Vehicle& refToBase = someMotor;

	outStream << "Motorcycle details : \n";

	outStream << refToBase;
	outStream << "\tbike type : " << BikeTypes[someMotor.m_Type] << '\n';


	return outStream;		// TODO: insert return statement here
}

std::ostream & Motorcycle::Details(std::ostream & outStream) const
{
	outStream << *(this);

	return outStream;		// TODO: insert return statement here
}

void Motorcycle::SetBikeType(const BikeType type)
{
	m_Type = type;
}

int Motorcycle::GetBikeType() const
{
	
	return (int)m_Type;
}
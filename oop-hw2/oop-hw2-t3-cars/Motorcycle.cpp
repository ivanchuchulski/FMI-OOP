#include "Motorcycle.h"

// static members initialization
const BikeType Motorcycle::M_BIKE_TYPE_DEFAULT = BikeType::UndefinedBike;


Motorcycle::Motorcycle()
	:	Vehicle(),
		m_bikeType(M_BIKE_TYPE_DEFAULT)
{}

Motorcycle::Motorcycle(const Motorcycle& someMotor)
	:	Vehicle(someMotor),
		m_bikeType(someMotor.m_bikeType)
{}

Motorcycle::Motorcycle(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model, const BikeType type)
	:	Vehicle(paint, productionYear, mileage, maker, model),
		m_bikeType(type)
{}

Motorcycle::~Motorcycle()
{}

Motorcycle & Motorcycle::operator=(const Motorcycle& other)
{
	if (this != &other) 
	{
		Vehicle::operator=(static_cast<const Vehicle&>(other));

		m_bikeType = other.m_bikeType;
	}

	return *this;
}


// setters
void Motorcycle::SetBikeType(const BikeType type)
{
	m_bikeType = type;
}


//getters
int Motorcycle::GetBikeType() const
{
	return static_cast<int>(m_bikeType);
}


// virtual override methods
void Motorcycle::Details() const
{
	std::cout << *this << '\n';
}


// friend methods
std::ostream& operator<<(std::ostream& outStream, const Motorcycle& motorcycle)
{
	const String BikeTypes[] = { "UndefinedBike",  "Chopper", "Cruiser", "DirtBike", "Touring", "Racing" };

	outStream << "Motorcycle details : \n";
	outStream << static_cast<const Vehicle&>(motorcycle) << '\n';
	outStream << "\tbike type : " << BikeTypes[motorcycle.m_bikeType] << '\n';


	return outStream;
}
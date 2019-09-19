#include "Vehicle.h"
#include <string.h>

// static members initialization
const VehicleColor Vehicle::M_PAINT_DEFAULT = VehicleColor::Unpainted;
const int Vehicle::YEAR_DEFAULT = 1960;
const int Vehicle::MILEGE_DEFUALT = 10000;
const String Vehicle::M_MAKER_DEFAULT("BMW");
const String Vehicle::MODEL_DEFUALT("M3");


Vehicle::Vehicle()
	:	m_vehicleColor(M_PAINT_DEFAULT),
		m_productionYear(YEAR_DEFAULT),
		m_mileage(MILEGE_DEFUALT),
		m_maker(M_MAKER_DEFAULT),
		m_model(MODEL_DEFUALT)
{}

Vehicle::Vehicle(const Vehicle& someVehicle)
	:	m_vehicleColor(someVehicle.m_vehicleColor),
		m_productionYear(someVehicle.m_productionYear),
		m_mileage(someVehicle.m_mileage),
		m_maker(someVehicle.m_maker),
		m_model(someVehicle.m_model)
{}

Vehicle::Vehicle(const VehicleColor paint, unsigned productionYear, unsigned mileage, const String& maker, const String& model)
	:	m_vehicleColor(paint),
		m_productionYear(productionYear),
		m_mileage(mileage),
		m_maker(maker),
		m_model(model)
{}

Vehicle::~Vehicle()
{}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other) 
	{
		m_vehicleColor = other.m_vehicleColor;
		m_productionYear = other.m_productionYear;
		m_mileage = other.m_mileage;
		m_maker = other.m_maker;
		m_model = other.m_model;
	}

	return *this;
}


// setters
void Vehicle::SetColor(const VehicleColor paint) 
{ 
	m_vehicleColor = paint; 
}

void Vehicle::SetYear(const int year) 
{ 
	m_productionYear = (year > 0) ? year : -year;
}

void Vehicle::SetMilege(const int milege) 
{ 
	m_mileage = (milege > 0) ? milege : -milege; 
}

void Vehicle::SetMaker(const String& maker)
{
	m_maker = maker;
}

void Vehicle::SetModel(const String& model)
{
	m_model = model;
}


// getters
int Vehicle::GetColor() const
{
	return static_cast<int>(m_vehicleColor);
}

int Vehicle::GetYear() const
{
	return m_productionYear;
}

int Vehicle::GetMilege() const
{
	return m_mileage;
}

const String Vehicle::GetMaker() const
{
	return String(m_maker);
}

const String Vehicle::GetModel() const
{
	return String(m_model);
}


// virtual methods
void Vehicle::Details() const
{
	std::cout << *this;
}


// friend methods
std::ostream& operator<<(std::ostream& outStream, const Vehicle& vehicle)
{
	//array to print the Enum Color, the index of the first dimension of this array corresponds to the particular enum value
	const String PAINTS[] = { "Unpainted", "Red", "Green", "Blue", "White", "Black" };

	outStream << PAINTS[vehicle.m_vehicleColor] << " " << vehicle.m_maker << ' ' << vehicle.m_model << '\n';
	outStream << "\tmade in " << vehicle.m_productionYear << " with " << vehicle.m_mileage << " miles covered";

	return outStream;			// TODO: insert return statement here
}
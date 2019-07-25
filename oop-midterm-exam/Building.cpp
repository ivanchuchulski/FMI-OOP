#include "Building.h"

/*constants for the class*/
const unsigned int AREA_DEFAULT = 100;
const unsigned int STOREYS_DEFAULT = 5;




/*defualt constructor*/
Building::Building()
	:	m_Area(AREA_DEFAULT),
		m_Storeys(STOREYS_DEFAULT)
{}

/*copy ctor*/
Building::Building(const Building & someBuilding)
	:	m_Area(someBuilding.m_Area),
		m_Storeys(someBuilding.m_Storeys)
{}

/*constructor with parameters*/
Building::Building(const int area, const int storeys)
	:	m_Area((area > 0) ? area : AREA_DEFAULT),
		m_Storeys((storeys > 0) ? storeys  : STOREYS_DEFAULT)

{}

/*destructor*/
Building::~Building()
{}


Building & Building::operator=(const Building & someBuilding)
{
	if (this != &(someBuilding)) {
		m_Area = someBuilding.m_Area;
		m_Storeys = someBuilding.m_Storeys;
	}

	return *this;		// TODO: insert return statement here
}

void Building::SetArea(const int area)
{
	m_Area = (area > 0) ? area : AREA_DEFAULT;
}

void Building::SetStoreys(const int storeys)
{
	m_Storeys = (storeys > 0) ? storeys : STOREYS_DEFAULT;
}

unsigned int Building::GetArea() const
{
	return m_Area;
}

unsigned int Building::GetStoreys() const
{
	return m_Storeys;
}


unsigned int Building::GetTotalArea() const
{
	return m_Area * m_Storeys;
}

unsigned int Building::GetHeight() const
{
	const int FLOOR_HEIGHT = 4;		//default floor height in meters

	return m_Storeys * FLOOR_HEIGHT;
}

std::ostream & operator<<(std::ostream & outStr, const Building & someBuilding)
{
	outStr << "\tArea : " << someBuilding.m_Area << std::endl;
	outStr << "\tStoreys : " << someBuilding.m_Storeys << std::endl;
	outStr << "\tGetHeight() : " << someBuilding.GetHeight() << std::endl;
	outStr << "\tTotalArea() : " << someBuilding.GetTotalArea() << std::endl;

	return outStr;		// TODO: insert return statement here
}


/*returns true if the height of the left-hand side is less than the right-hand side*/
bool Building::operator<(const Building & rhsBuilding) const
{
	return (this->GetHeight() < rhsBuilding.GetHeight());
}


//friend method, which also compares Building objects, but it IS NOT INHERITED! IF, we have the same operator in the derived class??s
bool operator>(const Building & lhsBuild, const Building & rhsBuilding)
{
	return (lhsBuild.GetHeight() > rhsBuilding.GetHeight());
}


void Building::operator++()
{
	++m_Storeys;
}





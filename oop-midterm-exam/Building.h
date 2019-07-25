#pragma once

#include <ostream>		//for overloading <<


class Building {
private:
	unsigned int m_Area;		//area in m^2
	unsigned int m_Storeys;		//floors of the building

public:
	/*constructors*/
	Building();
	Building(const Building& someBuilding);
	Building(const int area, const int storeys);

	/*destructor, we mark it as virtual, because of polymorphism*/
	virtual ~Building();

	/*copy assignment*/
	Building& operator=(const Building& someBuilding);

	/*setters*/
	void SetArea(const int area);
	void SetStoreys(const int storeys);

	/*getters*/
	unsigned int GetArea() const;
	unsigned int GetStoreys() const;

	unsigned int GetTotalArea() const;

	unsigned int GetHeight() const;

	// ?? could also be defined, and no compile error, but when you call it does not build
	//friend bool operator<(const Building& lhsBuild, const Building& rhsBuilding);

	bool operator<(const Building& rhsBuilding) const;

	friend bool operator>(const Building& lhsBuild, const Building& rhsBuilding);


	/*virtual operator++ -> add a floor in the building*/
	virtual void operator++();

	/*overloading operator for output*/
	friend std::ostream& operator<<(std::ostream& outStr, const Building& someBuilding);


};



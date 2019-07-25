#pragma once


#include "Vehicle.h"

class Truck
	:	public Vehicle
{

/*constants*/
private:
	const int SIZE_DEFAULT = 20;
private:
	int m_Size;		//lenght of the truck in meters
public:
	/*constructors*/
	Truck();
	Truck(const Color paint, const int year, const int milege, const char* marque, const char* model, const int size);
	Truck(const Truck& someTruck);

	/*destructor*/
	~Truck();

	/*copy assignment*/
	Truck& operator=(const Truck& someTruck);

	void SetSize(const int size);

	int GetSize() const;

	friend std::ostream& operator<<(std::ostream& outStream, const Truck& TruckObj);

	/*overriding the virtual method in the base class*/
	std::ostream& Details(std::ostream& outStream) const override;



};


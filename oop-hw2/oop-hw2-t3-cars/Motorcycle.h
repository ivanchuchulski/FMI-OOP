#pragma once


#include "Vehicle.h"


enum BikeType {
	UndefinedBike = 0,
	Chopper = 1,
	Cruiser = 2,
	DirtBike = 3,
	Touring = 4,
	Racing = 5
};

class Motorcycle 
	: public Vehicle
{

/*constant*/
private:
	const BikeType BIKE_TYPE_DEFAULT = BikeType::Chopper;

private:
	BikeType m_Type;

public:
	/*constructors*/
	Motorcycle();
	Motorcycle(const Motorcycle& someMotor);
	Motorcycle(const Color paint, const int year, const int milege, const char* marque, const char* model, const BikeType type);

	/*destructor*/
	~Motorcycle();

	/*copy assignment*/
	Motorcycle& operator=(const Motorcycle& someMoto);

	void SetBikeType(const BikeType type);
	int GetBikeType() const;

	friend std::ostream& operator<<(std::ostream& outStream, const Motorcycle& someMotor);

	/*overriding the virtual method in the base class*/
	std::ostream& Details(std::ostream& outStream) const override;



};


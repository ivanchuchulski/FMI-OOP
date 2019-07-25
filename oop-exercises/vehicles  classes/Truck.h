#pragma once
#include "Vehicle.h"

/*		class Truck definition		*/
class Truck : public Vehicle {

private:
	int m_Load;
	char* m_Marque;

public:
	/*constructors and destructor*/
	Truck();
	Truck(int year_truck, char* platform_truck, char* fuel_truck, int load, char* marque);
	Truck(const Truck& otherTruck);
	~Truck();

	/*copy assignment*/
	Truck& operator=(const Truck& otherTruck);

	/*overring the virtual method in the base class*/
	void GetInfo() const override;

	/*the pure virtual, not really overriding it, rather providing implementation*/
	void ShowOff() const override;


	/*setters*/
	void setLoad(int load);
	void setMarque(char* marque);

	/*getters*/
	int getLoad() const;
	char* getMarque() const;

};

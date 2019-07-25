#pragma once
#include "MyStringFuncs.h"


class Vehicle {

private:

	private:int m_Year;
	private:char* m_Platform;
	private:char* m_Fuel;

protected:
	//funtion to properly set a c-string, protected, so it can be called in derived classes
	char* SetCString(const char* source = nullptr);

public:

	/*constructors and desturctor*/
	Vehicle();
	Vehicle(int year, char* platform, char* fuel);
	Vehicle(const Vehicle& otherVehicle);
	~Vehicle();

	/*copy assignment operator overload*/
	Vehicle& operator=(const Vehicle& otherVehicle);


	/*virtual function, could implement it in the derived classes*/
	virtual void GetInfo() const;

	/*pure virtual function it is neccesary to implement it in the derived classes*/
	virtual void ShowOff() const = 0;


	/*setters*/
	void setYear(int year);
	void setPlatform(char* platform);
	void setFuel(char* fuel);

	/*getters*/
	int getYear() const;
	const char* getPlatform() const;
	const char* getFuel() const;

};


#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>


/*enum, representing the color of the vehicle*/
enum Color {
	Uncolored = 0,
	Red = 1,
	Green = 2,
	Blue = 3,
	White = 4,
	Black = 5
};

/*		---class Vehicle definition---		*/
class Vehicle {

/*constants*/
private:
	const Color PAINT_DEFAULT = Color::Uncolored;
	const int YEAR_DEFAULT = 1960;
	const int MILEGE_DEFUALT = 10000;
	const char* MARQUE_DEFAULT = "BMW";
	const char* MODEL_DEFUALT = "M3";
private:
	Color m_Paint;
	int m_Year;
	int m_Milege;
	char* m_Marque;
	char* m_Model;

protected:
	char* MakeCString(const char* source);

public:
	/*constructors*/
	Vehicle();
	Vehicle(Color paint, int year, int milege, const char* marque, const char* model);
	Vehicle(const Vehicle& someVehicle);

	/*destructor*/
	~Vehicle();
	
	/*copy assignment*/
	Vehicle& operator=(const Vehicle& someVehicle);
	
	friend std::ostream& operator<<(std::ostream& outStream, const Vehicle& aVehicle);

	/*setters*/
	void SetColor(const Color paint);
	void SetYear(const int year);
	void SetMilege(const int milege);
	void SetMarque(const char* marque);
	void SetModel(const char* model);


	/*getters*/
	int GetPaint() const;
	int GetYear() const;
	int GetMilege() const;
	const char* GetMarque() const;
	const char* GetModel() const;

	/* by definition this method should do nothing	*/
	virtual std::ostream& Details(std::ostream& outStream) const ;

};

#endif // !VEHICLE_H




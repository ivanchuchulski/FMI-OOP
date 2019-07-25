#include "Vehicle.h"
#include <string.h>


//array to print the Enum Color, the index of the first dimension of this array corresponds to the particular enum value
const char Paints[6][10] = { "Uncolored", "Red", "Green", "Blue", "White", "Black" };


char * Vehicle::MakeCString(const char * source) {
	char* toMake = nullptr;

	if (source != nullptr) {
		int len = strlen(source);
		toMake = new char[len + 1];
		strcpy_s(toMake, len + 1, source);
		
		return toMake;
	}

	else {
		toMake = new char[8]{ "Unknown" };

		return toMake;
	}
}

/*default constructor*/
Vehicle::Vehicle()
	:	m_Paint(PAINT_DEFAULT),
		m_Year(YEAR_DEFAULT),
		m_Milege(MILEGE_DEFUALT),
		m_Marque(MakeCString(MARQUE_DEFAULT)),
		m_Model(MakeCString(MODEL_DEFUALT))
{}


/*constructor with params*/
Vehicle::Vehicle(Color paint, int year, int milege, const char* marque, const char* model)
	:	m_Paint(paint), 
		m_Year((year > 0) ? year : YEAR_DEFAULT),
		m_Milege((milege > 0) ? milege : MILEGE_DEFUALT),
		m_Marque(MakeCString(marque)),
		m_Model(MakeCString(model))
{}


/*copy constructor*/
Vehicle::Vehicle(const Vehicle& someVehicle)
	:	m_Paint(someVehicle.m_Paint),
		m_Year(someVehicle.m_Year),
		m_Milege(someVehicle.m_Milege),
		m_Marque(MakeCString(someVehicle.m_Marque)),
		m_Model(MakeCString(someVehicle.m_Model))
{}

Vehicle::~Vehicle()
{
	//free dynamic memory
	if (m_Marque != nullptr) {
		delete[] m_Marque;
	}

	if (m_Model != nullptr) {
		delete[] m_Model;
	}
}


Vehicle & Vehicle::operator=(const Vehicle & someVehicle)
{
	if (this != &(someVehicle)) {
		//free current memory
		if (m_Marque != nullptr) {
			delete[] m_Marque;
		}

		if (m_Model != nullptr) {
			delete[] m_Model;
		}

		//copy the new data
		m_Paint = someVehicle.m_Paint;
		m_Year = someVehicle.m_Year;
		m_Milege = someVehicle.m_Milege;
		m_Marque = MakeCString(someVehicle.m_Marque);
		m_Model = MakeCString(someVehicle.m_Model);
	}

	return *this;		// TODO: insert return statement here
}


/*setters*/
void Vehicle::SetColor(const Color paint) 
{ 
	m_Paint = paint; 
}

void Vehicle::SetYear(const int year) 
{ 
	m_Year = (year > 0) ? year : -year;
}

void Vehicle::SetMilege(const int milege) 
{ 
	m_Milege = (milege > 0) ? milege : -milege; 
}

void Vehicle::SetMarque(const char * marque) 
{
	if (m_Marque != nullptr) {
		delete[] m_Marque;
	}
	m_Marque = MakeCString(marque);
}


void Vehicle::SetModel(const char * model) 
{
	if (m_Model != nullptr) {
		delete[] m_Model;
	}

	m_Model = MakeCString(model);
}

/*getters*/
int Vehicle::GetPaint() const
{
	return (int)m_Paint;
}

int Vehicle::GetYear() const
{
	return m_Year;
}

int Vehicle::GetMilege() const
{
	return m_Milege;
}

const char * Vehicle::GetMarque() const
{
	return m_Marque;
}

const char * Vehicle::GetModel() const
{
	return m_Model;
}

//void Vehicle::Details() const
//{
//	std::cout << *(this);
//}


std::ostream & operator<<(std::ostream & outStream, const Vehicle & someVehicle)
{

	outStream << '\t';

	if (someVehicle.m_Marque == nullptr || someVehicle.m_Model == nullptr) 
	{
		outStream << Paints[someVehicle.m_Paint] << ", ";
		outStream << someVehicle.m_Year << ", ";
		outStream << someVehicle.m_Milege << ", ";
		outStream << "no marque, no model\n";
	}

	else 
	{
		outStream << Paints[someVehicle.m_Paint] << ", ";
		outStream << someVehicle.m_Year << ", ";
		outStream << someVehicle.m_Milege << ", ";
		outStream << someVehicle.m_Marque << ", ";
		outStream << someVehicle.m_Model << '\n';
	}

	return outStream;			// TODO: insert return statement here
}


std::ostream & Vehicle::Details(std::ostream & outStream) const
{
	//calling the operator<< above
	//outStream << *(this);

	return outStream;		 // TODO: insert return statement here
}
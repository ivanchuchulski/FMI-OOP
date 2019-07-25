#include "Block.h"
#include <string.h>		//to use strcpy_s(), strlen()

/*constants*/
const char* ADDRESS_DEFAULT = "No Address";
const int LEN_OF_DEFAULT = 10;
const int APPS_DEFAULT = 15;

char * Block::MakeCStirng(const char * source)
{
	char* toMake = nullptr;

	if (source != nullptr) {
		int sLen = strlen(source);
		toMake = new char[sLen + 1];
		strcpy_s(toMake, sLen + 1, source);

		return toMake;
	}
	else {
		toMake = new char[LEN_OF_DEFAULT + 1];
		strcpy_s(toMake, LEN_OF_DEFAULT + 1, ADDRESS_DEFAULT);

		return toMake;
	}
}

/*default constructor*/
Block::Block()
	:	Building(),
		m_ApartmentsCount(APPS_DEFAULT),
		m_Address(MakeCStirng())
{}

/*copy constructor*/
Block::Block(const Block & someBlock)
	:	Building(someBlock),	
		m_ApartmentsCount(someBlock.m_ApartmentsCount),
		m_Address(MakeCStirng(someBlock.m_Address))
{}

Block::Block(const int area, const int storeys, const int apartments, const char * address)
	:	Building(area, storeys),
		m_ApartmentsCount((apartments > 0) ? apartments : APPS_DEFAULT),
		m_Address(MakeCStirng(address))
{
}

/*destructor*/
Block::~Block()
{
	if (m_Address != nullptr) {
		delete[] m_Address;
	}
}

Block & Block::operator=(const Block & someBlock)
{
	if (this != &(someBlock)) {

		//call parent operator=
		Building::operator=((const Building&)someBlock);

		//free current heap memory
		if (m_Address != nullptr) {
			delete[] m_Address;
		}

		//copy new data
		m_ApartmentsCount = someBlock.m_ApartmentsCount;
		m_Address = MakeCStirng(someBlock.m_Address);
	}

	return *this;		// TODO: insert return statement here
}


void Block::SetApartments(const int apartments)
{
	m_ApartmentsCount = (apartments > 0) ? apartments : APPS_DEFAULT;
}

void Block::SetAddress(const char * address)
{
	//free current heap memory if needed
	if (m_Address != nullptr) {
		delete[] m_Address;
	}

	m_Address = MakeCStirng(address);
}

int Block::GetApartments() const
{
	return m_ApartmentsCount;
}

const char * Block::GetAddress() const
{
	return m_Address;
}

bool Block::operator<(const Block & someBlock)
{
	return (this->m_ApartmentsCount < someBlock.m_ApartmentsCount);
}

//std::ostream & operator<<(std::ostream & outStr, const Block & someBlock)
//{
//	//creating a reference to the parent class to call the << in it
//	const Building& ref_base = someBlock;		
//
//	outStr << ref_base;
//	outStr << "apartments : " << someBlock.m_ApartmentsCount << std::endl;
//	outStr << "address : " << someBlock.m_Address << std::endl;
//
//
//	return outStr;		// TODO: insert return statement here
//}


void Block::operator++()
{
	++m_ApartmentsCount;
}







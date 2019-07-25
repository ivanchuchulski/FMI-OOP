#pragma once

#include "Building.h"

class Block
	:	public Building
{
private:
	unsigned int m_ApartmentsCount;
	char* m_Address;

protected:
	char* MakeCStirng(const char* source = nullptr);

public:
	/*constructors*/
	Block();
	Block(const Block& someBlock);
	Block(const int area, const int storeys, const int apartments, const char* address);

	/*destructor*/
	~Block();

	/*copy assignment*/
	Block& operator=(const Block& someBlock);

	/*setters*/
	void SetApartments(const int apartments);
	void SetAddress(const char* address);

	/*getters*/
	int GetApartments() const;
	const char* GetAddress() const;

	bool operator<(const Block& someBlock);

	void operator++() override;

	/*overloading operator for output*/
	//friend std::ostream& operator<<(std::ostream& outStr, const Block& someBlock);



};


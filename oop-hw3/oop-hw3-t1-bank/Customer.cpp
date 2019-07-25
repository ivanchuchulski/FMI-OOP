#include "Customer.h"


/*default ctor*/
Customer::Customer()
	:	m_ID(ID_DEFAULT),
		m_Name("no_name"),
		m_Address("no_address")
{}

/*copy ctor*/
Customer::Customer(const Customer& someCustomer)
	:	m_ID(someCustomer.m_ID),
		m_Name(someCustomer.m_Name),
		m_Address(someCustomer.m_Address)
{}

/*ctor with parameters*/
Customer::Customer(const std::string& Id, const std::string& name, const std::string& address)
	:	m_ID(Id),
		m_Name(name),
		m_Address(address)
{}

/*destructor*/
Customer::~Customer()
{
	//std::string automaticly deletes its data  
}

/*copy=*/
Customer & Customer::operator=(const Customer& someCustomer)
{
	if (this != &(someCustomer)) 
	{
		m_ID = someCustomer.m_ID;
		m_Name = someCustomer.m_Name;		//copy assignment in std::string class
		m_Address = someCustomer.m_Address;
	}

	return *this;		// TODO: insert return statement here
}


void Customer::SetID(const std::string & id)
{
	m_ID = id;
}

void Customer::SetName(const std::string & name)
{
	m_Name = name;
}

void Customer::SetAddress(const std::string & address)
{
	m_Address = address;
}



const std::string Customer::GetID() const
{
	return std::string(m_ID);
}

const std::string Customer::GetName() const
{
	return std::string(m_Name);
}

const std::string Customer::GetAddress() const
{
	return std::string(m_Address);
}

std::ostream& operator<<(std::ostream& outStr, const Customer& someCustomer)
{
	outStr << "Customer " << someCustomer.m_Name << " info : ID : "
			<< someCustomer.m_ID << ", address : " << someCustomer.m_Address << '\n';
 

	return outStr;		// TODO: insert return statement here
}

void Customer::Display() const
{
	std::cout << (*this);
}


Customer * Customer::CloneCustomer() const
{
	return new Customer(*(this));
}
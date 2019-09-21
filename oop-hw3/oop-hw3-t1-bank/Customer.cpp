#include "Customer.h"

//static members initialization
const std::string Customer::M_ID_DEFAULT= "#001";

//Customer::Customer()
//	:	m_id(M_ID_DEFAULT),
//		m_name("no_name"),
//		m_address("no_address")
//{}
//
//Customer::Customer(const Customer& someCustomer)
//	:	m_id(someCustomer.m_id),
//		m_name(someCustomer.m_name),
//		m_address(someCustomer.m_address)
//{}

Customer::Customer(const std::string& id, const std::string& name, const std::string& address)
	:	m_id(id),
		m_name(name),
		m_address(address)
{}

//Customer::~Customer()
//{}
//
//Customer & Customer::operator=(const Customer& someCustomer)
//{
//	if (this != &someCustomer) 
//	{
//		m_id = someCustomer.m_id;
//		m_name = someCustomer.m_name;
//		m_address = someCustomer.m_address;
//	}
//
//	return *this;
//}


// setters
void Customer::SetID(const std::string & id)
{
	m_id = id;
}

void Customer::SetName(const std::string & name)
{
	m_name = name;
}

void Customer::SetAddress(const std::string & address)
{
	m_address = address;
}


// getters
const std::string Customer::GetID() const
{
	return std::string(m_id);
}

const std::string Customer::GetName() const
{
	return std::string(m_name);
}

const std::string Customer::GetAddress() const
{
	return std::string(m_address);
}

//Customer* Customer::CloneCustomer() const
//{
//	return new Customer(*this);
//}

void Customer::DisplayCustomerInfo() const
{
	std::cout << (*this);
}


// friend methods
std::ostream& operator<<(std::ostream& outStream, const Customer& customer)
{
	outStream << "Customer " << customer.m_name << " info : ID : "
		<< customer.m_id << ", address : " << customer.m_address << '\n';


	return outStream;
}
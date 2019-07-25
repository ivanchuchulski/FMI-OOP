#pragma once

#include <iostream>
#include <string>


class Customer {

private:
	const char ID_DEFAULT[5] = "#001";

private:
	std::string m_ID;
	std::string m_Name;
	std::string m_Address;
	//std::vector<Account*> m_Accounts;

public:
	/*constructos*/
	Customer();
	Customer(const Customer& someCustomer);
	Customer(const std::string& Id, const std::string& name, const std::string& address);

	/*destructor*/
	~Customer();

	/*copy assignment*/
	Customer& operator=(const Customer& someCustomer);

	void SetID(const std::string& id);
	void SetName(const std::string& name);
	void SetAddress(const std::string& address);


	const std::string GetID() const;
	const std::string GetName() const;
	const std::string GetAddress() const;


	friend std::ostream& operator<<(std::ostream& outStr, const Customer& someCustomer);
	void Display() const;

	Customer* CloneCustomer() const;

};


#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer 
{


public:
	Customer() = default;
	Customer(const Customer& other) = default;
	Customer(const std::string& id, const std::string& name, const std::string& address);

	~Customer() = default;

	Customer& operator=(const Customer& other) = default;

	// setters
	void SetID(const std::string& id);
	void SetName(const std::string& name);
	void SetAddress(const std::string& address);

	// getters
	const std::string GetID() const;
	const std::string GetName() const;
	const std::string GetAddress() const;
	
	// method to copy customer
//	Customer* CloneCustomer() const;

	void DisplayCustomerInfo() const;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStr, const Customer& someCustomer);

private:
	static const std::string M_ID_DEFAULT;

private:
	std::string m_id;
	std::string m_name;
	std::string m_address;
};

#endif // !CUSTOMER_H
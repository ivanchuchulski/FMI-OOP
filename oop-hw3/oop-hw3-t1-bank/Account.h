#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account 
{
public:
	Account() = default;
	Account(const Account& other) = default;
	Account(int initialDeposit, const std::string& ownerID, const std::string& iban);

	virtual ~Account() = default;

	Account& operator=(const Account& other) = default;

	// getters
	const int GetBalance() const;
	const std::string GetOwnerID() const;
	const std::string GetIban() const;

	// pure virtual methods
	virtual Account* CloneAccount() const = 0;
	virtual void Deposit(int depositAmmount) = 0;
	virtual bool Withdraw(int withdrawAmmount) = 0;
	virtual void DisplayAccount() const = 0;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Account& account);
	
protected:
	// modifiers
	void IncreaseAmmount(int increase);
	void DecreaseAmmount(int decrease);
	void ChangeOwnerID(const std::string& owner_id);
	void ChangeIban(const std::string& iban);

private:
	int m_balance;
	std::string m_ownerID;
	std::string m_IBAN;
};


#endif // !ACCOUNT_H
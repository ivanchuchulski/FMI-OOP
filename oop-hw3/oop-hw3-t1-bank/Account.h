#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

enum class AccountType
{
	CurrentAccount = 0,
	SavingsAccount = 1,
	PrivileAccount = 2
};


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
	const std::string GetAccountIBAN() const;

	// pure virtual methods
	virtual int GetAccountType() const = 0;
	virtual Account* CloneAccount() const = 0;
	virtual void Deposit(int depositAmmount) = 0;
	virtual bool Withdraw(int withdrawAmmount) = 0;
	virtual void DisplayAccount() const = 0;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Account& account);
	
protected:
	// modifiers
	void IncreaseBalance(int increase);
	void DecreaseBalance(int decrease);
	void ChangeOwnerID(const std::string& owner_id);
	void ChangeIban(const std::string& iban);

private:
	int m_balance;
	std::string m_ownerID;
	std::string m_accountIBAN;
};


#endif // !ACCOUNT_H
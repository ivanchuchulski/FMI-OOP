#pragma once

#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include "Account.h"

class CurrentAccount 
	:	public Account
{
public:
	CurrentAccount();
	CurrentAccount(const CurrentAccount& other);
	CurrentAccount(int initialDeposit, const std::string& ownerID, const std::string& iban);

	~CurrentAccount() = default;

	CurrentAccount& operator=(const CurrentAccount& other);

	// pure virtual mehtods overrides
	virtual Account* CloneAccount() const override;
	virtual void Deposit(int depositAmmount) override;
	virtual bool Withdraw(int withdrawAmmount) override;
	virtual void DisplayAccount() const override;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const CurrentAccount& someCurrentAcc);
};

#endif // !CURRENT_ACCOUNT_H



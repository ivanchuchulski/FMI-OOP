#pragma once

#ifndef PRIVILEGE_ACCOUNT_H
#define PRIVILEGE_ACCOUNT_H

#include "Account.h"

class PrivilegeAccount 
	: public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(const PrivilegeAccount& other);
	PrivilegeAccount(int initialDeposit, const std::string& ownerID, const std::string& iban, int overdraft);

	~PrivilegeAccount();

	PrivilegeAccount& operator=(const PrivilegeAccount& other);

	// getters
	const int GetOverdraft() const;

	// setters
	void IncreaseOverdraft(int overdraftIncrease);
	void DecreaseOverdraft(int overdraftDecrease);

	// pure virtual mehtods overrides
	virtual int GetAccountType() const override;
	virtual Account* CloneAccount() const override;
	void Deposit(int depositAmmount) override;
	bool Withdraw(int withdrawAmmount) override;
	void DisplayAccount() const override;


	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const PrivilegeAccount& somePrivilAcc);

private:
	static const int M_OVERDRAFT_DEFAULT;

private:
	int m_overdraftOverBalance;

};

#endif // !PRIVILEGE_ACCOUNT_H

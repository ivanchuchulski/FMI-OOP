#pragma once

#include "Account.h"

class SavingsAccount
	:	public Account
{
public:
	SavingsAccount();
	SavingsAccount(const SavingsAccount& other);
	SavingsAccount(int curent_amount, const std::string& owner_id, const std::string& iban, float interest);

	~SavingsAccount();

	SavingsAccount& operator=(const SavingsAccount& other);

	void SetInterest(float interest);

	const float GetInterestRate();

	// pure virtual mehtods overrides
	virtual Account* CloneAccount() const override;
	virtual void Deposit(int add_ammount) override;
	virtual bool Withdraw(int request_ammount) override;
	virtual void DisplayAccount() const override;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const SavingsAccount& savingsAccount);

private:
	const float INTEREST_DEFAULT = 1.1f;
private:
	float m_yearlyInterest;

};


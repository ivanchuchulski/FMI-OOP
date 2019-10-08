#pragma once

#include "Account.h"

class SavingsAccount
	:	public Account
{
public:
	SavingsAccount();
	SavingsAccount(const SavingsAccount& other);
	SavingsAccount(int initialDeposit, const std::string& ownerID, const std::string& iban, float yearlyInterestProcent	);

	~SavingsAccount();

	SavingsAccount& operator=(const SavingsAccount& other);

	// getters
	const float GetInterestProcent();

	// setters
	void IncreaseInterest(float interest);
	void DecreaseInterest(float interest);

	// virtual methods
	virtual void InputAccount(const std::string& ownerID) override;

	// pure virtual mehtods overrides
	virtual int GetAccountType() const override;
	virtual Account* CloneAccount() const override;
	virtual void Deposit(int depositAmmount) override;
	virtual bool Withdraw(int withdrawAmmount) override;
	virtual void DisplayAccount() const override;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const SavingsAccount& savingsAccount);

private:
	static const float M_YEARLY_INTEREST_DEFAULT;

private:
	float m_yearlyInterestProcent;

};


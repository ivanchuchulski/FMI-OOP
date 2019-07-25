#pragma once

#include "Account.h"

class SavingsAccount
	: public Account

{
private:
	const float INTEREST_DEFAULT = 1.1f;
private:
	float m_InterestRate;		//yearly interest rate

public:
	/*constructors*/
	SavingsAccount();
	SavingsAccount(const SavingsAccount& someSavingsAcc);
	SavingsAccount(int curent_amount, const std::string& owner_id, const std::string& iban, float interest);

	/*destructor*/
	~SavingsAccount();

	/*copy assignment*/
	SavingsAccount& operator=(const SavingsAccount& someSavingsAcc);

	void SetInterest(float interest);

	const float GetInterestRate();

	/*overiding the pure virtual mehtods*/
	void Deposit(int add_ammount) override;
	bool Withdraw(int request_ammount) override;
	void DisplayAccount() const override;

	friend std::ostream& operator<<(std::ostream& outStream, const SavingsAccount& someSavingsAcc);

	Account* CloneWithNew() const override;

};


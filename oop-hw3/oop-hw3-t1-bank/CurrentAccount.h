#pragma once

#include "Account.h"		//also includes <string>


class CurrentAccount :
	public Account
{

public:
	/*constructors*/
	CurrentAccount();
	CurrentAccount(const CurrentAccount& someCurrent);
	CurrentAccount(int current_amount, const std::string& owner_id, const std::string& iban);

	/*desturctor*/
	~CurrentAccount();

	/*copy assignment*/
	CurrentAccount& operator=(const CurrentAccount& someCurrent);

	/*overiding the pure virtual mehtods*/
	void Deposit(int add_ammount) override;
	bool Withdraw(int request_ammount) override;
	void DisplayAccount() const override;

	friend std::ostream& operator<<(std::ostream& outStream, const CurrentAccount& someCurrentAcc);

	Account* CloneWithNew() const override;

};


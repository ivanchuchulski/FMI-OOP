#pragma once

#include "Account.h"		//also includes <iostream>, <string>

class PrivilegeAccount 
	: public Account
{
private:
	int m_Overdraft;

public:
	/*constructors*/
	PrivilegeAccount();
	PrivilegeAccount(const PrivilegeAccount& somePrivilAcc);
	PrivilegeAccount(int curent_amount, const std::string& owner_id, const std::string& iban, int overdraft);

	/*destructor*/
	~PrivilegeAccount();

	/*copy assignment*/
	PrivilegeAccount& operator=(const PrivilegeAccount& somePrivilAcc);

	void SetOverdraft(int overdraft);

	const int GetOverdraft() const;

	/*overiding the pure virtual mehtods*/
	void Deposit(int add_ammount) override;
	bool Withdraw(int request_ammount) override;
	void DisplayAccount() const override;


	friend std::ostream& operator<<(std::ostream& outStream, const PrivilegeAccount& somePrivilAcc);

	Account* CloneWithNew() const override;

};


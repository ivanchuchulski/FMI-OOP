#pragma once

#include <iostream>
#include <string>

/*	models the basics of a bank account*/
class Account {

private:
	const char OWNER_ID_DEFAULT[5] = "1234";

private:
	int m_CurrentAmount;
	std::string m_OwnerID;
	std::string m_IBAN;

public:
	/*constructors*/
	Account();
	Account(const Account& someAccount);
	Account(int current_amount, const std::string& owner_id, const std::string& iban);

	/*destructor*/
	virtual ~Account();

	/*copy assignment*/
	Account& operator=(const Account& someAccount);

	void IncreaseAmmount(int increase);
	void DecreaseAmmount(int decrease);
	void ChangeOwnerID(const std::string& owner_id);
	void ChangeIban(const std::string& iban);


	const int GetBalance() const;
	const std::string GetOwnerID() const;
	const std::string GetIban() const;

	/*pure virtual methods, need to be implemented in the derived classes*/
	virtual void Deposit(int add_amount) = 0;
	virtual bool Withdraw(int request_ammount) = 0;
	virtual void DisplayAccount() const = 0;

	//friend std::ostream& operator<<(std::ostream& outStream, const Account& someAcc);

	virtual Account * CloneWithNew() const = 0;
	
};


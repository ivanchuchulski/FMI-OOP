#pragma once

#ifndef BANK_H
#define BANK_H

#include <vector>

#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"	
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

class Bank 
{
public:
	Bank();
	Bank(const Bank& other);
	Bank(const std::string& bankName, const std::string& bankAddress);

	~Bank();

	Bank& operator=(const Bank& someBank);

	// setters
	void ChangeBankName(const std::string& name);
	void ChangeBankAddress(const std::string& address);

	// getters
	const std::string GetName() const;
	const std::string GetAddress() const;

	// customer modifiers
	void AddCustomer(const std::string& customerID, const std::string& customerName, const std::string& customerAddress);
	void DeleteCustomer(const std::string& customerID);

	// account modifiers
	void AddAccount(const std::string& ownerID, const AccountType accountType);
	void DeleteAccount(const std::string& iban);

	// bank money operations
	void Transfer(const std::string& fromIBAN, const std::string& toIBAN, int ammount);
	void DepositToAccount(const std::string& accountIBAN, int depositAmmount);
	bool WithdrawFromAccount(const std::string& accountIBAN, int withdrawAmmount);

	// bank information
	void ListCustomers() const;
	void ListAccounts() const;
	void ListCustomerAccount(const std::string& customerID) const;
	void PrintSupportedAccountTypes() const;
	void DisplayBank() const;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Bank& bank);

private:
	void ClearAccounts();
	void CopyAccounts(const std::vector<Account*>& otherAccounts);
	
	void ClearBank();
	void CopyOtherBank(const Bank& otherBank);
	
	std::vector<Customer>::const_iterator FindByCustomerID(const std::string& customerID) const;
	std::vector<Account*>::const_iterator FindAccountByIBAN(const std::string& accountIBAN) const;

	bool AccountAlreadyOpened(const std::vector<Account*>::const_iterator accountIt) const;	
	bool CustomerAlreadyRegistered(const std::vector<Customer>::const_iterator customerIt) const;

	bool NoRegisteredCustomers() const;
	bool NoAccountsOpened() const;

private:
	std::string m_bankName;
	std::string m_bankAddress;
	std::vector<Customer> m_customers;
	std::vector<Account*> m_accounts;
};

#endif // !define BANK_H



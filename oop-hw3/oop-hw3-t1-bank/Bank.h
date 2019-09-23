#pragma once

#ifndef BANK_H
#define BANK_H

#include <vector>
#include <functional>		// std::invoke

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
	void AddCustomer(const std::string& customer_id, const std::string& name, const std::string& address);
	void DeleteCustomer(const std::string& customer_id);

	// account modifiers
	void AddAccount(AccountType accountType, int amount, const std::string& owner_id, const std::string& iban);
	void DeleteAccount(const std::string& iban);

	// bank money operations
	void Transfer(const std::string& fromIBAN, const std::string& toIBAN, int ammount);
	void DepositToAccount(const std::string& deposit_to_iban, int add_ammount);
	bool WithdrawFromAccount(const std::string& withdraw_from_iban, int request_ammount);

	// bank information
	void ListCustomers() const;
	void ListAccounts() const;
	void ListCustomerAccount(const std::string& customer_id) const;
	void PrintSupportedAccountTypes() const;
	void DisplayBank() const;

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Bank& someBank);

private:
	bool NoRegisteredCustomers() const;
	bool HasNoAccountOpened() const;

	//method to copy the data in the vectors correctly
	template<typename Type>
	void CopyVectorOfPointers(std::vector<Type*>& dest, const std::vector<Type*>& othervec_source, Type* (Type::* CloningMethod)() const);

	//mehtod to clear the pointers in the vectors
	template<typename Type>
	void ClearVectorOfPointers (std::vector<Type*>& vec);

	int FindByCustomerID(const std::string& customerID) const;
	int FindAccountByIBAN(const std::string& accountIBAN) const;

private:
	std::string m_bankName;
	std::string m_bankAddress;
	std::vector<Customer> m_customers;
	std::vector<Account*> m_accounts;
};

#endif // !define BANK_H



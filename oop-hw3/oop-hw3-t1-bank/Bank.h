#pragma once


#include <vector>
#include <functional>		// std::invoke

#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"		//also includes "Account.h"
#include "SavingsAccount.h"		//also includes "Account.h"
#include "PrivilegeAccount.h"	//also includes "Account.h"


namespace acc {
	enum  AccountTypes : unsigned int
	{
		ACurrentAccount = 0,
		ASavingsAccount = 1,
		APrivilegeAccount = 2
	};
}

class Bank {

private:
	const int DEFAULT_CLIENT_NUM = 5;

private:
	std::string m_BankName;
	std::string m_BankAddress;
	std::vector<Customer*> m_Customers;
	std::vector<Account*> m_Accounts;

private:
	int FindByCustomerID(const std::string& customerID) const;
	int FindAccountByIBAN(const std::string& iban_to_find) const;

	//method to copy the data in the vectors correctly
	template<typename Type>
	void CopyVectorContent(std::vector<Type*>& dest, 
					const std::vector<Type*>& othervec_source, 
					Type* (Type::*CloningMethod)() const);

	//mehtod to clear the pointers in the vectors
	template<typename Type>
	void ClearVectorContent(std::vector<Type*>& vec);

public:
	/*constrctors*/
	Bank();
	Bank(const Bank& someBank);
	Bank(const std::string& name_bank, const std::string& address_bank, int reserve_customers = 0);
	/*destuctor*/
	~Bank();

	/*copy assignment*/
	Bank& operator=(const Bank& someBank);

	void ChangeBankName(const std::string& name);
	void ChangeBankAddress(const std::string& address);

	const std::string GetName() const;
	const std::string GetAddress() const;


	void AddCustomer(const std::string& customer_id, const std::string& name, const std::string& address);

	void ListCustomers() const;

	void DeleteCustomer(const std::string& customer_id);

	void AddAccount(acc::AccountTypes accountType, int amount, const std::string& owner_id, const std::string& iban);

	void DeleteAccount(const std::string& iban);

	void ListAccounts() const;

	void ListCustomerAccount(const std::string& customer_id) const;

	void Transfer(const std::string& fromIBAN, const std::string& toIBAN, int ammount);

	void DepositToAccount(const std::string& deposit_to_iban, int add_ammount);

	bool WithdrawFromAccount(const std::string& withdraw_from_iban, int request_ammount);

	void DisplayBank() const;

	friend std::ostream& operator<<(std::ostream& outStream, const Bank& someBank);

	void PrintSupportedAccountTypes() const;

};


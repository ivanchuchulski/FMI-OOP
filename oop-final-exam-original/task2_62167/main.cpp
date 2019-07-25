/*
	->faculty num : 62167
	->OOP_Task2
	->compiler : Visual C++
*/

#include <iostream>
#include "ConcreteObserver.h"
#include "CentralBank.h"


int main() {

	{
		ConcreteObserver obs1("StockObserver");

		ConcreteObserver obs2("Newspaper_observer");


		CentralBank BNB("BNB");

		BNB.RegisterObserver(&obs1);
		BNB.RegisterObserver(&obs2);

		BNB.UnregisterObserver(obs1.GetName());

	}



//	std::cin.get();
	return 0;
}
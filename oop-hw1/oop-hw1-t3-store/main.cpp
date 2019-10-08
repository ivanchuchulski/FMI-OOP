/*	oop summer 2017-2018
	homework 1 task 3 : online store with one type of product
	STL classes are prohibited
*/

#include <iostream>

#include "Mouse.h"
#include "Store.h"
#include "Menu.h"

int main() 
{
	char userCommand;
	Menu storeMenu("AXCD?Q");
	Store* MiceStore = new Store();

	do 
	{
		storeMenu.ShowMenu();

		userCommand = storeMenu.GetCommand();

		switch (userCommand) 
		{
			case 'A' :
				MiceStore->InputProductFromUser();
				break;

			case 'X' :
				MiceStore->DeleteProduct();
				break;

			case 'C' :
				MiceStore->ChangeProduct();
				break;

			case 'D' :
				MiceStore->Print();
				break;

			case '?' :
				storeMenu.ShowMenu();
				break;
		}
	} while (userCommand != 'Q');


	std::cout << "Come again soon!\n";

	delete MiceStore;

	//-- Tests --
	/*
	ComputerMouse mouse1 = ComputerMouse(1, 0, 7, 50, "#123", "Canyon", "123", 10.50f);
	ComputerMouse mouse2 = ComputerMouse(1, 1, 5, 70, "#456", "SteelSeries", "456", 12.00f);

	std::cout << mouse1;
	std::cout << mouse2;

	Store testStore = Store(3);

	// insertion
	testStore.InputProductFromUser();
	testStore.InputProductFromUser();

	testStore.AddProduct(mouse1);
	testStore.AddProduct(mouse2);

	testStore.Print();

	// removal
	testStore.DeleteProduct();

	testStore.Print();

	// modification
	testStore.ChangeProduct();

	testStore.Print();

	ComputerMouse* myMouse = new ComputerMouse(1, 1, 5, 200, "#123", "Canyon", "Fobos", 10.5f);

	std::cout << *(myMouse) << std::endl;

	delete myMouse;
	*/

	return 0;
}
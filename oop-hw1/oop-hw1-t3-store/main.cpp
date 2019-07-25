#include <iostream>
#include "Mouse.h"
#include "Store.h"


char toUpper(char symbol) {
	if (symbol >= 'a' && symbol <= 'z') {
		return symbol - ('a' - 'A');
	}
	return symbol;
}

/*main menu*/
void showMenu() {
	std::cout << "\n\t\t###### Computer Mice Shop ######";

	std::cout << "\n\tA \tAdd a new mouse";
	std::cout << "\n\tX \tDelete a mouse";
	std::cout << "\n\tC \tUpdate a mouse spec";
	std::cout << "\n\tD \tDisplay the mice in the shop";

	std::cout << "\n\t? \tShow the menu";
	std::cout << "\n\tQ \tQuit";
}

char getSymbol(char* promptString) {
	char response;

	std::cout << promptString;
	std::cin >> response;

	response = toUpper(response);
	std::cin.get();						

	return response;
}

bool legalCommand(char symbol) {
	return	(	(symbol == 'A') || (symbol == 'X') ||

				(symbol == 'C') || (symbol == 'D') ||

				(symbol == '?') || (symbol == 'Q')		);
}

char getCommand()
{
	char userCommand = getSymbol("\n\n>");	//get a char from the console

	while (legalCommand(userCommand) == false) {
		std::cout << "\nIllegal command, please enter again";
		showMenu();
		userCommand = getSymbol("\n\n_>");
	}

	return userCommand;
}


/*Main function*/
int main() {

/*
	Mouse mouse1 = Mouse(1, 0, 7, 50, "#123", "Canyon", "CND-SGM3", 10.50f);
	Mouse mouse2 = Mouse(1, 1, 5, 70, "#1234", "SteelSeries", "CND-SGM3", 10.50f);

	std::cout << mouse1;
	std::cout << mouse2;

	std::cout << mouse1;

	Store myStore = Store(3);
	myStore.InputProduct();
	myStore.InputProduct();
	myStore.InputProduct();
	myStore.InputProduct();
	myStore.Print();

	myStore.DeleteProduct();
	myStore.Print();
	myStore.ChangeProduct();
	myStore.Print();

	Mouse* myMouse = new Mouse(1, 1, 5, 200, "#123", "Canyon", "Fobos", 10.5f);

	std::cout << *(myMouse) << std::endl;

	delete myMouse;

*/

	
	char userCmd;
	Store* MiceStore = new Store(2);

	showMenu();

	do {

		userCmd = getCommand();

		switch (userCmd) {
			case 'A' :
				MiceStore->InputProduct();
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
				showMenu();
				break;
			case 'Q':
				//this is the exit condition
				break;
		}


	} while (userCmd != 'Q');


	std::cout << "Come again soon!\n";

	/*free memory*/
	delete MiceStore;

	std::cin.get();
	return 0;
}
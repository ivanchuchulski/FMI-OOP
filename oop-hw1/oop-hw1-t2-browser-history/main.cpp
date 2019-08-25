/*	oop summer 2017-2018
	homework 1 task 2 : browser history with fixed size
	STL classes are prohibited
*/

#include <iostream>

#include "BrowserHistory.h"


int main() {

	HistoryEntry entry1 = HistoryEntry(static_cast<int>(Month::January), "www.first.com");
	HistoryEntry entry2 = HistoryEntry(static_cast<int>(Month::January), "www.second.com");
	HistoryEntry entry3 = HistoryEntry(static_cast<int>(Month::February), "www.third.bg");
	HistoryEntry entry4 = HistoryEntry(static_cast<int>(Month::Unknown), nullptr);

	{
		BrowserHistory history0 = BrowserHistory(5);
	}


	BrowserHistory history1 = BrowserHistory(5);
	BrowserHistory history2 = BrowserHistory(3);

	/*adding methods*/
	history1.AddEntry(entry1);
	history1.AddEntry(entry2);
	history1.AddEntry(entry3);
	history1.AddEntry(entry4);

	/*input from the console*/
	//std::cin >> entry1;

	/*output to the console*/
	std::cout << entry1;

	history1.PrintAll();
	history2.PrintAll();

	history1.MostActiveMonth();

	history1.RemoveLatestEntry();
	history2.RemoveLatestEntry();

	history2.AddEntry(entry1);

	BrowserHistory* history3 = new BrowserHistory(history1.Concatenate(history2));
	BrowserHistory* history4 = new BrowserHistory(history1);

	(*history4) = history2.Concatenate(*history3);

	std::cout << '\n';
	history3->PrintAll();

	std::cout << '\n';
	history4->PrintAll();

	/*free memory*/
	delete history4;
	delete history3;

	return 0;
}
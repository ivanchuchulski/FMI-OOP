#include <iostream>
#include "BrowserHistory.h"


int main() {

	HistoryEntry entry1 = HistoryEntry(January, "www.example.com");
	HistoryEntry entry2 = HistoryEntry(January, "www.hello.com");
	HistoryEntry entry3 = HistoryEntry( February, "www.fmi.bg");
	HistoryEntry entry4 = HistoryEntry(Unknown, nullptr);

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

	history3->PrintAll();
	history4->PrintAll();


	/*free memory*/
	delete history4;
	delete history3;

	std::cin.get();
	return 0;
}
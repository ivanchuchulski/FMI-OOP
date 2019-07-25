#pragma once

#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

//#include <iostream>
#include "HistoryEntry.h"


/*		BrowsenHistory class definition 	*/
class BrowserHistory {

private:
	int m_MaxSize;
	int m_EntriesCount;
	HistoryEntry* m_HistoryArr;
	int m_MonthsCounter[13];		//each index in the array represents a month, the same way the enum Month does

private:
	void nullOutMonths();

private:
	/*these two are my first ideas, they work a bit diffetrent, but really inefficiently, so they should not be used*/
	BrowserHistory Concat_V1(const BrowserHistory& firstBrowser, const BrowserHistory& secondBrowser);
	BrowserHistory Concat_V2(const BrowserHistory& firstBrowser, const BrowserHistory& secondBrowser);

	/*private constructor, used is the concatenation method*/
	BrowserHistory(int max_size, int first_entries, int entries_count, HistoryEntry* first_historyArr, HistoryEntry* second_historyArr, int* months_counter);

public:
	/*constructors and destructor*/
	BrowserHistory();
	BrowserHistory(int N);
	BrowserHistory(const BrowserHistory& otherBrowserHistory);
	~BrowserHistory();

	/*copy assignment operator*/
	BrowserHistory& operator=(const BrowserHistory& otherBrowserHistory);

	/*input methods*/
	void AddEntry(const HistoryEntry& HistEntry);
	void InputEntry();
	
	/*print methods*/
	void PrintAll() const;
	void PrintByMonth(int Month) const;
	void MostActiveMonth() const;

	/*removing method*/
	void RemoveLatestEntry();

	/*concatenating mehtod*/
	BrowserHistory Concatenate(const BrowserHistory& otherBrowser);
};

#endif // !BROWSER_HISTORY_H

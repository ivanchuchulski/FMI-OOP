#pragma once

#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

#include "HistoryEntry.h"

// basicly the class implements a stack, LIFO principle, with fixed max size
class BrowserHistory
{
public:
	BrowserHistory();
	BrowserHistory(const BrowserHistory& otherBrowserHistory);
	BrowserHistory(int browserMemory);
	~BrowserHistory();

	BrowserHistory& operator=(const BrowserHistory& otherBrowserHistory);

	void Clear();
	bool Empty() const;

	bool AddEntry(const HistoryEntry& histEntry);
	bool InputEntry();

	bool RemoveLatestEntry();

	void PrintAll() const;
	void PrintByMonth(int Month) const;
	void MostActiveMonth() const;

	BrowserHistory Concatenate(const BrowserHistory& otherBrowser);

private:
	void NullifyMonthsArray();
	bool Full() const;
	int CurrentSize() const;

private:
	int m_maxCapacity;
	int m_arrTop;
	HistoryEntry* m_historyArr;
	int m_monthsFrequency[13];		//each index in the array represents a month, the same way the enum Month does

private:
	const int M_DEFAULT_MAX_CAPACITY = 5;
};

#endif // !BROWSER_HISTORY_H

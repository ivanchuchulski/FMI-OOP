#pragma once

#ifndef HISTORY_ENTRY_H
#define HISTORY_ENTRY_H

#include <iostream>

/*enum to represent months of the year*/
enum class Month
{
	Unknown = 0,
	January = 1,	 February = 2,		March = 3,
	April = 4,		 May = 5,			June = 6,
	July = 7,		 August = 8,		September = 9,
	October = 10,	 November = 11,		December = 12
};

struct HistoryEntry 
{
public:
	HistoryEntry();
	HistoryEntry(const HistoryEntry& other);
	HistoryEntry(int date, char* url);
	~HistoryEntry();

	HistoryEntry& operator=(const HistoryEntry& other);

	void SetUrl(const char* url);
	void SetDate(int date);

	const char* GetUrl() const;
	Month GetDate() const;

	friend std::ostream& operator<<(std::ostream& outStream, const HistoryEntry& historyEntry);
	friend std::istream& operator>>(std::istream& inStream, HistoryEntry& historyEntry);

public:
	Month m_date;
	char* m_url;
};

#endif // !HISTORY_ENTRY_H

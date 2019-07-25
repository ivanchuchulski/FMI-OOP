#pragma once


#ifndef HISTORY_ENTRY_H
#define HISTORY_ENTRY_H

#include <iostream>


/*enum to represent months of the year*/
enum Month
{
	Unknown = 0,
	January = 1,	 February = 2,		March = 3,
	April = 4,		 May = 5,			June = 6,
	July = 7,		 August = 8,		September = 9,
	October = 10,	 November = 11,		December = 12
};

/*		HistoryEntry structure definition	*/
struct HistoryEntry {

public:
	Month m_Date;
	char* m_Url;

protected:
	char* SetCString(const char* source = nullptr);

public:
	/*constructors and destructor*/
	HistoryEntry();
	HistoryEntry(Month date, char* url );
	HistoryEntry(const HistoryEntry& otherHisEntry);
	~HistoryEntry();

	/*copy assignment operator*/
	HistoryEntry& operator=(const HistoryEntry& otherHisEntry);

	friend std::ostream& operator<<(std::ostream& outStream, const HistoryEntry& hisEntry);
	friend std::istream& operator>>(std::istream& inStream, HistoryEntry& history);

	/*setters*/
	void setUrl(char* url);
	void setDate(Month date);

	/*getters*/
	const char* getUrl() const;
	Month getDate() const;

};

#endif // !HISTORY_ENTRY_H

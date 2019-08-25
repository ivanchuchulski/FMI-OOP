#include "HistoryEntry.h"

#include <cstring>

HistoryEntry::HistoryEntry()
	:	m_date(Month::Unknown),
		m_url(nullptr)
{}


HistoryEntry::HistoryEntry(const HistoryEntry& other)
	:	m_date(other.m_date),
		m_url(nullptr)
{
	SetUrl(other.m_url);
}

HistoryEntry::HistoryEntry(int date, char* url)
	:	m_date(Month::Unknown),
		m_url(nullptr)
{
	SetUrl(url);
	SetDate(date);
}

HistoryEntry::~HistoryEntry() 
{
	delete[] m_url;
	m_url = nullptr;
}

HistoryEntry& HistoryEntry::operator=(const HistoryEntry& other) 
{
	if (this != &other)
	{
		SetUrl(other.m_url);
		SetDate(static_cast<int>(other.m_date));
	}

	return *this;		// TODO: insert return statement here
}

void HistoryEntry::SetUrl(const char* source) 
{
	//first clear old memory
	delete[] m_url;
	m_url = nullptr;

	if (source == nullptr)
	{
		const int LEN_DEFAULT_URL = 7;
		const char* DEFAULT_URL = "Unknown";

		m_url = new char[LEN_DEFAULT_URL + 1];
		std::memcpy(m_url, DEFAULT_URL, LEN_DEFAULT_URL + 1);
	}

	int source_len = std::strlen(source);

	m_url = new char[source_len + 1];
	std::memcpy(m_url, source, source_len + 1);
}

void HistoryEntry::SetDate(int date) 
{
	if (date < 1 || date > 12) 
	{
		m_date = Month::Unknown;
	}

	m_date = static_cast<Month>(date);
}

const char* HistoryEntry::GetUrl() const 
{
	return m_url;
}

Month HistoryEntry::GetDate() const 
{
	return m_date;
}

std::ostream& operator<<(std::ostream& outStream, const HistoryEntry& historyEntry) 
{
	const char* monthsArr[] = { "Unknown", "January", "February", "March",
						"April", "May", "June", "July", 
						"August", "September", "October", "November", "December"};

	int month_index = static_cast<int>(historyEntry.m_date);

	if (historyEntry.m_url == nullptr) 
	{
		outStream << "The site \"\" was visited in " << monthsArr[month_index] << '\n';
	}

	else 
	{
		outStream << "The site \"" << historyEntry.m_url << "\" was visited in " << monthsArr[month_indexa] << '\n';
	}

	return outStream;		// TODO: insert return statement here
}

std::istream& operator>>(std::istream& inStream, HistoryEntry& historyEntry)
{
	const int LEN_DEFAULT_TEMP_URL = 30;
	char* tempUrl = new char[LEN_DEFAULT_TEMP_URL + 1];
	int tempDate = 0;

	std::memset(tempUrl, '\0', LEN_DEFAULT_TEMP_URL + 1);

	std::cout << "Please enter a month(by number) first : ";
	inStream >> tempDate;

	inStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter a url : ";
	inStream.getline(tempUrl, LEN_DEFAULT_TEMP_URL);


	historyEntry.SetUrl(tempUrl);
	historyEntry.SetDate(tempDate);

	delete[] tempUrl;

	return inStream;		// TODO: insert return statement here
}
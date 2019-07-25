#include <string.h>
#include "HistoryEntry.h"


/*		class HistoryEntry mehtods definition		*/
#pragma region

char* HistoryEntry::SetCString(const char* source) {
	char* bufferPtr = nullptr;

	if (source != nullptr) {
		int length = strlen(source);
		bufferPtr = new char[length + 1];
		//strcpy_s(bufferPtr, sourceLen + 1, source);
		memcpy_s(bufferPtr, length + 1, source, length + 1);
		return bufferPtr;
	}
	else {
		bufferPtr = new char[8];
		memcpy_s(bufferPtr, 8, "Unknown", 8);
		return bufferPtr;
	}

}

/*ctors and dtor*/
HistoryEntry::HistoryEntry()
	:	m_Date(Unknown),
		m_Url(SetCString())
{
}

HistoryEntry::HistoryEntry(Month date, char* url)
	:	m_Date(Unknown),
		m_Url(SetCString(url))
{
	/*setting m_Date*/
	if (date > 0 && date < 13) {
		m_Date = date;
	}
}

HistoryEntry::HistoryEntry(const HistoryEntry& otherHisEntry)
	:	m_Date(otherHisEntry.m_Date),
		m_Url(SetCString(otherHisEntry.m_Url))
{}

HistoryEntry::~HistoryEntry() {
	//free memory if needed
	if (m_Url != nullptr) {
		delete[] m_Url;
	}
}

/*copy assignment operator*/
HistoryEntry& HistoryEntry::operator=(const HistoryEntry& otherHisEntry) {
	if (this != &otherHisEntry) {
		//free dynamic memory if needed
		if (m_Url != nullptr) {
			delete[] m_Url;
			m_Url = nullptr;
		}

		m_Url = SetCString(otherHisEntry.m_Url);
		m_Date = otherHisEntry.m_Date;
	}

	return *this;		// TODO: insert return statement here
}

/*operator<< overload*/
std::ostream& operator<<(std::ostream& outStream, const HistoryEntry& hisEntry) {

	if (hisEntry.m_Url == nullptr) {
		outStream << "The site \"\" was visited in ";
	}
	else {
		outStream << "The site \"" << hisEntry.m_Url << "\" was visited in ";
	}

	switch (hisEntry.m_Date)
	{
	case Unknown:
		outStream << "Unknown month" << '\n';
		break;
	case January:
		outStream << "January" << '\n';
		break;
	case February:
		outStream << "February" << '\n';
		break;
	case March:
		outStream << "March" << '\n';
		break;
	case April:
		outStream << "April" << '\n';
		break;
	case May:
		outStream << "May" << '\n';
		break;
	case June:
		outStream << "June" << '\n';
		break;
	case July:
		outStream << "July" << '\n';
		break;
	case August:
		outStream << "August" << '\n';
		break;
	case September:
		outStream << "September" << '\n';
		break;
	case October:
		outStream << "October" << '\n';
		break;
	case November:
		outStream << "November" << '\n';
		break;
	case December:
		outStream << "December" << '\n';
		break;
	default:
		break;
	}

	return outStream;		// TODO: insert return statement here
}

/*operator>> overload*/
std::istream& operator>>(std::istream& inStream, HistoryEntry& hisEntry)
{
	char* tempUrl = new char[30];
	int tempDate = 0;

	std::cout << "Please enter a month(by number) first : ";
	inStream >> tempDate;

	inStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter a url : ";
	inStream.getline(tempUrl, 30);

	/*passing the input to the setter methods*/
	hisEntry.setUrl(tempUrl);
	hisEntry.setDate((Month)tempDate);

	/*free memory!*/
	delete[] tempUrl;

	return inStream;		// TODO: insert return statement here
}

/*getters and setters*/
void HistoryEntry::setUrl(char* url) {
	//free dynamic memory if needed
	if (m_Url != nullptr) {
		delete[] m_Url;
		m_Url = nullptr;
	}

	m_Url = SetCString(url);


}

void HistoryEntry::setDate(Month date) {
	if (date > 0 && date < 13) {
		m_Date = date;
	}
	else {
		m_Date = Unknown;
	}
}

const char* HistoryEntry::getUrl() const {
	return m_Url;
}

Month HistoryEntry::getDate() const {
	return m_Date;
}

#pragma endregion

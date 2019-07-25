//#include <iostream>
#include "BrowserHistory.h"


/*		class BrowserHistory methods definition		*/
#pragma region

/*private helper function to nullify the array, counting the months*/
void BrowserHistory::nullOutMonths() {
	for (int i = 0; i < 13; i++) {
		m_MonthsCounter[i] = 0;
	}
}

/*ctors and dtor*/
BrowserHistory::BrowserHistory()
	:	m_MaxSize(5),
		m_EntriesCount(0),
		m_HistoryArr(nullptr),
		m_MonthsCounter()
{
	nullOutMonths();
	m_HistoryArr = new HistoryEntry[m_MaxSize]{};
}

BrowserHistory::BrowserHistory(int N)
	:	m_MaxSize(0),
		m_EntriesCount(0),
		m_HistoryArr(nullptr),
		m_MonthsCounter()
{
	nullOutMonths();

	if (N > 0) {
		m_MaxSize = N;
		m_HistoryArr = new HistoryEntry[m_MaxSize];		//m_MaxSize HistoryEntry objects initialized with default ctors 
	}
	else {
		//std::cout << "Wrong input, N should be >= 0!\n";
		m_MaxSize = 5;
		m_HistoryArr = new HistoryEntry[m_MaxSize];
	}
}

BrowserHistory::BrowserHistory(const BrowserHistory& otherBrowserHistory)
	:	m_MaxSize(otherBrowserHistory.m_MaxSize),
		m_EntriesCount(otherBrowserHistory.m_EntriesCount)
{
	nullOutMonths();

	if (otherBrowserHistory.m_HistoryArr == nullptr) {
		m_MaxSize = 0;
		m_EntriesCount = 0;
		m_HistoryArr = nullptr;

	}
	else {

		//allocating the array, its been init with default ctors
		m_HistoryArr = new HistoryEntry[m_MaxSize];

		for (int i = 0; i < m_EntriesCount; i++) {
			/*this should call the copy assignment of  two HistoryEntry class objects*/
			m_HistoryArr[i] = otherBrowserHistory.m_HistoryArr[i];
		}
		/*copyng the month array*/
		for (int j = 0; j < 13; j++) {
			m_MonthsCounter[j] = otherBrowserHistory.m_MonthsCounter[j];
		}
	}
}
/*dtor _> free dynamic memory*/
BrowserHistory::~BrowserHistory() {

	if (m_HistoryArr != nullptr) {
		//the operator delete[] calls the dtor for each HistoryEntry in the array
		delete[] m_HistoryArr;
		//delete[m_MaxSize] m_HistoryArr;		alternatively 
	}
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory& otherBrowserHistory) {
	if (this != &otherBrowserHistory) {

		//free memory if needed
		if (m_HistoryArr != nullptr) {
			delete[] m_HistoryArr;
		}
		
		m_MaxSize = otherBrowserHistory.m_MaxSize;
		m_EntriesCount = otherBrowserHistory.m_EntriesCount;

		m_HistoryArr = new HistoryEntry[m_MaxSize];

		/*copy assigningn only those, who are different from the default HistoryEntry objects,
		because when allocation happens, m_MaxSize objects are already created with default ctor*/
		for (int i = 0; i < m_EntriesCount; i++) {
			m_HistoryArr[i] = otherBrowserHistory.m_HistoryArr[i];
		}

		/*copyng the month array*/
		for (int j = 0; j < 13; j++) {
			m_MonthsCounter[j] = otherBrowserHistory.m_MonthsCounter[j];
		}
	}

	return *this;		// TODO: insert return statement heres
}

/*Input methods*/
void BrowserHistory::AddEntry(const HistoryEntry& HistEntry) {
	if (m_EntriesCount == m_MaxSize) {
		std::cout << "Error, the history is full!\n";
		return;
	}
	else {
		m_HistoryArr[m_EntriesCount] = HistEntry;


		Month currentMonth = m_HistoryArr[m_EntriesCount].getDate();
		int monthIndex = (int)currentMonth;
		m_MonthsCounter[monthIndex] += 1;

		m_EntriesCount++;
	}
}

void BrowserHistory::InputEntry() {
	if (m_EntriesCount == m_MaxSize) {
		std::cout << "Error, the history is full!\n";
		return;
	}
	else {
		/*get input from the keyboard*/
		std::cin >> m_HistoryArr[m_EntriesCount];


		Month currentMonth = m_HistoryArr[m_EntriesCount].getDate();
		int monthIndex = (int)currentMonth;
		m_MonthsCounter[monthIndex] += 1;

		m_EntriesCount++;
	}
}

/*Printing methods*/
void BrowserHistory::PrintAll() const {

	std::cout << "\nPrinting a browser history : \n";

	if (m_EntriesCount == 0) {
		std::cout << "!this browser history has no entries, it is empty!\n\n";
	}
	else {
		for (int i = 0; i < m_EntriesCount; i++) {
			std::cout << "[" << i << "] = ";
			std::cout << m_HistoryArr[i];
		}
		std::cout << '\n';
	}
}

void BrowserHistory::PrintByMonth(int monthPassed) const {

	Month inputMonth = (Month)monthPassed;
	int monthCounter = 0;

	std::cout << "\nSearching for sites visited in " << inputMonth << '\n';

	if (m_EntriesCount == 0) {
		std::cout << "!this browser history has no entries, it is empty!\n\n";
	}
	else {
		for (int i = 0; i < m_EntriesCount; i++) {

			if (m_HistoryArr[i].m_Date == inputMonth) {
				std::cout << "[" << i << "] = ";
				std::cout << m_HistoryArr[i];
				monthCounter++;
			}

		}

		/*if there was no matches in the loop*/
		if (monthCounter == 0) {
			std::cout << "No sites have been visited at that time\n\n";
		}
		else {
			std::cout << monthCounter << "sites have been visited in " << monthPassed << "\n\n";
		}
	}
}

void BrowserHistory::MostActiveMonth() const {

	int mostVisitedIndex = 0;
	int frequencyCount = m_MonthsCounter[0];
	//char frequentMonth[14];

	/*finding the most active*/
	for (int i = 1; i < 13; i++) {
		if (m_MonthsCounter[i] >= frequencyCount) {
			frequencyCount = m_MonthsCounter[i];
			mostVisitedIndex = i;
		}
	}

	switch (mostVisitedIndex)
	{
	case Unknown:
		//strcpy_s(frequentMonth, 14, "Unknown month");
		std::cout << "\nThe most active month was Unknown, visited " << frequencyCount << " times\n\n";
		break;
	case January:
		std::cout << "\nThe most active month was January, visited " << frequencyCount << " times\n\n";
		break;
	case February:
		std::cout << "\nThe most active month was February, visited " << frequencyCount << " times\n\n";
		break;
	case March:
		std::cout << "\nThe most active month was March, visited " << frequencyCount << " times\n\n";
		break;
	case April:
		std::cout << "\nThe most active month was April, visited " << frequencyCount << " times\n\n";
		break;
	case May:
		std::cout << "\nThe most active month was May, visited " << frequencyCount << " times\n\n";
		break;
	case June:
		std::cout << "\nThe most active month was June, visited " << frequencyCount << " times\n\n";
		break;
	case July:
		std::cout << "\nThe most active month was July, visited " << frequencyCount << " times\n\n";
		break;
	case August:
		std::cout << "\nThe most active month was August, visited " << frequencyCount << " times\n\n";
		break;
	case September:
		std::cout << "\nThe most active month was September, visited " << frequencyCount << " times\n\n";
		break;
	case October:
		std::cout << "\nThe most active month was October, visited " << frequencyCount << " times\n\n";
		break;
	case November:
		std::cout << "\nThe most active month was November, visited " << frequencyCount << " times\n\n";
		break;
	case December:
		std::cout << "\nThe most active month was December, visited " << frequencyCount << " times\n\n";
		break;
	default:
		break;
	}

}

/*Remove method*/
void BrowserHistory::RemoveLatestEntry() {

	if (m_EntriesCount == 0) {
		std::cout << "No entries to remove, the history in empty!\n";
	}
	else {
		int removeIndex = m_EntriesCount - 1;

		/*decrementing the month from the array*/
		int monthToRemove = m_HistoryArr[removeIndex].m_Date;
		m_MonthsCounter[monthToRemove]--;

		/*cleaning the other data*/
		if (m_HistoryArr[removeIndex].m_Url != nullptr) {
			delete[] m_HistoryArr[removeIndex].m_Url;
			m_HistoryArr[removeIndex].m_Url = nullptr;
		}
		m_HistoryArr[removeIndex].m_Date = Unknown;

		m_EntriesCount--;
	}

}

/*Concatenation methods*/
BrowserHistory BrowserHistory::Concat_V1(const BrowserHistory& firstBrowser, const BrowserHistory& secondBrowser) {

	if (firstBrowser.m_MaxSize == 0 && 
		secondBrowser.m_MaxSize == 0 && 
		firstBrowser.m_HistoryArr == nullptr && 
		secondBrowser.m_HistoryArr == nullptr)
	{
		/*free current history*/
		if (m_HistoryArr != nullptr) {
			delete[] m_HistoryArr;
		}

		m_MaxSize = 0;
		m_EntriesCount = 0;
		m_HistoryArr = nullptr;
		for (int k = 0; k < 13; k++) {
			m_MonthsCounter[k] = 0;
		}

	}

	else if(this == &firstBrowser || this == &secondBrowser) {

		int toBuild_MaxSize = firstBrowser.m_MaxSize + secondBrowser.m_MaxSize;
		int toBuild_EntriesCount = firstBrowser.m_EntriesCount + secondBrowser.m_EntriesCount;
		int toBuild_MonthsCounter[13];
		int copyIndex = 0;

			/*in this case we need a buffer with the new size, copy from this object and then delete it*/
			HistoryEntry* bufferHistory = new HistoryEntry[toBuild_MaxSize];
			int bufferEntriesCount = 0;

			//copying from first browser, in this case  it is the this->object
			for (copyIndex = 0; copyIndex < firstBrowser.m_EntriesCount; copyIndex++) {
				bufferHistory[copyIndex] = firstBrowser.m_HistoryArr[copyIndex];
				bufferEntriesCount++;
			}

			//copying from second browser
			int indForSecond = 0;
			for (copyIndex; copyIndex < toBuild_EntriesCount; copyIndex++, indForSecond++) {
				bufferHistory[copyIndex] = secondBrowser.m_HistoryArr[indForSecond];
				bufferEntriesCount++;
			}

			//copyng the months array
			for (int k = 0; k < 13; k++) {
				//first copying in the new array, then in the this;
				toBuild_MonthsCounter[k] = firstBrowser.m_MonthsCounter[k] + secondBrowser.m_MonthsCounter[k];
				this->m_MonthsCounter[k] = toBuild_MonthsCounter[k];
			}

			/*free current history*/
			if (m_HistoryArr != nullptr) {
				delete[] m_HistoryArr;
			}

			/*set new history*/
			m_HistoryArr = bufferHistory;
			m_EntriesCount = bufferEntriesCount;
			m_MaxSize = toBuild_MaxSize;

			/*free the buffer*/
			delete[] bufferHistory;
		}

	else if (this != &firstBrowser && this != &secondBrowser) {

		int toBuild_MaxSize = firstBrowser.m_MaxSize + secondBrowser.m_MaxSize;
		int toBuild_EntriesCount = firstBrowser.m_EntriesCount + secondBrowser.m_EntriesCount;
		int copyIndex = 0;

		/*free current history*/
		if (m_HistoryArr != nullptr) {
			delete[] m_HistoryArr;
		}
		m_EntriesCount = 0;
		m_MaxSize = toBuild_MaxSize;

		/*		build new history array		*/
		m_HistoryArr = new HistoryEntry[toBuild_MaxSize];

		//copying from first browser
		for (copyIndex = 0; copyIndex < firstBrowser.m_EntriesCount; copyIndex++) {
			m_HistoryArr[copyIndex] = firstBrowser.m_HistoryArr[copyIndex];
			m_EntriesCount++;
		}

		//copying from second browser
		int indForSecond = 0;
		for (copyIndex; copyIndex < toBuild_EntriesCount; copyIndex++, indForSecond++) {
			m_HistoryArr[copyIndex] = secondBrowser.m_HistoryArr[indForSecond];
			m_EntriesCount++;
		}

		//copyng the months array
		for (int k = 0; k < 13; k++) {
			m_MonthsCounter[k] = firstBrowser.m_MonthsCounter[k] + secondBrowser.m_MonthsCounter[k];
		}

	}

	return BrowserHistory(*this);
}

BrowserHistory BrowserHistory::Concat_V2(const BrowserHistory& firstBrowser, const BrowserHistory& secondBrowser) {

	int toBuild_MaxSize = firstBrowser.m_MaxSize + secondBrowser.m_MaxSize;
	int toBuild_EntriesCount = firstBrowser.m_EntriesCount + secondBrowser.m_EntriesCount;
	int copyIndex = 0;		//equal to how many entries we copy

	/*in this case we need a bufferBrowser*/
	BrowserHistory bufferBrowser = BrowserHistory(toBuild_MaxSize);
	bufferBrowser.m_MaxSize = toBuild_MaxSize;

	/*	setting the bufferBrowser	*/

	//copying from first browser
	for (copyIndex = 0; copyIndex < firstBrowser.m_EntriesCount; copyIndex++) {
		bufferBrowser.m_HistoryArr[copyIndex] = firstBrowser.m_HistoryArr[copyIndex];
		bufferBrowser.m_EntriesCount++;
	}

	//copying from second browser
	int indForSecond = 0;
	for (copyIndex; copyIndex < toBuild_EntriesCount; copyIndex++, indForSecond++) {
		bufferBrowser.m_HistoryArr[copyIndex] = secondBrowser.m_HistoryArr[indForSecond];
		bufferBrowser.m_EntriesCount++;
	}

	//copyng the months array
	for (int k = 0; k < 13; k++) {
		bufferBrowser.m_MonthsCounter[k] = firstBrowser.m_MonthsCounter[k] + secondBrowser.m_MonthsCounter[k];
	}

	/*call the copy ctor to return an object*/
	return BrowserHistory(bufferBrowser);
	/*the buffer is stack allocated and its cleaned when end of scope is reached*/
}


/*ctor, used in the concatenation method*/
BrowserHistory::BrowserHistory(int max_size, int first_entries, int entries_count, HistoryEntry* first_historyArr, HistoryEntry* second_historyArr, int* months_counter)
	:	m_MaxSize(max_size),
		m_EntriesCount(entries_count),
		m_HistoryArr(nullptr),
		m_MonthsCounter()
{
	/*setting history array*/
	if (max_size > 0) {
		m_HistoryArr = new HistoryEntry[max_size];

		//copy from first
		for (int i = 0; i < first_entries; i++) {
			m_HistoryArr[i] = first_historyArr[i];
		}
		//copy from second
		int indForSecond = 0;
		for (int k = first_entries, indForSecond = 0; k < entries_count; k++, indForSecond++) {
			m_HistoryArr[k] = second_historyArr[indForSecond];
		}
	}
	else if (max_size == 0) {
		m_HistoryArr = nullptr;
	}

	/*setting the months counter*/
	for (int m = 0; m < 13; m++) {
		m_MonthsCounter[m] = months_counter[m];
	}


}

BrowserHistory BrowserHistory::Concatenate(const BrowserHistory& otherBrowser)
{
	int toBuild_MaxSize =this->m_MaxSize + otherBrowser.m_MaxSize;
	int toBuild_EntriesCount = this->m_EntriesCount + otherBrowser.m_EntriesCount;
	int toBuild_MonthsCounter[13];

	for (int i = 0; i < 13; i++) {
		toBuild_MonthsCounter[i] = this->m_MonthsCounter[i] + otherBrowser.m_MonthsCounter[i];
	}

	//calling the special constructor
	return BrowserHistory(toBuild_MaxSize, this->m_EntriesCount, toBuild_EntriesCount, this->m_HistoryArr, otherBrowser.m_HistoryArr, toBuild_MonthsCounter);
}

#pragma endregion
#include "BrowserHistory.h"


/*private helper function to nullify the array, counting the months*/
void BrowserHistory::NullifyMonthsArray()
{
	for (int i = 0; i < 13; i++)
	{
		m_monthsFrequency[i] = 0;
	}
}

BrowserHistory::BrowserHistory()
	: m_maxCapacity(M_DEFAULT_MAX_CAPACITY),
	m_arrTop(-1),
	m_historyArr(nullptr),
	m_monthsFrequency()
{
	NullifyMonthsArray();
	m_historyArr = new HistoryEntry[m_maxCapacity]{};
}

BrowserHistory::BrowserHistory(const BrowserHistory& otherBrowserHistory)
	: m_maxCapacity(M_DEFAULT_MAX_CAPACITY),
	m_arrTop(-1),
	m_historyArr(nullptr),
	m_monthsFrequency()
{
	NullifyMonthsArray();

	if (otherBrowserHistory.Empty())
		return;

	m_maxCapacity = otherBrowserHistory.m_maxCapacity;
	m_historyArr = new HistoryEntry[m_maxCapacity]{};

	for (int i = 0; i < otherBrowserHistory.CurrentSize(); i++)
		AddEntry(otherBrowserHistory.m_historyArr[i]);
}

BrowserHistory::BrowserHistory(int browserMemory)
	: m_maxCapacity((browserMemory > 0) ? browserMemory : M_DEFAULT_MAX_CAPACITY),
	m_arrTop(-1),
	m_historyArr(nullptr),
	m_monthsFrequency()
{
	NullifyMonthsArray();
	m_historyArr = new HistoryEntry[m_maxCapacity]{};
}

BrowserHistory::~BrowserHistory()
{
	//the operator delete[] calls the dtor for each HistoryEntry in the array
	delete[] m_historyArr;
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory& otherBrowserHistory)
{
	if (this != &otherBrowserHistory)
	{
		Clear();

		if (otherBrowserHistory.Empty())
			return *this;

		m_maxCapacity = otherBrowserHistory.m_maxCapacity;
		m_historyArr = new HistoryEntry[m_maxCapacity]{};

		for (int i = 0; i < otherBrowserHistory.CurrentSize(); i++)
			AddEntry(otherBrowserHistory.m_historyArr[i]);
	}

	return *this;		// TODO: insert return statement heres
}

bool BrowserHistory::Empty() const
{
	return m_arrTop == -1;
}

bool BrowserHistory::Full() const
{
	return m_arrTop == m_maxCapacity - 1;
}

int BrowserHistory::CurrentSize() const
{
	return m_arrTop + 1;
}

void BrowserHistory::Clear()
{
	delete[] m_historyArr;
	m_historyArr = nullptr;

	m_arrTop = -1;
}

bool BrowserHistory::AddEntry(const HistoryEntry& histEntry)
{
	if (Full())
	{
		std::cerr << "error : the history is full\n";
		return false;
	}

	m_historyArr[++m_arrTop] = histEntry;

	int monthToIncrement = (int)m_historyArr[m_arrTop].GetDate();
	m_monthsFrequency[monthToIncrement]++;

	return true;
}

bool BrowserHistory::InputEntry()
{
	if (Full())
	{
		std::cerr << "error : the history is full\n";
		return false;
	}

	std::cin >> m_historyArr[++m_arrTop];

	int monthToIncrement = static_cast<int>(m_historyArr[m_arrTop].GetDate());
	m_monthsFrequency[monthToIncrement]++;

	return true;
}

bool BrowserHistory::RemoveLatestEntry()
{
	if (Empty())
	{
		std::cerr << "error : no entries to remove, the history is empty\n";
		return false;
	}

	int monthToDecrement = (int)m_historyArr[m_arrTop].GetDate();
	m_monthsFrequency[monthToDecrement]--;

	// setting the latest entry to a default one, before decrementing the array index
	HistoryEntry defaultEntry = HistoryEntry();
	m_historyArr[m_arrTop] = defaultEntry;

	m_arrTop--;

	return true;
}

void BrowserHistory::PrintAll() const
{
	if (Empty())
	{
		std::cout << "this browser history has no entries, it is empty\n\n";
		return;
	}

	for (int i = 0; i < CurrentSize(); i++)
	{
		std::cout << m_historyArr[i];
	}

	std::cout << '\n';
}

void BrowserHistory::PrintByMonth(int monthToSearch) const
{
	if (Empty())
	{
		std::cout << "this browser history has no entries, it is empty\n\n";
		return;
	}

	if (monthToSearch < 1 || monthToSearch > 12)
	{
		std::cerr << "error : enter a valid month to search in\n";
		return;
	}

	Month inputMonth = static_cast<Month>(monthToSearch);
	int monthCounter = 0;

	std::cout << "Searching for sites ..." << '\n';

	for (int i = 0; i < CurrentSize(); i++)
	{
		if (m_historyArr[i].m_date == inputMonth)
		{
			std::cout << m_historyArr[i];
			monthCounter++;
		}
	}

	if (monthCounter == 0)
	{
		std::cout << "No sites have been visited at that time\n\n";
	}
	else
	{
		std::cout << monthCounter << " sites have been visited in " << monthToSearch << "\n\n";
	}
}

void BrowserHistory::MostActiveMonth() const
{
	if (Empty())
	{
		std::cout << "This browser history has no entries, it is empty\n\n";
		return;
	}

	int mostVisitedMonth = 0;
	int frequencyCount = m_monthsFrequency[0];

	for (int i = 1; i < 13; i++)
	{
		if (m_monthsFrequency[i] >= frequencyCount)
		{
			frequencyCount = m_monthsFrequency[i];
			mostVisitedMonth = i;
		}
	}

	PrintByMonth(mostVisitedMonth);
}

BrowserHistory BrowserHistory::Concatenate(const BrowserHistory& otherBrowser)
{
	int concatenatedCapacity = this->m_maxCapacity + otherBrowser.m_maxCapacity;
	BrowserHistory concatenationBrowser = BrowserHistory(concatenatedCapacity);

	for (int i = 0; i < this->CurrentSize(); i++)
		concatenationBrowser.AddEntry(this->m_historyArr[i]);

	for (int j = 0; j < otherBrowser.CurrentSize(); j++)
		concatenationBrowser.AddEntry(otherBrowser.m_historyArr[j]);

	return concatenationBrowser;
}
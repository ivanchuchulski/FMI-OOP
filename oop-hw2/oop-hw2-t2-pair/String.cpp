#include "String.h"

#include <cstring>

String::String()
	:	m_capacity(M_CAPACITY_DEFAULT),
		m_length(0),
		m_data(nullptr)
{
	DefaultAllcocate();
}

String::String(const String& other)
	:	m_capacity(other.m_capacity),
		m_length(0),
		m_data(nullptr)
{
	if (other.Empty())
		DefaultAllcocate();
	else
		CopyOtherString(other);
}

String::String(const char* str)
	:	m_capacity(M_CAPACITY_DEFAULT),
		m_length(0),
		m_data(nullptr)
{
	if (str == nullptr)
	{
		DefaultAllcocate();
		return;
	}

	int len = std::strlen(str);

	m_capacity = len + (len / 2) + 1;
	m_length = len;
	m_data = new char[static_cast<size_t>(m_capacity) + 1];

	std::memset(m_data, 0, static_cast<size_t>(m_capacity) + 1);
	std::memcpy(m_data, str, static_cast<size_t>(len) + 1);
}

String::~String()
{
	ClearContents();
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		ClearContents();

		if (other.Empty())
			DefaultAllcocate();
		else
			CopyOtherString(other);
	}

	return *this;
}

// private helper methods
void String::ClearContents()
{
	if (m_data != nullptr)
	{
	//	std::cout << "cleaning " << m_data << '\n';

		delete[] m_data;
		m_data = nullptr;
	}
}

void String::DefaultAllcocate()
{
	m_capacity = M_CAPACITY_DEFAULT;
	m_length = 0;
	m_data = new char[static_cast<size_t>(m_capacity) + 1];

	std::memset(m_data, 0, static_cast<size_t>(m_capacity) + 1);
}

void String::CopyOtherString(const String& other)
{
	m_capacity = other.m_capacity;
	m_length = other.m_length;
	m_data = new char[static_cast<size_t>(m_capacity) + 1] {};

	std::memset(m_data, 0, static_cast<size_t>(m_capacity) + 1);

//	std::memcpy(m_data, other.m_data, (static_cast<size_t>(m_capacity) + 1) * sizeof(char));

	for (int i = 0; i < m_length; i++)
	{
		m_data[i] = other.m_data[i];
	}

}

void String::Grow()
{
	int newCapacity = m_capacity  + (m_capacity / 2);
	char* newData = new char[static_cast<size_t>(newCapacity) + 1];

	std::memset(m_data, 0, static_cast<size_t>(m_capacity) + 1);

	for (int i = 0; i < Length(); i++)
		newData[i] = m_data[i];

	delete[] m_data;
	
	m_capacity = newCapacity;
	m_data = newData;
}

bool String::Full() const
{
	return m_length == m_capacity;
}


// element access
char& String::At(int index)
{
	if (index < 0 && index >= m_length)
		throw std::out_of_range("error : index out of range\n");

	return m_data[index];
}

const char& String::At(int index) const
{
	if (index < 0 && index >= m_length)
		throw std::out_of_range("error : index out of range\n");

	return m_data[index];
}


char& String::operator[](int index)
{
	if (index < 0 && index >= m_length)
		throw std::out_of_range("error : index out of range\n");

	return m_data[index];
}

const char& String::operator[](int index) const
{
	if (index < 0 && index >= m_length)
		throw std::out_of_range("error : index out of range\n");

	return m_data[index];
}

char& String::Front()
{
	return m_data[0];
}

const char& String::Front() const
{
	return m_data[0];
}

char& String::Back()
{
	return m_data[m_length - 1];
}

const char& String::Back() const
{
	return m_data[m_length - 1];
}

char* String::Data()
{
	if (Empty())
		return nullptr;

	return m_data;
}

const char* String::Data() const
{
	if (Empty())
		return nullptr;

	return m_data;
}

const char* String::CStr() const
{
	if (Empty())
		return nullptr;

	return m_data;
}

// capacity and size
bool String::Empty() const
{
	return m_length == 0;
}


int String::Length() const
{
	return m_length;
}

int String::Size() const
{
	return m_length;
}

int String::Capacity() const
{
	return m_capacity;
}

// operations
void String::Clear()
{
	ClearContents();
	DefaultAllcocate();
}

//void String::Insert(size_t index, char symbol)
//{
//	if (index > Size())
//		throw std::out_of_range("error : Insert, index out of range");
//
//	//TODO
//}

void String::PushBack(char symbol)
{
	if (Full())
		Grow();

	m_data[m_length++] = symbol;
}

void String::PopBack(char symbol)
{
	if (Empty())
		throw std::exception("error : PopBack on empty string");

	m_length--;
}


void String::Append(char symbol)
{
	PushBack(symbol);
}

// operator overloads
bool String::operator==(const String& right) const
{
	if (Empty() || right.Empty())
		return false;

	else if (Length() != right.Length())
		return false;

	for (int i = 0; i < Length(); i++)
	{
		if (m_data[i] != right.m_data[i])
		{
			return false;
		}
	}

	return true;
}

// friend methods
std::ostream& operator<<(std::ostream& outStream, const String& str)
{

	auto addr = &(str.m_data);
	outStream << addr << ' ';

	outStream << str.m_data;
	
	return outStream;
}

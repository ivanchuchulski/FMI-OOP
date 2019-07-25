#include "MyString.h"

const size_t CAPACITY_DEFAULT= 3;
const size_t LENGTH_DEFAULT = 0;
const char DATA_DEFAULT[CAPACITY_DEFAULT] = "**";
 

void ich::MyString::Expand()
{
}


/*default ctor*/
ich::MyString::MyString()
	:	m_Capacity(CAPACITY_DEFAULT),
		m_Length(LENGTH_DEFAULT),
		m_Data(nullptr)
{
	m_Data = new char[m_Capacity];
	memset(m_Data, '\0', m_Capacity);
	memcpy_s(m_Data, m_Length, DATA_DEFAULT, m_Length);
}


ich::MyString::MyString(const MyString& someString)
	:	m_Capacity(someString.m_Capacity),
		m_Length(someString.m_Length),
		m_Data(nullptr)
{
	m_Data = new char[m_Capacity];
	memset(m_Data, '\0', m_Capacity);				//nullifying
	memcpy(m_Data, someString.m_Data, m_Length);

}


ich::MyString::MyString(const char* str)
	:	m_Capacity(CAPACITY_DEFAULT),
		m_Length(LENGTH_DEFAULT),
		m_Data(nullptr)
{
	if (str == nullptr) {
		m_Data = new char[m_Capacity];
		memset(m_Data, '\0', m_Capacity);
		memcpy_s(m_Data, m_Length, DATA_DEFAULT, m_Length);
	}
	else {
		m_Length = strlen(str);
		m_Capacity = m_Length + 1;
		m_Data = new char[m_Length + 1];

		memset(m_Data, '\0', m_Capacity);
		memcpy_s(m_Data, m_Length, str, m_Length);
	}

}

/*dtor*/
ich::MyString::~MyString()
{
	if (m_Data) {
		delete[] m_Data;
	}
}

/*copy=*/
ich::MyString& ich::MyString::operator=(const MyString& someString)
{
	if (this != &(someString)) {
		//free memory if needed
		if (m_Data) {
			delete[] m_Data;
		}

		//copy new data
		m_Capacity = someString.m_Capacity;
		m_Length = someString.m_Length;

		m_Data = new char[m_Capacity];
		memset(m_Data, '\0', m_Capacity);				//nullifying
		memcpy(m_Data, someString.m_Data, m_Length);

	}

	return *this;		// TODO: insert return statement here
}

const char * ich::MyString::GetData() const
{
	return m_Data;
}

size_t ich::MyString::Length() const
{
	return m_Length;
}

void ich::MyString::Clear()
{
	if (m_Data) {
		delete[] m_Data;
	}
	m_Capacity = 0;
	m_Length = 0;

}

bool ich::MyString::IsEmpty() const
{
	return (m_Length == 0);
}

char& ich::MyString::operator[](size_t index)
{
	if (index < m_Length) {
		return m_Data[index];
	}

	throw std::out_of_range("Index out of range!\n");
}

const char & ich::MyString::operator[](size_t index) const
{
	if (index < m_Length) {
		return m_Data[index];
	}

	throw std::out_of_range("Index out of range!\n");
}



bool ich::operator<(const MyString & lhs_string, const MyString & rhs_string)
{
	if (strcmp(lhs_string.m_Data, rhs_string.m_Data) < 0)
	{
		return true;
	 }
	else {
		return false;
	}
}

bool ich::operator>(const MyString & lhs_string, const MyString & rhs_string)
{
	return !(lhs_string < rhs_string);
}

bool ich::operator==(const MyString & lhs_string, const MyString & rhs_string)
{
	return (strcmp(lhs_string.m_Data, rhs_string.m_Data) == 0);
}
#pragma once
#include <iostream>
#include <string>

class Widget
{
private:
	std::string m_Name;

public:

	Widget()
		: m_Name{}
	{}

	Widget(const Widget& other)
		:	m_Name {other.m_Name}
	{}

	Widget(const std::string& str)
		: m_Name{ str }
	{}

	~Widget()
	{}

	Widget& operator=(const Widget& other) 
	{
		if (this != &(other))
			m_Name = other.m_Name;

		return *(this);
	}

	void PrintName() const 
	{
		std::cout << "widget name : " << m_Name << '\n';
	}

	void SetName(const std::string& name)
	{
		m_Name = name;
	}


	friend std::ostream& operator<<(std::ostream& outS, const Widget& obj)
	{
		outS << obj.m_Name << '\n';

		return outS;
	}

	friend std::istream& operator>>(std::istream& inS, Widget& obj)
	{
		inS >> obj.m_Name;

		return inS;
	}


};
















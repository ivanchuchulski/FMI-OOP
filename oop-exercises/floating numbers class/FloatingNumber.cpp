#include <cmath>

#include "floatNumberClass.h"


FloatingNum::FloatingNum()
	: 	m_signif(123), 
		m_base(10), 
		m_exponent(-3) 
{}


FloatingNum::FloatingNum(int u_significant, int u_base, int u_exponent)
	:	m_signif(u_significant), 
		m_base(u_base), 
		m_exponent(u_exponent) 
{}

FloatingNum::FloatingNum(const FloatingNum& other)
	:	m_signif(other.m_signif), 
		m_base(other.m_base),
		m_exponent(other.m_exponent) 
{}

/*destructor*/
FloatingNum::~FloatingNum() 
{}

int FloatingNum::GetSignif() const 
{
	return m_signif;
}

int FloatingNum::GetBase() const 
{
	return m_base;
}

int FloatingNum::GetExponent() const 
{
	return m_exponent;
}


void FloatingNum::SetSignif(int signif) 
{
	m_signif = signif;
}

void FloatingNum::SetBase(int base) 
{
	m_base = base;
}

void FloatingNum::SetExponent(int exponent) 
{
	m_exponent = exponent;
}


void FloatingNum::Print(std::ostream& out) const 
{
	out << *(this);
}

//mutator function
void FloatingNum::ReadFromUser() 
{
	std::cin >> m_signif;
	std::cin.ignore(10,';');	//separation
	std::cin >> m_base;
	std::cin.ignore(10, ';');
	std::cin >> m_exponent;
}


std::ostream& operator<<(std::ostream& out, const FloatingNum& other) 
{
	out << "significant : " << other.m_signif << '\n';
	out << "base : " << other.m_base << '\n';
	out << "exponent" << other.m_exponent << '\n';

	// TODO: insert return statement here
	return out;
}

std::istream& operator>>(std::istream& in, FloatingNum& other) 
{
	std::cout << "Enter significant : ";
	in >> other.m_signif;
	//in.ignore();
	std::cout << "Enter base : ";
	in >> other.m_base;

	std::cout << "Enter exponent";
	in >> other.m_exponent;

	// TODO: insert return statement here
	return in;
}



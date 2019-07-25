
#ifndef FLOATING_NUM_H
#define FLOATING_NUM_H

#include <iostream>

class FloatingNum 
{
private:
	int m_signif;
	int m_base;
	int m_exponent;

public:
	FloatingNum();
	FloatingNum(const FloatingNum& other);
	FloatingNum(int u_significant, int u_base, int u_exponent);
	~FloatingNum();

	int GetSignificant() const;
	int GetExponent() const;
	int GetBase() const;

	void SetSignif(int signif);
	void SetBase(int base);
	void SetExponent(int exponent);

	void Print(std::ostream& out = std::cout) const;
	void ReadFromUser();

	FloatingNum operator+ (const FloatingNum& other);

	friend std::ostream& operator<<(std::ostream& out, const FloatingNum& other);
	friend std::istream& operator>>(std::istream& in, FloatingNum& other);
};


#endif
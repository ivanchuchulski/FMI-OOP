#pragma once


class Polynomial {

private:
	int m_Degree;
	int m_ArrSize;
	float* m_Coefs;	

protected:
	float* SetCoefs(int sizeCoefs, const float* sourceCoefs = nullptr);
	//float* SetCoefs(int firstSize, const float* firstSource, int secondSize, const float* secondSource);

public:
	/*constructors*/
	Polynomial();
	Polynomial(int degree, float* coefs);
	Polynomial(const Polynomial& somePoly);

	//ctor used in the addition of polynomials
	Polynomial(char operation ,int highestDegree, const Polynomial* lhsPoly, const Polynomial* rhsPoly);

	/*destructor*/
	~Polynomial();

	Polynomial& operator=(const Polynomial& somePoly);


	/*finds the value of the polynomial, by pluging in the input */
	float GetValue(float point);

	Polynomial operator+(const Polynomial& rhsPoly);
//	friend Polynomial operator+(const Polynomial& lhsPoly, const Polynomial& rhsPoly);

	Polynomial operator*(const Polynomial& rhsPoly);

};



/*notes : 
	_> the m_Coefs array indices represent coeficients in front of the polynomial variable degrees


*/
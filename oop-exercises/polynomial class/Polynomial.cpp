#include "Polynomial.h"
#include <string.h>



int powerFunc(int num, int power) {
	int result = 1;

	//handling zero case
	if (power == 0)
		return 1;

	//looping to calculate the power (product)
	for (int i = 1; i <= power; i++) {
		result = result * num;
	}

	return result;
}

/*class Polynomial methods definitions*/
#pragma region

float* Polynomial::SetCoefs(int sizeOfCoefs, const float* sourceCoefs) {
	float* bufferPtr = nullptr;

	if (sourceCoefs != nullptr && sizeOfCoefs > 0) {
		bufferPtr = new float[sizeOfCoefs];
		//memcpy_s(bufferPtr, sizeOfCoefs * sizeof(float), sourceCoefs, sizeOfCoefs * sizeof(float));
		for (int i = 0; i < sizeOfCoefs; i++) {
			bufferPtr[i] = sourceCoefs[i];
		}
		return bufferPtr;
	}
	else {
		bufferPtr = new float[sizeOfCoefs];
		//setting all the values to -1
		for (int k = 0; k < sizeOfCoefs; k++) {
			bufferPtr[k] = -1.0f;
		}
		return bufferPtr;
	}
}


Polynomial::Polynomial()
	:	m_Degree(5),
		m_ArrSize(5 + 1),
		m_Coefs(SetCoefs(m_ArrSize))
{}


Polynomial::Polynomial(int degree, float* coefs)
	:	//m_Degree((degree > 0) ? degree : -degree),
		m_Degree(0),
		m_ArrSize(1),
		m_Coefs(nullptr)

{
	if (degree > -1 && coefs != nullptr) {
		m_Degree = degree;
		m_ArrSize = m_Degree + 1;
		m_Coefs = SetCoefs(m_ArrSize, coefs);
	
	}
	else if (degree > -1 && coefs == nullptr) {
		m_Degree = degree;
		m_ArrSize = m_Degree + 1;
		m_Coefs = SetCoefs(m_ArrSize);
	}

	else {
		m_Degree = 5;
		m_ArrSize = m_Degree + 1;
		m_Coefs = SetCoefs(m_ArrSize);
	}
}

Polynomial::Polynomial(const Polynomial& somePoly)
	:	m_Degree(somePoly.m_Degree),
		m_ArrSize(somePoly.m_ArrSize),
		m_Coefs(SetCoefs(somePoly.m_ArrSize,somePoly.m_Coefs))

{}

Polynomial::~Polynomial() {
	//if (m_Coefs != nullptr) {
		delete[] m_Coefs;
		//m_Coefs = nullptr;
	//}
}


Polynomial& Polynomial::operator=(const Polynomial& somePoly) {
	if (this != &somePoly) {
		//free current memory
		if (m_Coefs != nullptr) {
			delete[] m_Coefs;
			m_Coefs = nullptr;
		}
		//copy the data
		m_Degree = somePoly.m_Degree;
		m_ArrSize = somePoly.m_ArrSize;
		m_Coefs = SetCoefs(somePoly.m_ArrSize, somePoly.m_Coefs);

	}
	return *this;		// TODO: insert return statement here
}



float Polynomial::GetValue(float point) {
	float result = 0;

	for (int i = 0; i < m_ArrSize; i++) {

		/*that was the other representation of the coeficients
			result = result +  m_Coefs[i] * powerFunc(point, m_ArrSize - i - 1);
		*/

		result = result + m_Coefs[i] * powerFunc(point, i);
	}

	return result;
}


Polynomial Polynomial::operator+(const Polynomial& rhsPoly) {

	if (this->m_Degree == rhsPoly.m_Degree) {
		return Polynomial('+', this->m_Degree, this, &rhsPoly);
	}

	else if(this->m_Degree > rhsPoly.m_Degree) {
		return Polynomial('+',this->m_Degree, this, &rhsPoly);
	}
	else {
		//this->m_Degree < rhsPoly.m_Degree
		return Polynomial('+', rhsPoly.m_Degree, this, &rhsPoly);
	}
}

Polynomial Polynomial::operator*(const Polynomial & rhsPoly)
{
	return Polynomial();
}


Polynomial::Polynomial(char operation, int highestDegree, const Polynomial* lhsPoly, const Polynomial* rhsPoly)
	:	m_Degree(highestDegree),
		m_ArrSize(highestDegree + 1),
		m_Coefs(SetCoefs(m_ArrSize))
{

	if (operation == '+') {

		/*first case, both polynomials have the same degree*/
		if (highestDegree == lhsPoly->m_Degree == rhsPoly->m_Degree) {
			for (int i = 0; i < m_ArrSize; i++) {
				m_Coefs[i] = lhsPoly->m_Coefs[i] + rhsPoly->m_Coefs[i];
			}
		}

		/*the left-handside poly has a higher degree*/
		else if (highestDegree == lhsPoly->m_Degree) {
			//first copy all the coefs from rhsPoly, it has a lower degree
			for (int i = 0; i < rhsPoly->m_ArrSize; i++) {
				m_Coefs[i] = rhsPoly->m_Coefs[i] + lhsPoly->m_Coefs[i];
			}
			for (int j = rhsPoly->m_ArrSize; j < lhsPoly->m_ArrSize; j++) {
				m_Coefs[j] = lhsPoly->m_Coefs[j];
			}
		}

		/*the right-handside poly has a higher degree*/
		else if (highestDegree == rhsPoly->m_Degree) {
			//first copy all the coefs from lhsPoly, it has a lower degree
			for (int i = 0; i < lhsPoly->m_ArrSize; i++) {
				m_Coefs[i] = lhsPoly->m_Coefs[i] + rhsPoly->m_Coefs[i];
			}
			for (int j = lhsPoly->m_ArrSize; j < rhsPoly->m_ArrSize; j++) {
				m_Coefs[j] = rhsPoly->m_Coefs[j];
			}
		}
	}





}

#pragma endregion
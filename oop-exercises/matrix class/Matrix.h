#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>

class Matrix 
{
private:
	static const int MAX_SIZE = 3;
	float m_matrix[MAX_SIZE][MAX_SIZE];

public:
	Matrix();
	Matrix(const Matrix& otherObj);
	Matrix(const float* const outMatrix);
	~Matrix();

	Matrix& operator=(const Matrix& otherObj);

	friend std::ostream& operator<<(std::ostream& outStream, const Matrix& obj);

	/*setter*/
	void setMatrix(const float* const otherMatrix);

	/*getter*/
	float** getMatrix() const;

	Matrix& scalarMultiply(float number);


};

#endif
#include <iomanip>
#include <string.h>
#include "Matrix.h"


Matrix::Matrix() {
	//nullifying the matrix by default

	int i = 0;
	int j = 0;
	for (i = 0; i < MAX_SIZE; ++i) {

		float* const row_current = this->m_matrix[i];
		for (j = 0; j < MAX_SIZE; ++j) {
			row_current[j] = 0.0f;
		}
	}

	//std::memset(this->m_matrix, 0, MAX_SIZE * MAX_SIZE * sizeof(float));
}

Matrix::Matrix(const float* const otherMatrix) {

	/*		here i use the input as a T* pointer and do the magic		*/

	/*handling null pointer case*/
	if (otherMatrix == nullptr) {

		int i = 0;
		int j = 0;
		while (i < MAX_SIZE) {
			while (j < MAX_SIZE) {
				this->m_matrix[i][j] = 0;
				j++;
			}
			j = 0;
			i++;
		}

		/*	in case of a string maybe	*/
		//std::memset(this->m_matrix, 0, MAX_SIZE * MAX_SIZE * sizeof(float));

		return;
	}
	else {

		int i = 0;
		int j = 0;
		while (i < MAX_SIZE) {
			
			float* const row_current =(float*)(this->m_matrix) + i*MAX_SIZE;
			const float* const row_other = otherMatrix + i * MAX_SIZE;

			while (j < MAX_SIZE) {

			//	*((float*)this->m_matrix + i*MAX_SIZE + j) = *(outMatrix_ptr + i*MAX_SIZE + j);
			//	this->m_matrix[i][j] = *(outMatrix_ptr + i*MAX_SIZE + j);

				row_current[j] = row_other[j];

			/*	in case of a string maybe	*/
			//	std::memcpy(((float*)this->m_matrix + i*MAX_SIZE + j), (outMatrix_ptr + i*MAX_SIZE + j), sizeof(float));
				j++;
			}
			j = 0;
			i++;
		}

		/*less safe*/
		//std::memcpy(this, outMatrix, MAX_SIZE * MAX_SIZE * sizeof(float));
	}
}

/*		copy ctor		*/
Matrix::Matrix(const Matrix& otherObj)	{
	/*		m_matrix is T** pointer and do the magic		*/

	//evuilevent to this pointer of otherObj
	const Matrix* const ptr_other = &otherObj;

	int i = 0;
	int j = 0;

	for (i = 0; i < MAX_SIZE; i++) {

		float* row_current = this->m_matrix[i];
		const float* row_other = ptr_other->m_matrix[i];
	
		for (j = 0; j < MAX_SIZE; j++) {

		//	*((float*)this->m_matrix + i*MAX_SIZE + j) = *((float*)ptr_other->m_matrix + i*MAX_SIZE + j);
		//	this->m_matrix[i][j] = ptr_other->m_matrix[i][j];
		//	this->m_matrix[i][j] = otherObj.m_matrix[i][j];

			row_current[j] = row_other[j];
		}
	}

}

/*		dtor		*/
Matrix::~Matrix() {
}

/*		copy assignment operator		*/
Matrix& Matrix::operator=(const Matrix& otherObj) {

	/*check to not assign the same object to itself*/
	if (this != &otherObj) {

		int i = 0;
		int j = 0;

		for (i = 0; i < MAX_SIZE; ++i) {

		/*	float* row_current = (float*)(this->m_matrix + i);		other variant, strange, not good*/
			float* row_current = this->m_matrix[i];
			const float* row_other = otherObj.m_matrix[i];

			for (j = 0; j < MAX_SIZE; ++j) {
				row_current[j] = row_other[j];
			}
		}
	}

	return *this;			// TODO: insert return statement here
}


std::ostream& operator<<(std::ostream& outStream, const Matrix& obj) {
	
	int i = 0; 
	int j = 0;
	for (i = 0; i < obj.MAX_SIZE; ++i) {
		for (j = 0; j < obj.MAX_SIZE; ++j) {
			outStream << std::setw(10) << obj.m_matrix[i][j] << " ";
		}
		outStream << '\n';
	}
	/*	a new line for visabillity	*/
	outStream << '\n';

	return outStream;	// TODO: insert return statement here

}

/*		setter method		*/
void Matrix::setMatrix(const float* const otherMatrix) {

	int i = 0;
	int j = 0;

	if (otherMatrix == nullptr) {
		for (i = 0; i < MAX_SIZE; ++i) {
			for (j = 0; j < MAX_SIZE; ++j) {
				this->m_matrix[i][j] = 0;
			}
		}
	}

	else {
		for (i = 0; i < MAX_SIZE; ++i) {

			float* const row_current = (float*)(this->m_matrix) + i*MAX_SIZE;
			const float* const row_other = otherMatrix + i*MAX_SIZE;

			for (j = 0; j < MAX_SIZE; ++j) {
				row_current[j] = row_other[j];
			}
		}

	}
}

/*	ToDo -> need to implement	*/
float ** Matrix::getMatrix() const
{

	return nullptr;
}

Matrix& Matrix::scalarMultiply(float number) {

	int i = 0;
	int j = 0;
	for (i = 0; i < MAX_SIZE; ++i) {

		float* const row_current = this->m_matrix[i];

		for (j = 0; j < MAX_SIZE; ++j) {
			row_current[j] *= number;
		}
	}
	
	return *this;
}
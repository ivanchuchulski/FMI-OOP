#pragma once

#include "HomogPoint.h"

class SetOfPoints 
{
private:
	const int DEFAULT_MAX_SIZE = 5;

private:
	int m_Size;
	int m_CurrentSize;
	HomogPoint ** m_PointSet;

private:
	void Expand();
	void Clear();

public:
	/*constructors*/
	SetOfPoints();
	SetOfPoints(const SetOfPoints& somePoints);

	SetOfPoints(int N);

	/*destructor*/
	~SetOfPoints();

	/*copy assignment*/
	SetOfPoints& operator=(const SetOfPoints& somePoints);

	void AddPoint(const HomogPoint& somePoint);


};


#include "SetOfPoints.h"


/*default ctor*/
SetOfPoints::SetOfPoints()
	: m_Size(DEFAULT_MAX_SIZE),
	m_CurrentSize(0),
	m_PointSet(nullptr)
{
	//making m_Size pointers on the heap, and setting them to null
	m_PointSet = new HomogPoint*[m_Size] {nullptr};
	//setting each pointer to null
	//for (int i = 0; i < m_Size; i++) { m_PointSet[i] = nullptr; }

}

/*copy ctor*/
SetOfPoints::SetOfPoints(const SetOfPoints & somePoints)
	:	m_Size(somePoints.m_Size),
		m_CurrentSize(somePoints.m_CurrentSize),	
		m_PointSet(nullptr)
{

	m_PointSet = new HomogPoint*[m_Size] {nullptr};

	if (m_CurrentSize > 0) {
		for (int i = 0; i < m_CurrentSize; i++) {
			m_PointSet[i] = new HomogPoint(*(somePoints.m_PointSet[i]));
		}
	}
	//else {
	//	for (int i = 0; i < m_Size; i++) { m_PointSet[i] = nullptr; }
	//}
}

/*ctor with params*/
SetOfPoints::SetOfPoints(int N)
	:	m_Size((N > 0)? N : DEFAULT_MAX_SIZE),
		m_CurrentSize(0),
		m_PointSet(nullptr)
{

	m_PointSet = new HomogPoint*[m_Size] {nullptr};
	//for (int i = 0; i < m_Size; i++) { m_PointSet[i] = nullptr; }
}


/*destructor*/
SetOfPoints::~SetOfPoints()
{
	if (m_PointSet != nullptr)
	{
		for (int i = 0; i < m_CurrentSize; i++) {
			//calling the dtor for each object
			delete m_PointSet[i];
		}

		//deleting the pointers on the heap
		delete[] m_PointSet;
	}
}

/*copy=*/
SetOfPoints & SetOfPoints::operator=(const SetOfPoints & somePoints)
{
	if (this != &(somePoints)) 
	{
		//free current memory
		Clear();

		//copy new data
		m_Size = somePoints.m_Size;
		m_CurrentSize = somePoints.m_CurrentSize;

		//allocating pointers on the heap and setting them to null
		m_PointSet = new HomogPoint*[m_Size] {nullptr};

		if (m_CurrentSize > 0) {
			for (int i = 0; i < m_CurrentSize; i++) {
				m_PointSet[i] = new HomogPoint(*(somePoints.m_PointSet[i]));
			}
		}
	}

	return *this;		// TODO: insert return statement here
}

void SetOfPoints::AddPoint(const HomogPoint & somePoint)
{
	if (m_CurrentSize == m_Size)
	{
		//expand
		Expand();
		m_PointSet[m_CurrentSize++] = new HomogPoint(somePoint);
	}

	else {
		//copy ctor of HomogPoint
		m_PointSet[m_CurrentSize++] = new HomogPoint(somePoint);
	}
}

void SetOfPoints::Expand()
{
	int expRate = 5;

	HomogPoint ** ToMake = new HomogPoint*[m_Size + expRate];
	
	for (int i = 0; i < m_CurrentSize; i++)
	{
		ToMake[i] = new HomogPoint(*(m_PointSet[i]));
	}

	Clear();

	m_Size += expRate;
	m_PointSet = ToMake;

}

void SetOfPoints::Clear()
{
	if (m_PointSet != nullptr)
	{
		for (int i = 0; i < m_CurrentSize; i++) {
			//calling the dtor for each object
			delete m_PointSet[i];
		}

		//deleting the pointers on the heap
		delete[] m_PointSet;
	}
}
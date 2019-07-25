#include "HomogPoint.h"


HomogPoint::HomogPoint()
	:	m_X(0.0f),
		m_Y(0.0f),
		m_Z(0.0f),
		m_T(1.0f),
		m_ArrForm {m_X, m_Y, m_Z, m_T}

{}


HomogPoint::HomogPoint(const HomogPoint & somePoint)
	:	m_X(somePoint.m_X),
		m_Y(somePoint.m_Y),
		m_Z(somePoint.m_Z),
		m_T(somePoint.m_T),
		m_ArrForm{ somePoint.m_X, somePoint.m_Y, somePoint.m_Z, somePoint.m_T }
{
}

HomogPoint::HomogPoint(HomogPoint && somePoint)
{
}

HomogPoint::HomogPoint(const float x, const float y, const float z, const float t)
	:	m_X(x),
		m_Y(y),
		m_Z(z),
		m_T((x != 0 && y != 0 && z != 0)? t : 1),
		m_ArrForm{ m_X, m_Y, m_Z, m_T }
{
}

HomogPoint & HomogPoint::operator=(const HomogPoint & somePoint)
{
	if (this != &(somePoint)) {
		m_X = somePoint.m_X;
		m_Y = somePoint.m_Y;
		m_Z = somePoint.m_Z;
		m_T = somePoint.m_T;
		for(int i = 0; i < 4; i++)
		{
			m_ArrForm[i] = somePoint.m_ArrForm[i];
		}

	}

	return *this;		// TODO: insert return statement here
}

HomogPoint::~HomogPoint()
{
}

HomogPoint & HomogPoint::operator+(const HomogPoint& rhs) const
{
	// TODO: insert return statement here
	return HomogPoint(m_X + rhs.m_X, m_Y + rhs.m_Y, m_Z + rhs.m_Z, m_T + rhs.m_T);

}


void HomogPoint::ModX(const float modify_X)
{
	m_X += modify_X;
}

void HomogPoint::ModY(const float modify_Y)
{
	m_Y += modify_Y;
}

void HomogPoint::ModZ(const float modify_Z)
{
	m_Z += modify_Z;
}

void HomogPoint::ModT(const float modify_T)
{
	m_T += modify_T;
}
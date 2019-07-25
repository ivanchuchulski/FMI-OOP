#pragma once


class HomogPoint
{
private:
	float m_X;
	float m_Y;
	float m_Z;
	float m_T;
	float m_ArrForm[4];

public:
	/*constructors*/
	HomogPoint();
	HomogPoint(const HomogPoint& somePoint);	
	HomogPoint(HomogPoint && somePoint) = default;

	HomogPoint(const float x, const float y, const float z, const float t);

	/*destructor*/
	~HomogPoint();

	HomogPoint& operator=(const HomogPoint& somePoint);

	void ModX(const float modify_X);
	void ModY(const float modify_Y);
	void ModZ(const float modify_Z);
	void ModT(const float modify_T);

	HomogPoint& operator+(const HomogPoint& rhs) const;

};


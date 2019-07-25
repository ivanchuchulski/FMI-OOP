#pragma once

class Point {

private:
	double m_X;
	double m_Y;

	//igonring small differences
	const double EPSILON = 0.000001;
	bool doublesAreEqual(double first, double second);

public:

	//constructors
	Point();
	Point(double x, double y);

	//setters
	void setX(double x);
	void setY(double y);

	//getters
	double getX() const;
	double getY() const;

	void print() const;

	void move(double dX, double dY);

	double getDistance(Point other) const;

	bool operator> (Point other);
	bool operator== (Point other);

	Point operator+ (Point other);
	Point operator+ (int translateAmount);			//overloading the function above

	Point operator- (Point otherObj);

};

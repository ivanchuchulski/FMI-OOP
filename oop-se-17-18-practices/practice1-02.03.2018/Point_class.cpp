#include <iostream>
#include <math.h>
#include "Point_class.h"

//		definition of constructors
Point::Point() {
	m_X = 0;
	m_Y = 0;
}

Point::Point(double x, double y) {
	m_X = x;
	m_Y = y;
}

//		definition of other methods

void Point::setX(double x) {
	m_X = x;
}

void Point::setY(double y) {
	m_Y = y;
}

double Point::getX() const {
	return m_X;
}

double Point::getY() const {
	return m_Y;
}


void Point::print() const {
	//std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
	std::cout << '(' << getX() << ", " << getY() << ')' << std::endl;
}

void Point::move(double dX, double dY) {
	m_X += dX;
	m_Y += dY;
}

// getting the distance from Point otherObj
double Point::getDistance(Point otherObj) const {
	return sqrt(pow(m_X - otherObj.m_X, 2) + pow(m_Y - otherObj.m_Y, 2));
}

//check for small differences
bool Point::doublesAreEqual(double first, double second) {
	//if the difference is smaller than EPSILON -> return true
	return (abs(first - second) < Point::EPSILON);
}

// behavior of the operator '>' for Point objects
bool Point::operator> (Point otherObj) {
	return (m_X > otherObj.m_X && m_Y > otherObj.m_Y);
}

// behavior of the operator '==' for Point objects
bool Point::operator== (Point other) {
	//EPSILON is needed to correctly compare values
	return (doublesAreEqual(m_X, other.m_X) &&
			doublesAreEqual(m_Y, other.m_Y));
}

/* behavior of the operator '+' for Point objects := 
	creates new Point obj and adds the values of the parameter */
Point Point::operator+(Point otherObj) {
	//calling the constructor to create an object
	return Point(m_X + otherObj.m_X, m_Y + otherObj.m_Y);
}

//overloaded version of the function above := adds the passed value 
Point Point::operator+(int translateAmount) {
	//calling the constructor
	return Point(m_X + translateAmount, m_Y + translateAmount);
}

Point Point::operator-(Point otherObj) {
	//calling the constructor
	return Point(m_X - otherObj.m_X, m_Y - otherObj.m_Y);
}
#include <iostream>

/*	Point class definition	*/
class Point 
{
private:
	float m_X;
	float m_Y;
	//static counter :  DECLARATION ONLY!
	static int call_pointDefCtor;

public:
	/*constructors*/
	Point();
	Point(float x, float y);
	Point(const Point& otherObj);

	/*destructors*/
	~Point();
	
	/*copy assignment operator*/
	Point& operator=(const Point& otherObj);

	/*setters*/
	void setX(float x);
	void setY(float y);

	/*getters*/
	float getX() const;
	float getY() const;

	friend std::ostream& operator<<(std::ostream& outStream, const Point& Obj_Point);
	int getPointCount() const;
};

/*	DirectedVector class definition	*/
class DirectedVector 
{
private:
	Point m_Start;
	Point m_End;
public:

	/*constructors*/
	DirectedVector();
	DirectedVector(const Point& StartPoint, const Point& EndPoint);
	DirectedVector(const DirectedVector& otherObj);

	/*desctructor*/
	~DirectedVector();

	/*copy assignment operator*/
	DirectedVector& operator=(const DirectedVector& otherObj);

	void setStart(const Point& otherPoint);
	void setEnd(const Point& otherPoint);

	Point getStart() const;
	Point getEnd() const;

};

void printFunc(Point* pointObj, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << "[" << i << "] = " << pointObj[i] << '\n';
	}
	std::cout << std::endl;
}


int Point::call_pointDefCtor = 0;	//definition of static member variable, it should be done before main
/*		Program entry point		*/
int main() {


	Point a = Point(5.0f, 15.0f);
	Point b = Point(7.0f, 17.0f);
	Point c = Point();
	Point* d = new Point(10.0f, 20.0f);
	Point* e = new Point(*d);
	Point* f = new Point{ *d };

	c = b;


	DirectedVector vec1 = DirectedVector();
	DirectedVector vec2 = DirectedVector(a, b);
	DirectedVector vec3 = DirectedVector(vec2);

	vec1 = vec3;

	DirectedVector vec4 = DirectedVector(vec1.getStart(), vec1.getEnd());

	Point* pointSystem1 = new Point[10]{};						//init with Point default ctor
	Point* pointSystem2 = new Point[5]{ a, b, a, b, c };		//init with Point copy ctor

	Point** ptrArr1 = new Point*[5]{};
	Point** ptrArr2 = new Point*[5]{ nullptr, nullptr, nullptr, nullptr, nullptr };
	Point* ptr = &a;

	printFunc(pointSystem1, 10);
	printFunc(pointSystem2, 5);

	std::cout << c.getPointCount() << '\n';

	/*free up heap allocated memory*/
	delete d;
	delete e;
	delete f;
	delete[10] pointSystem1;
	delete[5] pointSystem2;
	delete[] ptrArr1;
	delete[] ptrArr2;


	std::cin.get();
	return 0;
}


/*		class Point methods definitions		*/
#pragma region

/*defualt ctor*/
Point::Point() {
	call_pointDefCtor++;
	m_X = 1.0f;
	m_Y = 1.0f;
}

/*ctor with parameters*/
Point::Point(float x, float y)
	//_> initializer list
	:	m_X(x),
		m_Y(y)
{
	std::cout << "Called Point param ctor!\n";
}

/*copy ctor*/
Point::Point(const Point& otherObj) {
	m_X = otherObj.m_X;
	m_Y = otherObj.m_Y;
}

/*dtor*/
Point::~Point() {
	std::cout << "You called the Point destructor!\n";
}

/*overloaded copy assignment operator*/
Point& Point::operator=(const Point& otherObj) {
	std::cout << "Point copy operator=\n";

	if (this != &otherObj) {
		m_X = otherObj.m_X;
		m_Y = otherObj.m_Y;
	}

	// TODO: insert return statement here
	return *this;
}

void Point::setX(float x) {
	m_X = x;
}
void Point::setY(float y){
	m_Y = y;
}

float Point::getX() const {
	return m_X;
}
float Point::getY() const {
	return m_Y;
}

std::ostream& operator<<(std::ostream & outStream, const Point & Obj_Point) {

	outStream << "m_X = " << Obj_Point.m_X << ", m_Y = " << Obj_Point.m_Y;

	// TODO: insert return statement here
	return outStream;
}

int Point::getPointCount() const {
	return call_pointDefCtor;
}

#pragma endregion
/*----------------------------------*/


/*		class DirectedVector methods definition	*/
#pragma region

/*defualt ctor*/
DirectedVector::DirectedVector()

	//_>	initializer list -> calling the defualt ctors in class Points
	:	m_Start(), 
		m_End()
{
}

/*ctor with parameters*/
DirectedVector::DirectedVector(const Point& StartPoint, const Point& EndPoint)

	//_>	calling the copy ctor in class Point
	:	m_Start(StartPoint),
		m_End(EndPoint)	
{
}

/*copy ctor*/
DirectedVector::DirectedVector(const DirectedVector& otherObj)

	//_> initializer list -> calling the copy constructor in class Point
	:	m_Start(otherObj.m_Start), 
		m_End(otherObj.m_End)
{
	/*very bad aproach:
		-the objects are created first in the initializer list with Point default ctor
		-then Point copy ctor is called
		-then calls the copy assignment operator of the Point ctor to set the values of the copy ctor
		-the Point obj, created with the default ctor  is destroyed

	m_Start = Point(otherObj.m_Start);
	m_End = Point(otherObj.m_End);
	*/
}

/*destructor*/
DirectedVector::~DirectedVector() {
}

DirectedVector& DirectedVector::operator=(const DirectedVector& otherObj)	{
	if (this != &otherObj) {
		//_> calling the copy assignment operator in Point class
		m_Start = otherObj.m_Start;
		m_End = otherObj.m_End;
	}
	// TODO: insert return statement here
	return *this;
}

void DirectedVector::setStart(const Point& otherPoint)	{
	//calling the copy operator= in class Point
	m_Start = otherPoint;
}

void DirectedVector::setEnd(const Point& otherPoint) {
	//calling the copy operator= in class Point
	m_End = otherPoint;
}

Point DirectedVector::getStart() const {

	/*Point DirectedVector::getStart() { and returning like this does this : 
		-calls Point copy constructor for m_Start
		-uses the newly created object for calculations on the current line(expression)
		-destroys the newly created Point obj
*/
	return m_Start;
}

Point DirectedVector::getEnd() const {
	return m_End;
}

#pragma endregion
/*----------------------------------*/
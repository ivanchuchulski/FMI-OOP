#include <iostream>
#include <string>
#include <vector>

#include "HomogPoint.h"
#include "SetOfPoints.h"
#include "MyString.h"


int main() {

	{
	//	std::string str1("TestString!");

		std::string * str2 = new std::string("test2");

		delete str2;
	}

	/*
	{
		HomogPoint p1(1.0f, 2.0f, 3.0f, 5.0f);
		HomogPoint p2(10.0f, 10.0f, 10.0f, 10.0f);

		HomogPoint p3 = HomogPoint(p1 + p2);

		std::vector<HomogPoint*> pointContainer;
		
		pointContainer.reserve(5);
		pointContainer.emplace_back<HomogPoint*>(new HomogPoint(p1));
		pointContainer.emplace_back(new HomogPoint(p2));

		SetOfPoints set1(5);
		set1.AddPoint(p1);
		set1.AddPoint(p2);

		SetOfPoints set2(set1);
		SetOfPoints set3;

		p1.ModX(15.0f);

		//delete the objects, the vector will clean only the pointers
		for (int i = 0; i < pointContainer.size(); i++) {
			delete pointContainer[i];
		}

	}
	*/

	try
	{

		ich::MyString str1 = ich::MyString("abc");
		
		std::cout << str1[2];
		
		str1 == "puta_de_madre";

	}
	catch (std::exception& exc) {
		std::cout << exc.what();
	}

	std::cin.get();
	return 0;
}
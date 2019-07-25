#include <cstring>
#include "Rod.h"

/*	Class methods definition	*/

//_> default constuctor, no parameters
Rod::Rod()
	: m_Length(1), m_IsAutomatic(true), m_RodMaterial(Unspecified), m_Name(nullptr)
{}

//_> default constructor, with parameters
Rod::Rod(int lenght, bool is_Auto, Material rodMaterial, char* inputName)
	//member initializer list
	:	m_Length(lenght), m_IsAutomatic(is_Auto), m_RodMaterial(rodMaterial), m_Name(nullptr)
{
	//check if the input is empty
	if (inputName != nullptr) {
		int nameLength = (strlen(inputName) + 1);		//adding 1 for terminating '\0'
		m_Name = new char[nameLength];
		strcpy_s(m_Name, nameLength, inputName);
	}
	//else {
	//	m_Name = nullptr;
	//}
}

//_>copy constructor
Rod::Rod(const Rod& otherObj) {

	m_Length = otherObj.m_Length;
	m_IsAutomatic = otherObj.m_IsAutomatic;
	m_RodMaterial = otherObj.m_RodMaterial;
	m_Name = nullptr;		//in case otherObj.m_Name is nullptr

//check if the input is empty
	if (otherObj.m_Name != nullptr) {
		int nameLength = (strlen(otherObj.m_Name) + 1);		//adding 1 for terminating '\0'
		m_Name = new char[nameLength];
		strcpy_s(m_Name, nameLength, otherObj.m_Name);
	}
}

//_> destrutor, frees heap memory if needed
Rod::~Rod() {

	if (m_Name != nullptr) {
		//if it isnot a nullptr, its allocated heap memory => need to be freed
		delete[] m_Name;
	}

}

//_>getters
int Rod::getLeght() const {
	return m_Length;
}

bool Rod::getIsAutomatic() const {
	return m_IsAutomatic;
}

Material Rod::getMaterial() const {
	return m_RodMaterial;
}

char * Rod::getName() const {
	return m_Name;
}

//_>setters
void Rod::setLength(int lenght) {
	m_Length = lenght;
}

void Rod::setIsAutomatic(bool isAuto) {
	m_IsAutomatic = isAuto;
}

void Rod::setMaterial(Material RodMaterial) {
	m_RodMaterial = RodMaterial;
}

void Rod::setName(char * inputName) {

	//guard clause
	if (inputName == nullptr) {
		return;
	}

	if (m_Name != nullptr) {
		delete[] m_Name;
	}

	int nameLength = (strlen(inputName) + 1);		//adding 1 for terminating '\0'
	m_Name = new char[nameLength];
	strcpy_s(m_Name, nameLength, inputName);
}

Rod& Rod::operator=(const Rod & otherObj)
{
	m_Length = otherObj.m_Length;
	m_IsAutomatic = otherObj.m_IsAutomatic;
	m_RodMaterial = otherObj.m_RodMaterial;
	m_Name = nullptr;		//in case otherObj.m_Name is nullptr

	//check if the input is empty
	if (otherObj.m_Name != nullptr) {
		int nameLength = (strlen(otherObj.m_Name) + 1);		//adding 1 for terminating '\0'
		m_Name = new char[nameLength];
		strcpy_s(m_Name, nameLength, otherObj.m_Name);
	}

	// TODO: insert return statement here
	return *this;
}




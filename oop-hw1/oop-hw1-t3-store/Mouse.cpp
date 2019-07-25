#include <iostream>
#include <string.h>
#include "Mouse.h"


/*		class Mouse methods definition		*/
#pragma region

char * Mouse::SetCString(const char* source) {

	char* bufferPtr = nullptr;

	if (source != nullptr) {
		int Len = strlen(source);
		bufferPtr = new char[Len + 1];
		memcpy_s(bufferPtr, Len + 1, source, Len + 1);
		return bufferPtr;
	}
	else {
		bufferPtr = new char[8];
		memcpy_s(bufferPtr, 8, "Unkwown", 8);
		return bufferPtr;
	}

}

/*default ctor*/
Mouse::Mouse()
	:	m_IsWireless(false),
		m_IsBacklit(false),
		m_ButtonsNum(3),
		m_Count(10),
		m_Brand(SetCString()),
		m_Model(SetCString()),
		m_Price(5),
		m_SKU()
{
	memset(m_SKU, '\0', 21);
}

/*ctor with parameters*/
Mouse::Mouse(bool wireless, bool backlit, int buttonsNum, int count, char* sku, char* brand, char* model, float price)
	:	m_IsWireless(wireless),
		m_IsBacklit(backlit),
		m_ButtonsNum(0),
		m_Count(0),
		m_Brand(SetCString(brand)),
		m_Model(SetCString(model)),
		m_Price(0.0f),
		m_SKU()
{	
	memset(m_SKU, '\0', 21);

	if (buttonsNum > 0) {	m_ButtonsNum = buttonsNum;	}
	if (count > 0) { m_Count = count; }
	if (price > 0) { m_Price = price; }


	//setting m_SKU
	if (sku != nullptr) {
		int skuLen = strlen(sku);

		if (skuLen <= 20) {
			//if the len is exacly or less than 20, then copy the whole thing
			for (int i = 0; i < skuLen; i++) {
				m_SKU[i] = sku[i];
			}
			//m_SKU[skuLen] = '\0';
		}
		else {
			//otherwise copy only to the max size of the SKU array
			for (int i = 0; i < 20; i++) {
				m_SKU[i] = sku[i];
			}
			//m_SKU[20] = '\0';
		}
	}
}

/*copy ctor*/
Mouse::Mouse(const Mouse& otherMouse)
	:	m_IsWireless(otherMouse.m_IsWireless),
		m_IsBacklit(otherMouse.m_IsBacklit),
		m_ButtonsNum(otherMouse.m_ButtonsNum),
		m_Count(otherMouse.m_Count),
		m_Brand(SetCString(otherMouse.m_Brand)),
		m_Model(SetCString(otherMouse.m_Model)),
		m_Price(otherMouse.m_Price),
		m_SKU()
{
	memset(m_SKU, '\0', 21);

	//setting m_SKU
	int skuLen = strlen(otherMouse.m_SKU);

	if (skuLen <= 20) {
		//if the len is exacly or less than 20, then copy the whole thing
		for (int i = 0; i < skuLen; i++) {
			m_SKU[i] = otherMouse.m_SKU[i];
		}
		//m_SKU[skuLen] = '\0';
	}
	else {
		//otherwise copy only to the max size of the SKU array
		for (int i = 0; i < 20; i++) {
			m_SKU[i] = otherMouse.m_SKU[i];
		}
		//m_SKU[20] = '\0';
	}
}

/*destructor*/
Mouse::~Mouse() {
	//free memory if needed
	if (m_Brand != nullptr) {
		delete[] m_Brand;
	}
	if (m_Model != nullptr) {
		delete[] m_Model;
	}
}

/*copy assignment operator*/
Mouse& Mouse::operator=(const Mouse& otherMouse) {

	if (this != &otherMouse) {
		//free current memory if needed
		if (m_Brand != nullptr) {
			delete[] m_Brand;
			m_Brand = nullptr;
		}
		if (m_Model != nullptr) {
			delete[] m_Model;
			m_Model = nullptr;
		}

		//setting non-dynamic memory data
		m_IsWireless = otherMouse.m_IsWireless;
		m_IsBacklit = otherMouse.m_IsBacklit;
		m_ButtonsNum = otherMouse.m_ButtonsNum;
		m_Count = otherMouse.m_Count;
		m_Price = otherMouse.m_Price;

		m_Brand = SetCString(otherMouse.m_Brand);
		m_Model = SetCString(otherMouse.m_Model);

		//setting m_SKU
		int skuLen = strlen(otherMouse.m_SKU);

		if (skuLen <= 20) {
			//if the len is exacly or less than 20, then copy the whole thing
			for (int i = 0; i < skuLen; i++) {
				m_SKU[i] = otherMouse.m_SKU[i];
			}
			m_SKU[skuLen] = '\0';
		}
		else {
			//otherwise copy only to the max size of the SKU array
			for (int i = 0; i < 20; i++) {
				m_SKU[i] = otherMouse.m_SKU[i];
			}
			m_SKU[20] = '\0';
		}
	}
	return *this;			// TODO: insert return statement here
}

/*friend functions for console output and input*/
std::ostream& operator<<(std::ostream& outStream, const Mouse& someMouse) {

	//outStream << "\nPrinting a mouse : \n";


	if (someMouse.m_Brand == nullptr || someMouse.m_Model == nullptr) {
		outStream << '\t' << "It is unknown\n";
	}
	else {
		outStream << '\t' << "It is called : " << someMouse.m_Brand << ' ' << someMouse.m_Model << '\n';

		if (someMouse.m_SKU[0] == '\0') {
			outStream << '\t' << "It does not have unique ID \n";
		}
		else {
			outStream << '\t' << "Its unique ID is : " << someMouse.m_SKU << '\n';
		}



		if (someMouse.m_IsWireless == true)
		{
			outStream << '\t' << "It is wireless\n";
		}
		else
		{
			outStream << '\t' << "It is not wireless\n";
		}


		if (someMouse.m_IsBacklit == true)
		{
			outStream << '\t' << "It has backlighting\n";
		}
		else
		{
			outStream << '\t' << "It has not backlighting\n";
		}

		outStream << '\t' << "Number of buttons : " << someMouse.m_ButtonsNum << '\n';

		outStream << '\t' << "There are " << someMouse.m_Count << " units of it\n";
		outStream << '\t' << "Each one costs " << someMouse.m_Price << " euro\n";
	}
	outStream << '\n';

	return outStream;			// TODO: insert return statement here
}

std::istream& operator>>(std::istream& inStream, Mouse& someMouse) {
	int bufferWireless = 0;
	int bufferBacklight = 0;
	int buffferButtons = 0;
	int bufferCount = 0;
	char* bufferSKU = new char[50];
	char* bufferBrand = new char[50];
	char* bufferModel = new char[50];
	float bufferPrice = 0;

	std::cout << "Please input the mouse parameters :\n";

	std::cout << '\t' << "Wireless : ";
	inStream >> bufferWireless;

	std::cout << '\t' << "Backlit : ";
	inStream >> bufferBacklight;

	std::cout << '\t' << "Number of buttons : ";
	inStream >> buffferButtons;

	std::cout << '\t' << "Count : ";
	inStream >> bufferCount;

	std::cout << '\t' << "Price : ";
	inStream >> bufferPrice;

	inStream.ignore();

	std::cout << '\t' << "SKU (max 20 chars) : ";
	inStream.getline(bufferSKU, 50);
	std::cout << '\t' << "Brand : ";
	inStream.getline(bufferBrand, 50);
	std::cout << '\t' << "Model :";
	inStream.getline(bufferModel, 50);

	std::cout << std::endl;

	if (bufferWireless == 0) {
		someMouse.m_IsWireless = false;
	}
	else {
		someMouse.m_IsWireless = true;
	}

	if (bufferBacklight == 0) {
		someMouse.m_IsBacklit = false;
	}
	else {
		someMouse.m_IsBacklit = true;
	}

	//calling the setter methods
	someMouse.setButtonsNum(buffferButtons);
	someMouse.setCount(bufferCount);
	someMouse.setPrice(bufferPrice);
	someMouse.setSKU(bufferSKU);
	someMouse.setBrand(bufferBrand);
	someMouse.setModel(bufferModel);

	//free memory
	delete[] bufferSKU;
	delete[] bufferBrand;
	delete[] bufferModel;

	return inStream;			// TODO: insert return statement here
}

/*setters*/
void Mouse::setButtonsNum(const int buttonsNum) {
	if (buttonsNum > 0) {
		m_ButtonsNum = buttonsNum;
	}
	else {
		m_ButtonsNum = 0;
	}
}

void Mouse::setCount(const int count) {
	if (count > 0) {
		m_Count = count;
	}
	else {
		m_Count = 0;
	}
}

void Mouse::setSKU(const char* SKU) {
	memset(m_SKU, '\0', 21);

	if (SKU != nullptr) {

		int skuLen = strlen(SKU);
		if (skuLen <= 20) {
			for (int i = 0; i < skuLen; i++) {
				m_SKU[i] = SKU[i];
			}
			m_SKU[skuLen] = '\0';
		}
		else {
			for (int i = 0; i < 20; i++) {
				m_SKU[i] = SKU[i];
			}
			m_SKU[20] = '\0';
		}

	}
}
void Mouse::setBrand(const char* brand) {
	//free current memory
	if (m_Brand != nullptr) {
		delete[] m_Brand;
		m_Brand = nullptr;
	}

	m_Brand = SetCString(brand);

}
void Mouse::setModel(const char* model) {
	//free current memory
	if (m_Model != nullptr) {
		delete[] m_Model;
		m_Model = nullptr;
	}

	m_Model = SetCString(model);

}
void Mouse::setPrice(const float price) {
	if (price > 0.0f) {
		m_Price = price;
	}
	else {
		m_Price = 0.0f;
	}
}

/*getters*/
int Mouse::getCount() const {
	return m_Count;
}

const char* Mouse::getSKU() const {
	return m_SKU;
}

const char* Mouse::getBrand() const {
	return m_Brand;
}

const char* Mouse::getModel() const {
	return m_Model;
}

const float Mouse::getPrice() const {
	return m_Price;
}

/*method to change a mouse*/
void Mouse::ModifyMouse() {
	std::cout << "\nModifying...\n";
	std::cin >> *this;
}



#pragma endregion
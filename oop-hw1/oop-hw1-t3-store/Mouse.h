#pragma once

#ifndef MOUSE_CLASS_H
#define MOUSE_CLASS_H

#include <iostream>

/*		class Mouse definition
->the class defines a computer mouse characteristics*/
class Mouse {

/*private member data*/
private:
	bool m_IsWireless;		
	bool m_IsBacklit;
	int m_ButtonsNum;
	int m_Count;			//how many mice we have of the particular specification
	char* m_Brand;
	char* m_Model;
	float m_Price;
	char m_SKU[21];			//Stock Keeping Unit, unique ID, max 20 characters + '\0'

/*helper functions*/
protected:
	char* SetCString(const char* source = nullptr);

/*public methods*/
public:
	/*constructors and destructor*/
	Mouse();
	Mouse(bool wireless, bool backlit, int buttonsNum, int count, char* sku, char* brand, char* model, float price);
	Mouse(const Mouse& otherMouse);
	~Mouse();

	/*copy assignment operator*/
	Mouse& operator=(const Mouse& otherMouse);
	
	/*friend functions for console output and input*/
	friend std::ostream& operator<<(std::ostream& outStream, const Mouse& someMouse);
	friend std::istream& operator>>(std::istream& inStream, Mouse& someMouse);

	/*setters*/
	void setButtonsNum(const int buttonsNum);
	void setCount(const int count);
	void setSKU(const char* SKU);
	void setBrand(const char* brand);
	void setModel(const char* model);
	void setPrice(const float price);

	/*getters*/
	int getCount() const;
	const char* getSKU() const;
	const char* getBrand() const;
	const char* getModel() const;
	const float getPrice() const;

	/*method to change an exsiting unit*/
	void ModifyMouse();

};


#endif //  the clause is for !MOUSE_CLASS





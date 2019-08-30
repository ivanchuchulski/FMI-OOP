#pragma once

#ifndef MOUSE_CLASS_H
#define MOUSE_CLASS_H

#include <iostream>

// the class defines a computer mouse characteristics
class ComputerMouse 
{
public:
	ComputerMouse();
	ComputerMouse(bool wireless, bool backlit, int buttonsNum, int unitsInStock, const char* brand, const char* model, const char* sku, float price);
	ComputerMouse(const ComputerMouse& otherMouse);
	~ComputerMouse();

	/*copy assignment operator*/
	ComputerMouse& operator=(const ComputerMouse& otherMouse);

	void SetWireless(const bool wireless);
	void SetBacklit(const bool backlit);
	void SetNumberOfButtons(const int buttonsNum);
	void ChangeUnitsInStock(const int count);
	void SetBrand(const char* brand);
	void SetModel(const char* model);
	void SetPrice(const float price);
	void SetSKU(const char* SKU);

	bool GetWireless() const;
	bool GetBacklit() const;
	int GetNumberOfButtons() const;
	int GetUnitsInStockCount() const;
	const char* GetBrand() const;
	const char* GetModel() const;
	const float GetPrice() const;
	const char* GetSKU() const;

	static const int GetSKULen();

	/*method to change an exsiting unit*/
	void ModifyMouse();

	/*friend functions for console output and input*/
	friend std::ostream& operator<<(std::ostream& outStream, const ComputerMouse& mouse);
	friend std::istream& operator>>(std::istream& inStream, ComputerMouse& mouse);

private:
	void Clear();
	void CopyFromOther(const ComputerMouse& other);
	void NullifySKU();

private:
	bool m_wireless;
	bool m_backlit;

	int m_numberOfButtons;
	int m_unitsInStock;

	char* m_brand;
	char* m_model;

	float m_price;

	static const int M_LEN_SKU = 10;
	char m_SKU[M_LEN_SKU + 1];			//Stock Keeping Unit, unique ID, max 10 characters + '\0'

private:
	const bool M_WIRELESS_DEFAULT = 0;
	const bool M_BACKLIT_DEFAULT = 0;

	const int M_NUMBER_OF_BUTTONS_DEFAULT = 3;
	const int M_UNITS_IN_STOCK_DEFAULT = 0;

	const char* M_BRAND_DEFAULT = "no_brand";
	const char* M_MODEL_DEFAULT = "no_model";

	const float M_PRICE_DEFAULT = 0.0f;
	const char* M_SKU_DEFUALT = "abcdefghij";
};

#endif //  the clause is for !MOUSE_CLASS





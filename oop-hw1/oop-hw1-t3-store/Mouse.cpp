#include "Mouse.h"

#include <cstring>


ComputerMouse::ComputerMouse()
	:	m_wireless(M_WIRELESS_DEFAULT),
		m_backlit(M_BACKLIT_DEFAULT),
		m_numberOfButtons(M_NUMBER_OF_BUTTONS_DEFAULT),
		m_unitsInStock(M_UNITS_IN_STOCK_DEFAULT),
		m_brand(nullptr),
		m_model(nullptr),
		m_price(M_PRICE_DEFAULT),
		m_SKU()
{
	NullifySKU();
}

ComputerMouse::ComputerMouse(bool wireless, bool backlit, int buttonsNum, int unitsInStock, const char* brand, const char* model, const char* sku, float price)
	:	m_wireless(wireless),
		m_backlit(backlit),
		m_numberOfButtons(),
		m_unitsInStock(),
		m_brand(nullptr),
		m_model(nullptr),
		m_price(),
		m_SKU()
{	
	NullifySKU();

	SetNumberOfButtons(buttonsNum);
	ChangeUnitsInStock(unitsInStock);

	SetBrand(brand);
	SetModel(model);
	
	SetPrice(price);
	SetSKU(sku);
}

ComputerMouse::ComputerMouse(const ComputerMouse& otherMouse)
	:	m_wireless(otherMouse.GetWireless()),
		m_backlit(otherMouse.GetBacklit()),
		m_numberOfButtons(otherMouse.GetNumberOfButtons()),
		m_unitsInStock(otherMouse.GetUnitsInStockCount()),
		m_brand(nullptr),
		m_model(nullptr),
		m_price(otherMouse.GetPrice()),
		m_SKU()
{
	NullifySKU();
	SetBrand(otherMouse.GetBrand());
	SetModel(otherMouse.GetModel());

	// CopyFromOther(otherMouse);
}

ComputerMouse::~ComputerMouse() 
{
	if (m_brand != nullptr) 
	{
		delete[] m_brand;
	}
	if (m_model != nullptr) {
		delete[] m_model;
	}
}

ComputerMouse& ComputerMouse::operator=(const ComputerMouse& otherMouse) 
{
	if (this != &otherMouse) 
	{
		Clear();
		CopyFromOther(otherMouse);
	}
	return *this;			// TODO: insert return statement here
}

void ComputerMouse::Clear()
{
	SetWireless(M_WIRELESS_DEFAULT);
	SetBacklit(M_BACKLIT_DEFAULT);

	SetNumberOfButtons(M_NUMBER_OF_BUTTONS_DEFAULT);
	ChangeUnitsInStock(M_UNITS_IN_STOCK_DEFAULT);

	delete[] m_brand;
	m_brand = nullptr;

	delete[] m_model;
	m_model = nullptr;

	SetPrice(M_PRICE_DEFAULT);

	NullifySKU();
}

void ComputerMouse::CopyFromOther(const ComputerMouse& other)
{
	SetWireless(other.GetWireless());
	SetBacklit(other.GetBacklit());

	SetNumberOfButtons(other.GetNumberOfButtons());
	ChangeUnitsInStock(other.GetUnitsInStockCount());

	SetBrand(other.GetBrand());
	SetModel(other.GetModel());

	SetPrice(other.GetPrice());

	SetSKU(other.GetSKU());
}

void ComputerMouse::NullifySKU()
{
	std::memset(m_SKU, '\0', M_LEN_SKU);
}


void ComputerMouse::SetWireless(const bool wireless)
{
	m_wireless = wireless;
}

void ComputerMouse::SetBacklit(const bool backlit)
{
	m_backlit = backlit;
}

void ComputerMouse::SetNumberOfButtons(const int buttonsNum) 
{
	m_numberOfButtons = (buttonsNum > 0) ? buttonsNum : M_NUMBER_OF_BUTTONS_DEFAULT;
}

void ComputerMouse::ChangeUnitsInStock(const int count) 
{
	m_unitsInStock = (count > 0) ? count : M_UNITS_IN_STOCK_DEFAULT;
}

void ComputerMouse::SetBrand(const char* brand)
{
	if (m_brand != nullptr)
	{
		delete[] m_brand;
		m_brand = nullptr;
	}

	if (brand == nullptr)
	{
		brand = M_BRAND_DEFAULT;
	}

	int brandLen = std::strlen(brand);
	
	m_brand = new char[brandLen + 1];
	std::memcpy(m_brand, brand, brandLen + 1);
}

void ComputerMouse::SetModel(const char* model) 
{
	if (m_model != nullptr)
	{
		delete[] m_model;
		m_model = nullptr;
	}

	if (model == nullptr)
	{
		model = M_MODEL_DEFAULT;
	}

	int modelLen = std::strlen(model);

	m_model = new char[modelLen + 1];
	std::memcpy(m_model, model, modelLen + 1);
}

void ComputerMouse::SetSKU(const char* SKU) 
{
	NullifySKU();

    int skuLen = std::strlen(SKU);

	if (SKU == nullptr || skuLen == 0 || skuLen > M_LEN_SKU)
	{
		std::memcpy(m_SKU, M_SKU_DEFUALT, M_LEN_SKU);
		return;
	}

	std::memcpy(m_SKU, SKU, skuLen);
}

void ComputerMouse::SetPrice(const float price) 
{
	m_price = (price > 0) ? price : M_PRICE_DEFAULT;
}

// getters
bool ComputerMouse::GetWireless() const
{
	return m_wireless;
}

bool ComputerMouse::GetBacklit() const
{
	return m_backlit;
}

int ComputerMouse::GetNumberOfButtons() const
{
	return m_numberOfButtons;
}

int ComputerMouse::GetUnitsInStockCount() const 
{
	return m_unitsInStock;
}

const char* ComputerMouse::GetBrand() const 
{
	return m_brand;
}

const char* ComputerMouse::GetModel() const 
{
	return m_model;
}

const float ComputerMouse::GetPrice() const 
{
	return m_price;
}

const char* ComputerMouse::GetSKU() const
{
	return m_SKU;
}

const int ComputerMouse::GetSKULen()
{
	return M_LEN_SKU;
}

void ComputerMouse::ModifyMouse() 
{
	std::cout << "Modifying...\n";
	std::cin >> *this;
}


std::ostream& operator<<(std::ostream& outStream, const ComputerMouse& mouse)
{
	outStream << "Mice information : \n";

	outStream << '\t' << "brand name : " << (mouse.GetBrand() != nullptr ? mouse.GetBrand() : "unidentified") << '\n';
	outStream << '\t' << "model name : " << (mouse.GetModel() != nullptr ? mouse.GetModel() : "unidentified") << '\n';

	outStream << '\t' << (mouse.m_wireless ? "is" : "isn't") << " wireless\n";
	outStream << '\t' << (mouse.m_backlit ? "is" : "isn't") << " backlit\n";

	outStream << '\t' << "it has " << mouse.GetNumberOfButtons() << " buttons\n";
	outStream << '\t' << "they are " << mouse.GetUnitsInStockCount() << " units available\n";
	outStream << '\t' << "each priced at " << mouse.GetPrice() << '\n';

	outStream << '\t' << "product SKU " << mouse.GetSKU() << '\n';

	outStream << std::endl;

	return outStream;			// TODO: insert return statement here
}

std::istream& operator>>(std::istream& inStream, ComputerMouse& mouse) 
{
	int wireless = 0;
	int backlit = 0;
	int numOfButtons = 0;
	int unitsInStock = 0;
	float price = 0;

	const int MAX_LEN = 50;
	char* brand = new char[MAX_LEN + 1];
	char* model = new char[MAX_LEN + 1];
	char* SKU = new char[MAX_LEN + 1];


	std::cout << "Please input the mouse parameters :\n";

	std::cout << '\t' << "Wireless : ";
	inStream >> wireless;

	std::cout << '\t' << "Backlit : ";
	inStream >> backlit;

	std::cout << '\t' << "Number of buttons : ";
	inStream >> numOfButtons;

	std::cout << '\t' << "Units in stock : ";
	inStream >> unitsInStock;

	std::cout << '\t' << "Price : ";
	inStream >> price;

	inStream.ignore();

	std::cout << '\t' << "SKU (max " << mouse.GetSKULen() << " chars) : ";
	inStream.getline(SKU, 50);

	std::cout << '\t' << "Brand : ";
	inStream.getline(brand, 50);

	std::cout << '\t' << "Model :";
	inStream.getline(model, 50);

	std::cout << std::endl;

	mouse.SetWireless(wireless);
	mouse.SetBacklit(backlit);
	mouse.SetNumberOfButtons(numOfButtons);
	mouse.ChangeUnitsInStock(unitsInStock);
	mouse.SetBrand(brand);
	mouse.SetModel(model);
	mouse.SetPrice(price);
	mouse.SetSKU(SKU);

	//free dynamic memory
	delete[] SKU;
	delete[] model;
	delete[] brand;

	return inStream;			// TODO: insert return statement here
}
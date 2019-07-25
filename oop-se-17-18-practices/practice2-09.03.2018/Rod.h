#pragma once

//enum for RodMaterial
enum Material {
	Unspecified = 0,
	Carbon = 1,
	Wooden = 2
};

//class definition
class Rod {

private:
	int m_Length;
	bool m_IsAutomatic;
	Material m_RodMaterial;
	char* m_Name;	//

public:

	//constructors and destructor
	Rod();
	Rod(int lenght, bool is_Auto, Material rodMaterial, char* inputName);	//overloaded constr
	Rod(const Rod& otherObj);	//copy constructor
	~Rod();	//destuctor

	//getters
	int getLeght() const;
	bool getIsAutomatic() const;
	Material getMaterial() const;
	char* getName() const;

	//setters
	void setLength(int lenght);
	void setIsAutomatic(bool isAuto);
	void setMaterial(Material RodMaterial);
	void setName(char* inputName);

	//copy assignment opearator
	Rod& operator=(const Rod& otherObj);
};


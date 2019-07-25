#pragma once

#include <iostream>
#include <string>


class Profile
{

private:
	const int YEAR_DEFAULT = 15;
	const std::string DEFAULT_STRING = "N/a";
private:

	int m_BirthYear;
	std::string m_Name;
	std::string m_Password;

public:
	/*constructors*/
	Profile();
	Profile(const Profile& someProfile);
	Profile(const std::string& name, const std::string& password, int year);
	//Profile(const std::string* name, const std::string* password, int year);
	Profile(const char* name, const char* password, int year);

	/*destructor*/
	virtual ~Profile();

	Profile& operator=(const Profile& someProfile);

	friend std::ostream& operator<<(std::ostream& outStream, const Profile& objProfile);
	friend std::istream& operator>>(std::istream& inStream, Profile& objProfile);

	void SetBirthYear(int const year);


	void DisplayInfo() const;

};


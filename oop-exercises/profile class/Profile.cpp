#include "Profile.h"


/*default ctor*/
Profile::Profile()
	:	m_BirthYear(),
		m_Name(DEFAULT_STRING),
		m_Password(DEFAULT_STRING)
{
}

/*copy ctor*/
Profile::Profile(const Profile& someProfile)
	:	m_BirthYear(someProfile.m_BirthYear),
		m_Name(someProfile.m_Name),
		m_Password(someProfile.m_Password)

{
}

/*ctor with parameters*/
Profile::Profile(const std::string& name, const std::string& password, int year)
	:	m_BirthYear((year > 0) ? year : YEAR_DEFAULT),
		m_Name(name),
		m_Password(password)
{}

//Profile::Profile(const std::string* name, const std::string* password, int year)
//	:	m_BirthYear((year > 0) ? year : YEAR_DEFAULT),
//		m_Name((name != nullptr) ? *(name) : DEFAULT_STRING),
//		m_Password((password != nullptr) ? *(password) : DEFAULT_STRING)
//{}

Profile::Profile(const char* name, const char* password, int year)
	:	m_BirthYear((year > 0) ? year : YEAR_DEFAULT),
		m_Name((name != nullptr) ? name : DEFAULT_STRING),
		m_Password((password != nullptr) ? password : DEFAULT_STRING)
{}


/*destuctor*/
Profile::~Profile()
{}

Profile & Profile::operator=(const Profile& someProfile)
{
	if (this != &(someProfile)) {
		m_BirthYear = someProfile.m_BirthYear;
		m_Name = someProfile.m_Name;
		m_Password = someProfile.m_Password;

	}


	return *(this);		// TODO: insert return statement here
}


std::ostream & operator<<(std::ostream & outStream, const Profile & objProfile)
{
	outStream << "\n\tname :  " << objProfile.m_Name  
				<< "\n\tpassword : " << objProfile.m_Password 
				<< "\n\tbirth year : " << objProfile.m_BirthYear << '\n';

	return outStream;		// TODO: insert return statement here
}

std::istream& operator>>(std::istream& inStream, Profile& objProfile)
{
	int year_buffer = 0;

	//to clean possible previous flags
//	inStream.clear();


	std::cout << "Please enter a name : ";
	std::getline(inStream, objProfile.m_Name, '\n');
	//inStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	inStream.ignore(10000, '\n');

	std::cout << "Please enter a password : ";
	std::getline(inStream, objProfile.m_Password, '\n');
	//inStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	inStream.ignore(10000, '\n');


	std::cout << "Please enter your birth age : ";
	inStream >> year_buffer;

	objProfile.SetBirthYear(year_buffer);

	return inStream;		// TODO: insert return statement here
}


void Profile::SetBirthYear(int const year)
{
	if (year > 0) {
		m_BirthYear = year;
	}

}

void Profile::DisplayInfo() const
{
	std::cout << *(this);
}
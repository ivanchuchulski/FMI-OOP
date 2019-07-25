#pragma once

#include "Profile.h"

template<typename Type>
class RandomProfile 
		: Profile
{

private:
	Type m_random_data;

public:
	/*constructors*/
	RandomProfile();
	RandomProfile(const RandomProfile<Type>& otherRandProfile);
	RandomProfile(Type& random_data);

	/*destructor*/
	~RandomProfile();

	/*copy assignment*/
	RandomProfile& operator=(const RandomProfile& otherRandProfile);

};


/*		methods definitions		*/
#pragma region

//default ctor
template<typename Type>
inline RandomProfile<Type>::RandomProfile()
	:	Profile::Profile(),
		m_random_data()
{}


//copy ctor
template<typename Type>
inline RandomProfile<Type>::RandomProfile(const RandomProfile<Type>& otherRandProfile)
	:	Profile::Profile(otherRandProfile),
		m_random_data(otherRandProfile.m_random_data)
{}


//copy =
template<typename Type>
inline RandomProfile<Type>& RandomProfile<Type>::operator=(const RandomProfile<Type>& otherRandProfile)
{
	if (this != &(otherRandProfile))
	{
		Profile::operator=(otherRandProfile);

		m_random_data = otherRandProfile.m_random_data;
	}
	return *(this);			// TODO: insert return statement here
}

//ctor with parameters
template<typename Type>
inline RandomProfile<Type>::RandomProfile(Type& random_data)
	:	Profile::Profile(),
		m_random_data(random_data)
{}


//destructor
template<typename Type>
inline RandomProfile<Type>::~RandomProfile()
{}


#pragma endregion
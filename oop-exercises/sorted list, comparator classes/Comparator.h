#pragma once


template<typename Type>
class Comparator {

public:
	//pure virtual method, need to implement in the derived classes
	virtual int Compare(const Type& left, const Type& right) const = 0;


};
#include <iostream>
#include "MyStringFuncs.h"
#include "Truck.h"

class Entity {

private:
	unsigned int m_Data;
	char* m_Name;

private:
	char* setCString(const char* source = nullptr) {
		char* bufferPtr = nullptr;

		if (source != nullptr) {
			int sourceLen = StrLen(source);

			bufferPtr = new char[sourceLen + 1];
			StrCopy(bufferPtr, sourceLen, source);

			return bufferPtr;
		}
		else {
			bufferPtr = new char[8]{ "Unknown" };
			return bufferPtr;
		}

	}

public:

	Entity()
		: m_Data(0),
		m_Name(setCString())
	{}

	Entity(const Entity& someEntity)
		: m_Data(someEntity.m_Data),
		m_Name(setCString(someEntity.m_Name))
	{}

	Entity(const Entity* someEntity)
		: m_Data(someEntity->m_Data),
		m_Name(setCString(someEntity->m_Name))
	{}

	Entity(int data, const char* name)
		: m_Data(0),
		m_Name(setCString(name))
	{
		if (data >= 0) { m_Data = data; }
	}

	~Entity() {
		//free memory if needed
		if (m_Name != nullptr) {
			delete[] m_Name;
		}
	}

	Entity& operator=(const Entity& someEntity) {
		if (this != &someEntity) {
			//free data if needed
			if (m_Name != nullptr) {
				delete[] m_Name;
				m_Name = nullptr;
			}

			m_Data = someEntity.m_Data;
			m_Name = setCString(someEntity.m_Name);
		}
		return *this;
	}

	friend std::ostream& Entity::operator<<(std::ostream& outStream, const Entity& someEntity) {
		outStream << "Printing a Entity :\n\t  ~data :"
			<< someEntity.m_Data
			<< "\n\t ~name : " << someEntity.m_Name << std::endl;
		return outStream;				//returning the output stream
	}

	/*operators*/
	bool operator==(const Entity& otherEntity) { return (this->m_Data == otherEntity.m_Data); }
	bool operator!=(const Entity& otherEntity) { return (this->m_Data != otherEntity.m_Data); }

	bool operator<=(const Entity& otherEntity) { return (this->m_Data <= otherEntity.m_Data); }
	bool operator>=(const Entity& otherEntity) { return (this->m_Data >= otherEntity.m_Data); }

	bool operator<(const Entity& otherEntity) { return (this->m_Data < otherEntity.m_Data); }
	bool operator>(const Entity& otherEntity) { return (this->m_Data > otherEntity.m_Data); }

	/*prefix operator ++*/
	//void operator++() {
	//	++(this->m_Data);
	//}

	/*postfix operator ++*/
	//void operator++(int x) {
	//	(this->m_Data)++;
	//}


	/*covers only the prefix*/
	friend void operator++(Entity& someEntity){
		++someEntity.m_Data;
	}

	/*covers only the postfix*/
	friend void operator++(Entity& someEntity, int x) {
		someEntity.m_Data++;
	}

	Entity operator*(const Entity& otherEntity) {
		return Entity(this->m_Data * otherEntity.m_Data, otherEntity.m_Name);	//calling the ctor with one float param and char*
	}

};

class MyEntities {

private:
	Entity m_FirstEnt;
	Entity m_SecondEnt;

public:

	/*default ctor*/
	MyEntities()
		//calling default ctors
	:	m_FirstEnt(Entity()),		
		m_SecondEnt(Entity())
	{}
	
	/*copy ctor*/
	MyEntities(const MyEntities& someClass)
		//calling copy ctors
	:	m_FirstEnt(Entity(someClass.m_FirstEnt)),
		m_SecondEnt(Entity(someClass.m_SecondEnt))
	{}


	MyEntities(const Entity& firstEnt, const Entity& secondEnt)
		//calling copy ctors
	:	m_FirstEnt(Entity(firstEnt)),
		m_SecondEnt(Entity(secondEnt))
	{}

	MyEntities& operator=(const MyEntities& someClass)
	{
		m_FirstEnt = someClass.m_FirstEnt;
		m_SecondEnt = someClass.m_SecondEnt;
	}

	~MyEntities() {

	}


};


int main() {

	Entity a;
	Entity b = &a;		//passing the address of a, so we search for ctor, that takes a Entity*
	Entity c = a;
	Entity d = Entity(10, "SomeRandomLongName");

	c = d;

	c++;
	++d;

	MyEntities obj1 = MyEntities(c, d);
	MyEntities obj2 = MyEntities(obj1);
	

	Truck myTruck1 = Truck();
	Truck myTruck2 = Truck(1983, "Vag2", "Diesel", 123, "Man");

	Truck myTruck3 = Truck(myTruck2);

	myTruck1 = myTruck2;

	void* myPtr = nullptr;

	myPtr = (Truck*)&myTruck1;



	std::cin.get();
	return 0;
}
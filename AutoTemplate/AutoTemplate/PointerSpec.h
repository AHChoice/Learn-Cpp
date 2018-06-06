//////////////////////////////////////////////////////////////////////////
//  @file     PointerSpec.h
//  @author   AutoNet
//  @date     2018-05-23
//  @remark   Partial template specialization for pointers
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef POINTERSPEC_H
#define POINTERSPEC_H

#include <iostream>
using namespace std;
#include <cstring>

// Our Storage class for non-pointers
template <class T>
class StoragePtr
{
private:
	T m_value;
public:
	StoragePtr(T value)
	{
		m_value = value;
	}

	~StoragePtr()
	{
	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

// Partial-specialization of Storage class for pointers
template <class T>
class StoragePtr<T*>
{
private:
	T* m_value;
public:
	StoragePtr(T* value)
	{
		m_value = new T(*value);
	}

	~StoragePtr()
	{
		delete m_value;
	}

	void print()
	{
		std::cout << *m_value << '\n';
	}
};

// Full specialization of constructor for type char*
template <>
StoragePtr<char*>::StoragePtr(char* value)
{
	// Figure out how long the string in value is
	int length = 0;
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator

	// Allocate memory to hold the value string
	m_value = new char[length];

	// Copy the actual value string into the m_value memory we just allocated
	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}

// Full specialization of destructor for type char*
template<>
StoragePtr<char*>::~StoragePtr()
{
	delete[] m_value;
}

// Full specialization of print function for type char*
// Without this, printing a Storage<char*> would call Storage<T*>::print(), which only prints the first element
template<>
void StoragePtr<char*>::print()
{
	std::cout << m_value << endl;
}

int PointerSpec()
{
	// Declare a non-pointer Storage to show it works
	StoragePtr<int> myint(5);
	myint.print();

	// Declare a pointer Storage to show it works
	int x = 7;
	StoragePtr<int*> myintptr(&x);

	// If myintptr did a pointer assignment on x,
	// then changing x will change myintptr too
	x = 9;
	myintptr.print();

	// Dynamically allocate a temporary string
	//char *name = new char[40]{ "Alex" }; // requires C++14

	// If your compiler isn't C++14 compatible, comment out the above line and uncomment these
	char *name = new char[40];
	strcpy_s(name, 40, "Alex");

	// Store the name
	StoragePtr< char*> myname(name);

	// Delete the temporary string
	delete[] name;

	// Print out our name
	myname.print();

	return 0;
}

#endif // POINTERSPEC_H
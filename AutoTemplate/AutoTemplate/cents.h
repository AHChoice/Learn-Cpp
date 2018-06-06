//////////////////////////////////////////////////////////////////////////
//  @file     cents.h
//  @author   AutoNet
//  @date     2018-05-23
//  @remark   overloaded operator for the Cents class
//  @note
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <ostream>

using namespace std;

template <typename T> // this is the template parameter declaration
const T& max(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

template <class T>
T average(T *array, int length)
{
	T sum = 0;
	for (int count=0; count < length; ++count)
		sum += array[count];

	sum /= length;
	return sum;
}


class Cents
{
private:
	int m_cents;
public:
	Cents(int cents) : m_cents(cents) {}

	friend bool operator>(const Cents &c1, const Cents &c2)
	{
		return (c1.m_cents > c2.m_cents);
	}

	friend ostream& operator<< (ostream &out, const Cents &cents)
	{
		out << cents.m_cents << "cents";
		return out;
	}

	Cents& operator+=(Cents cents)
	{
		m_cents += cents.m_cents;
		return *this;
	}

	Cents& operator/=(int value)
	{
		m_cents /= value;
		return *this;
	}
};

int cents()
{
	Cents nickle(5);
	Cents dime(10);

	//Cents bigger = max(nickle, dime);
	Cents array3[] = { Cents(5), Cents(10), Cents(15), Cents(14) };
	std::cout << average(array3, 4) << '\n';

	return 0;
}
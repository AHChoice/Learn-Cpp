//////////////////////////////////////////////////////////////////////////
//  @file     Basic.cpp
//  @author   AutoNet
//  @date     2018-05-25
//  @remark   Basic exception handling
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>

namespace basic_exception
{
	void basic()
	{
		try
		{
			// Statements that may throw exceptions you want to handle go here
			throw -1.5; // here's a trivial example
		}
		catch (int x)
		{
			// Any exceptions of type int thrown within the above try block get sent here
			std::cerr << "We caught an int exception with value: " << x << '\n';
		}
		catch (double) // no variable name since we don't use the exception itself in the catch block below
		{
			// Any exceptions of type double thrown within the above try block get sent here
			std::cerr << "We caught an exception of type double" << '\n';
		}
		catch (const std::string &str) // catch classes by const reference
		{
			// Any exceptions of type std::string thrown within the above try block get sent here
			std::cerr << "We caught an exception of type std::string" << '\n';
		}

		std::cout << "Continuing on our merry way\n";
	}

	int sqrtvalue()
	{
		std::cout << "Enter a number: ";
		double x;
		std::cin >> x;

		try // Look for exceptions that occur within try block and route to 
			// attached actch blocks
		{
			// If the user entered a negative number, this is an error condition
			if (x < 0.0)
				// throw exception of type const char*
				throw "Can not take sqrt of negative number";

			// Otherwise, print the answer
			std::cout << "The sqrt of " << x << " is " << sqrt(x) << '\n';
		}
		catch (...)
		{
			
			//std::cerr << "Error: " << exception << '\n';
		}

		return 0;
	}
}

#endif // BASIC_H
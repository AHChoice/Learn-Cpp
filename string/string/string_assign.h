//////////////////////////////////////////////////////////////////////////
//  @file     string_assign
//  @author   VincentLee
//  @date     2018-05-29
//  @mail     vincentleecn@163.com
//
//  @version  2018-05-29
//  -added std::string assignment and swapping
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef STRING_ASSIGN_H
#define STRING_ASSIGN_H

#include <iostream>
#include <string>
#include "Line.h"

namespace cm_assign
{
	int assign()
	{
		LINE(PLOG_STR(assign));

		// string& string::operator= (const string& str)
		// string& string::assign (const string& str)
		// string& string::operator= (const char* str)
		// string& string::assign (const char* str)
		// string& string::operator= (char c)

		std::string source;
		
		// assign a string value
		source = std::string("one");
		std::cout << source << std::endl;

		const std::string str_two("two");
		source.assign(str_two);
		std::cout << source << std::endl;

		// assign a C-style string
		source = "three";
		std::cout << source << std::endl;

		source.assign("four");
		std::cout << source << std::endl;

		// chain assignment
		std::string str_other;
		source = str_other = "six";
		std::cout << source << " " << str_other << std::endl;

		// swapping 
		// void string::swap (string &str)
		// void swap (string &str1, string &str2)

		std::string str1("red");
		std::string str2("blue");

		std::cout << str1 << " " << str2 << std::endl;
		swap(str1, str2);
		std::cout << str1 << " " << str2 << std::endl;
		str1.swap(str2);
		std::cout << str1 << " " << str2 << std::endl;

		return 0;
	}
}

#endif // STRING_ASSIGN_H
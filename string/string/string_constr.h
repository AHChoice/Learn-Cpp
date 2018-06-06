//////////////////////////////////////////////////////////////////////////
//  @file     string.h
//  @author   VincentLee
//  @date     2018-05-29
//  @mail     vincentleecn@163.com
//
//  @version  208-05-29
//  -added 
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <sstream>

//	These are the two classes that you will actually use. std::string is used for 
//	standard ascii (utf-8) strings. std::wstring is used for wide-character/unicode
//	(utf-16) strings. There is no built-in class for utf-32 strings (though you 
//	should be able to extend your own from basic_string<> if you need one).

//  While the standard library string classes provide a lot of functionality, 
//  there are a few notable omissions:
//
//  Regular expression support
//	Constructors for creating strings from numbers
//	Capitalization / upper case / lower case functions
//	Case-insensitive comparisons
//	Tokenization / splitting string into array
//	Easy functions for getting the left or right hand portion of string
//	Whitespace trimming
//	Formatting a string sprintf style
//	Conversion from utf-8 to utf-16 or vice-versa

namespace cm_string
{
	template <class T>
	inline std::string ToString(T tx)
	{
		std::ostringstream ostream;
		ostream << tx;
		return ostream.str();
	}

	template <class T>
	inline bool FromString(const std::string &str, T &tx)
	{
		std::istringstream istream(str);
		// extract value int tx, return success or not

		return (istream >> tx) ? true : false;
	}

	int constructor()
	{
		std::string sSource1("my string"); // string::string();
		std::string sSource2(sSource1); // string::string(&string);

		// string::string(const string& strString, size_type unIndex)
		// string::string(const string& strString, size_type unIndex, size_type unLength)
		// * This constructor creates a new string that contains at most 
		// unLength characters from strString, starting with index unIndex. If
		// a NULL is encountered, the string copy will end, even if unLength has
		// not been reached.
		// * If no unLength is supplied, all characters starting from unIndex will be used.
		// * If unIndex is larger than the size of the string, the out_of_range 
		// exception will be thrown.
		std::string sOutput(sSource1, 3);
		std::cout << sOutput << std::endl;

		std::string sOutput2(sSource1, 3, 4);
		std::cout << sOutput2 << std::endl;

		// string::string(const char *szCString)
		// * This constructor creates a new string from the C-style string 
		// szCString, up to but not including the NULL terminator.
		// * If the resulting size exceeds the maximum string length, the
		// length_error exception will be thrown.
		// * Warning: szCString must not be NULL.

		const char *szSource("my string");
		std::string sOutput3(szSource);
		std::cout << sOutput3 << std::endl;

		std::string sOutput4(szSource, 4);
		std::cout << sOutput4 << std::endl;


		// string::string(size_type nNum, char chChar)
		// * This constructor creates a new string initialized by nNum
		// occurances of the character chChar.
		// * If the resulting size exceeds the maximum string length,
		// the length_error exception will be thrown.
		
		std::string sOutput5(4, 'Q');
		std::cout << sOutput5 << std::endl;

		// One notable omission in the std::string class is the lack of ability
		// to create strings from numbers. 

		std::string sFour(ToString(4));
		std::string sSixPointSeven(ToString(6.7));
		std::string sA(ToString('A'));
		std::cout << sFour << std::endl;
		std::cout << sSixPointSeven << std::endl;
		std::cout << sA << std::endl;

		double dx;
		if (FromString("3.4", dx))
			std::cout << dx << std::endl;
		if (FromString("ABC", dx))
			std::cout << dx << std::endl;

		return 0;
	}
}

#endif // STRING_H
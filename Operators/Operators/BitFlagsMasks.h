//////////////////////////////////////////////////////////////////////////
//  @file     BitFlagsMasks.h
//  @author   AutoNet
//  @date     2018-05-24
//  @remark   Bit flags and bit masks
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef BITFLAG_H
#define BITFLAG_H

#include <iostream>
using namespace std;
#include <bitset>

namespace bitflag
{
	// C++ 14
	// Define 8 separate bit flags (these can represent whatever you want)
	//const unsigned char option0 = 0b0000'0001; // represents bit 0
	//const unsigned char option1 = 0b0000'0010; // represents bit 1
	//const unsigned char option2 = 0b0000'0100; // represents bit 2 
	//const unsigned char option3 = 0b0000'1000; // represents bit 3
	//const unsigned char option4 = 0b0001'0000; // represents bit 4
	//const unsigned char option5 = 0b0010'0000; // represents bit 5
	//const unsigned char option6 = 0b0100'0000; // represents bit 6

	// C++ 11
	// Define 8 separate bit flags (these can represent whatever you want)
	const unsigned char option0 = 0x1;  // hex for 0000 0001 
	const unsigned char option1 = 0x2;  // hex for 0000 0010
	const unsigned char option2 = 0x4;  // hex for 0000 0100
	const unsigned char option3 = 0x8;  // hex for 0000 1000
	const unsigned char option4 = 0x10; // hex for 0001 0000
	const unsigned char option5 = 0x20; // hex for 0010 0000
	const unsigned char option6 = 0x40; // hex for 0100 0000
	const unsigned char option7 = 0x80; // hex for 1000 0000

	// This can be a little hard to read. One way to make it easier is to 
	// use the left-shift operator to shift a bit into the proper location:

	// Define 8 separate bit flags (these can represent whatever you want)
	//const unsigned char option0 = 1 << 0; // 0000 0001 
	//const unsigned char option1 = 1 << 1; // 0000 0010
	//const unsigned char option2 = 1 << 2; // 0000 0100
	//const unsigned char option3 = 1 << 3; // 0000 1000
	//const unsigned char option4 = 1 << 4; // 0001 0000
	//const unsigned char option5 = 1 << 5; // 0010 0000
	//const unsigned char option6 = 1 << 6; // 0100 0000
	//const unsigned char option7 = 1 << 7; // 1000 0000



	int MainpulateBits()
	{
		// Since we have 8 options above, we'll use an 8-bit value to hold our 
		// options Each bit in myflags corresponds to one of the options defined above
		unsigned char myflags = 0; // all bits turned off to start
		myflags |= option4; // turn option4 on
		myflags &= ~option4; // turn option4 off
		myflags &= ~(option4 | option5); // turn options 4 and 5 off at the same time

		// To toggle a bit state, we use bitwise XOR:
		myflags ^= option4; // filp option4 from on to off, or vice versa
		myflags ^= (option4 | option5); // flip options 4 and 5 at the same time

		// To query a bit state, we use bitwise AND:
		if (myflags & option4)
			std::cout << "myflags has option 4 set";
		if (!(myflags & option5))
			std::cout << "myfalgs does not have option 5 set";

		return 0;
	}

	// the C++ standard library comes with functionality called std::bitset
	// that helps us manage bit flags.
	// We recommend using std::bitset instead of doing all the bit operations 
	// manually, as bitset is more convenient and less error prone.

	int bitset()
	{
		// Note that with std::bitset, our options correspond to bit indices,
		// not bit patterns
		const int option0 = 0;
		const int option1 = 1;
		const int option2 = 2;
		const int option3 = 3;
		const int option4 = 4;
		const int option5 = 5;
		const int option6 = 6;
		const int option7 = 7;

		std::bitset<8> bits(0x2); // we need 8 bits, start with bit pattern 0000 0010
		bits.set(option4);	 // set bit 4 to 1 (now we have 0001 0010)
		bits.flip(option5); // flip bit 5 (now we have 0011 0010)
		bits.reset(option5); // set bit 5 back to 0 (now we have 0001 0010)

		std::cout << "Bit 4 has value: " << bits.test(option4) << '\n';
		std::cout << "Bit 5 has value: " << bits.test(option5) << '\n';
		std::cout << "All the bits: " << bits << '\n';

		return 0;
	}

	int RGB()
	{
		const unsigned int redBits = 0xFF000000;
		const unsigned int greenBits = 0x00FF0000;
		const unsigned int blueBits = 0x0000FF00;
		const unsigned int alphaBits = 0x000000FF;

		std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
		unsigned int pixel;
		std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

		// use bitwise AND to isolate red pixels, then right shift the value into the range 0-255
		unsigned char red = (pixel & redBits) >> 24;
		unsigned char green = (pixel & greenBits) >> 16;
		unsigned char blue = (pixel & blueBits) >> 8;
		unsigned char alpha = pixel & alphaBits;

		std::cout << "Your color contains:\n";
		std::cout << static_cast<int>(red) << " of 255 red\n";
		std::cout << static_cast<int>(green) << " of 255 green\n";
		std::cout << static_cast<int>(blue) << " of 255 blue\n";
		std::cout << static_cast<int>(alpha) << " of 255 alpha\n";

		return 0;
	}
}
	


#endif // BITFLAG_H
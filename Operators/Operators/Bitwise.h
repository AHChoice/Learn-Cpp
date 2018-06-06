//////////////////////////////////////////////////////////////////////////
//  @file     Bitwise.h
//  @author   AutoNet
//  @date     2018-05-23
//  @remark  
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef BITWISE_H
#define BITWISE_H
#include <iostream>
using namespace std;
namespace bitwise
{
	void BitWise()
	{
		unsigned long quiz = 0;
		quiz |= 1UL << 7;			//  0 to 1 

		quiz &= ~(1UL << 7);		// 1 to 0

		bool status = quiz & (1Ul <<7);

	}

}


#endif // BITWISE_H
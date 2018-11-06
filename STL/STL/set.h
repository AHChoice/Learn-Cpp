/*******************************************************************
*  Copyright(c) 2000-2018 Company Name
*  All rights reserved.
*
*  @file
*  @brief
*  @mail   vincentlee@usa.com
*  @date   2018-11-06
*  @author vincentlee
*  @note
*
******************************************************************/
#ifndef SET_H
#define SET_H
#include <iostream>
#include <set>
using namespace std;

class Kit
{
public:
    int a;
    int b;

};


struct kit_less
{	// functor for operator<
    bool operator()(const Kit& left, const Kit& right) const
    {	// apply operator< to operands
        if (left.a == right.a)
            return left.b < right.b;
        else
            return left.a < right.a;
    }
};

namespace myset
{
    void init() {
        set<Kit, kit_less> s;
        Kit t1, t2, t3;
        t1.a = 10;
        t1.b = 10;
        t2.a = 20;
        t2.b = 20;
        t3.a = 10;
        t3.b = 10;

        s.insert(t1);
        s.insert(t2);
        s.insert(t3);

        for (auto elem : s)
            cout << elem.a << elem.b << endl;
    }
    
}









#endif // SET_H
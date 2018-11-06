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
#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
using namespace std;
namespace myvec
{
    void init() {
        vector<int> vi;
        vi.push_back(10);
        for (auto elem : vi)
            cout << elem << endl;
    }
    
}



















#endif  // VECTOR_H
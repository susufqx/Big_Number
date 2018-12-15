//
//  BigNumber.h
//  newbg
//
//  Created by 睿 李 on 15/6/8.
//  Copyright (c) 2015年 睿 李. All rights reserved.
//

#ifndef __newbg__BigNumber__
#define __newbg__BigNumber__

#include <iostream>
#include <string.h>
using namespace std;

class BigNumber
{
    friend ostream & operator << (ostream& out, BigNumber& obj);
    friend istream & operator >> (istream& in, BigNumber& obj);
private:
    char * s;
    int n;
    bool sign;   //true for + et false for -
    int * result;
public:
    BigNumber & operator + (BigNumber& other);
    BigNumber & operator - (BigNumber& other);
    BigNumber & operator * (BigNumber& other);
    BigNumber & operator ^ (int x);
    BigNumber & pgcd (BigNumber& other);
    BigNumber & operator % (BigNumber& other);

    void setS(char * x);
    char * getS();
    void setBool(bool si);
    bool getBool();
    int  getN();

    ~BigNumber();
    BigNumber();
    BigNumber(BigNumber& other);
    BigNumber(char * x, bool si);

};
#endif /* defined(__newbg__BigNumber__) */

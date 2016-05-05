//
//  calculator.cpp
//  newbg
//
//  Created by 睿 李 on 15/6/8.
//  Copyright (c) 2015年 睿 李. All rights reserved.
//

#include "calculator.h"

//compare two numbers. if return 1 x >= y else x < y
int compare(string x, string y, int nx, int ny)
{
    int pa;
    if (nx > ny)
    {
        return 1;
    }
    else if(nx <ny)
    {
        return 0;
    }
    else
    {
        for(int i=0;i<nx;i++)
        {
            pa = (x[i] - 48)-(y[i] - 48);
            if (pa > 0)
            {
                return 1;
            }
            else if(pa <0)
            {
                return 0;
            }
        }
        return 1;
    }
}

//get the sum of two numbers
char *  add(string s1, string s2, int n1, int n2)
{
    char *  res;
    int * plus;
    int n, m;
    int flag = 0;
    int i;
    int com = compare(s1, s2, n1, n2);
    if (com == 1)
    {
        n = n2;
        m = n1;
        plus = new int [n1+1];
    }
    else
    {
        n = n1;
        m = n2;
        plus = new int [n2+1];
    }
    
    for (i=0;i<n;i++)
    {
        plus[i] = (s1[n1-1-i]-48) + (s2[n2-1-i]-48) + flag;
        if (plus[i] == 3)
        {
            plus[i] = 1;
            flag = 1;
        }
        else if(plus[i] == 2)
        {
            plus[i] = 0;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    
    if(com == 1)
    {
        for(;i<n1;i++)
        {
            plus[i] = (s1[n1-1-i]-48) + flag;
            if (plus[i] == 2)
            {
                plus[i] = 0;
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
    }
    else
    {
        for(;i<n2;i++)
        {
            plus[i] = (s2[n2-1-i]-48) + flag;
            if (plus[i] == 2)
            {
                plus[i] = 0;
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
    }
    if (flag == 1)
    {
        plus[i] = 1;
        m = m + 1;
    }
    res = new char[n];
    for (i=0;i<m;i++)
    {
        res[m-1-i] = plus[i] + 48;
    }
    return res;
}

//realize the minus of two numbers
char *  reduce(string s1,string s2, int n1, int n2) //ici, s1 est plus grand que s2 ,donc n1 >= n2
{
    char *  res;
    int *minus;
    int n; // pour deposer le nombre de bit de resultat
    int flag = 0;
    int i;
    n = n1;
    minus = new int [n1];
    for (i=0;i<n2;i++)
    {
        minus[i] = (s1[n1-1-i]-48) - (s2[n2-1-i]-48) - flag;
        if (minus[i] == -2)
        {
            minus[i] = 0;
            flag = 1;
        }
        else if (minus[i] == -1)
        {
            minus[i] = 1;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    for (;i<n1;i++)
    {
        minus[i] = (s1[n1-1-i]-48) - flag;
        if (minus[i] == -1)
        {
            minus[i] = 1;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    
    int temp = n;
    for (i=0;i<temp;i++)
    {
        if(minus[temp-1-i] == 1)
        {
            break;
        }
        else
        {
            n -= 1;
        }
    }
    
    res = new char[n];
    for (i=0;i<n;i++)
    {
        res[n-1-i] = minus[i] + 48;
    }
    
    if (n == 0)
    {
        n = 1;
        res[0] = 48;
    }
    
    return res;
}

//logical not
bool no(bool x)
{
    if (x == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//logical and
bool et(bool x, bool y)
{
    if (x == true && y == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//logical or
bool ou(bool x, bool y)
{
    if (x == true || y == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//logical xor
bool xou(bool x, bool y)
{
    if (x == y)
    {
        return false;
    }
    else
    {
        return true;
    }
}


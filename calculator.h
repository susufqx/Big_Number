//
//  calculator.h
//  newbg
//
//  Created by 睿 李 on 15/6/8.
//  Copyright (c) 2015年 睿 李. All rights reserved.
//

#ifndef newbg_calculator_h
#define newbg_calculator_h

#include <iostream>
#include <string.h>
using namespace std;

int compare(string x,  string y,  int nx, int ny);
char * add (string s1, string s2, int n1, int n2);
char * reduce (string s1, string s2, int n1, int n2);
char * move (string x,  int n);

bool no(bool x);
bool et(bool x, bool y);
bool ou(bool x, bool y);
bool xou(bool x, bool y);

#endif

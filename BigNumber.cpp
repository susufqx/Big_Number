//
//  BigNumber.cpp
//  newbg
//
//  Created by 睿 李 on 15/6/8.
//  Copyright (c) 2015年 睿 李. All rights reserved.
//

#include "BigNumber.h"
#include "calculator.h"

//set ou get
void BigNumber::setS(char * x) {
  int xn = strlen(x);
  for (int i=0;i<=xn;i++) {
    s[i] = x[i];
  }
}
char * BigNumber::getS() {
  return s;
}

void BigNumber::setBool(bool si) {
  sign = si;
}

bool BigNumber::getBool() {
  return sign;
}

int BigNumber::getN() {
  return int(strlen(s));
}

//destructeur et constructeur
BigNumber::~BigNumber() {
  if (s != 0) delete s;
}

BigNumber::BigNumber() {
  //...
  sign = true;
  s = new char[0];
  n = 0;
}

BigNumber::BigNumber(BigNumber& other) {
  sign = other.sign;
  s = other.s;
  n = other.n;
}

BigNumber::BigNumber(char * x,  bool si) {
  s = x;
  sign = si;
}

//redefinie les operators comme + - x
BigNumber&
BigNumber::
operator + (BigNumber& other) {
  BigNumber * res;
  int g;        //for comparing the two numbers
  char * s1, * s2;
  int n1, n2;    //s1 stores the bigger number  s2 stores the other one and n1 and n2 are the bit number of s1 s2

  this->n = this->getN();
  other.n = other.getN();
  res = new BigNumber();
  s1 = new char [0];
  s2 = new char [0];
  g = compare(this->s, other.s, this->n, other.n);

  if (g == 1) {
    res->sign = this->sign;
    s1 = this->s;
    s2 = other.s;
    n1 = this->n;
    n2 = other.n;
  } else {
    res->sign = other.sign;
    s2 = this->s;
    s1 = other.s;
    n2 = this->n;
    n1 = other.n;
  }

  if (this->sign == other.sign) {
    res->s = add(s1, s2, n1, n2);
    res->n = res->getN();
  } else {
    res->s = reduce(s1, s2, n1, n2);
    res->n = res->getN();
  }
  return * res;
}

BigNumber&
BigNumber::
operator - (BigNumber& other) {
  BigNumber * res;
  int g;
  char * s1, * s2;
  int n1, n2;

  other.sign = no(other.sign);  //here  a - b = a + (-b) so we just need to change the sign
  this->n = this->getN();
  other.n = other.getN();
  res = new BigNumber();
  s1 = new char [0];
  s2 = new char [0];
  g = compare(this->s, other.s, this->n, other.n);

  if (g == 1) {
    res->sign = this->sign;
    s1 = this->s;
    s2 = other.s;
    n1 = this->n;
    n2 = other.n;
  } else {
    res->sign = other.sign;
    s2 = this->s;
    s1 = other.s;
    n2 = this->n;
    n1 = other.n;
  }

  if (this->sign == other.sign) {
    res->s = add(s1, s2, n1, n2);
    res->n = res->getN();
  } else {
    res->s = reduce(s1, s2, n1, n2);
    res->n = res->getN();
  }
  return * res;
}

BigNumber&
BigNumber::
operator * (BigNumber& other) {
  int n1, n2, m, n_res;
  BigNumber * res;
  char * x;

  res = new BigNumber();
  this->n = this->getN();
  other.n = other.getN();

  n1 = this->n;
  n2 = other.n;
  m = n1 + n2 - 1;
  n_res = m;
  x = new char[m];

  for (int i=0;i<m;i++) {
    if(i < n1) {
      x[i] = this->s[i];
      res->s[i] = this->s[i];
    } else {
      x[i] = 48;
      res->s[i] = 48;
    }
  }

  for (int i=1;i<n2;i++) {
    if(other.s[i] == 48) {
      x[m-1] = 0;
      m -= 1;
    } else {
      x[m-1] = 0;
      m -= 1;
      res->s = add(x, res->s, m, n_res);
      n_res = res->getN();
    }
  }

  if (this->sign == other.sign) {
    res->sign = 0;
  } else {
    res->sign = 1;
  }
  res->n = res->getN();
  return * res;
}

BigNumber&
BigNumber::
operator ^ (BigNumber x) {
  BigNumber * res;
  BigNumber y;
  res = new BigNumber();
  * res = * this;
  if (x.s == '0') {
    res->s = '1';
  } else {
    while (x.s != '1') {
      * res = (* res) * (* this);
      x.s = reduce(x.s, '1', x.getN(), 1);
    }
  }
  this->n = this->getN();
  if (x % 2 == 0) {
    res->sign = true;
  } else {
    res->sign = this->sign;
  }
  return * res;
}

BigNumber&
BigNumber::
pgcd (BigNumber  & other) {
  BigNumber * res;
  int g;  // for comparing the two numbers
  char * s1, * s2, * store;
  int temp, n1, n2, n_t, n_j, i;

  res = new BigNumber();
  s1 = new char [0];
  s2 = new char [0];
  store = new char [0];
  s1 = this->s;
  s2 = other.s;
  n1 = this->getN();
  n2 = other.getN();
  g = compare (s1 , s2 , n1 , n2);
  n_j = n1;

  while(n1 != 1 && n2 != 1) {
    if(g == 0) {
      n_t = n1;
      for (i=0;i<n_t;i++) {
        store[i] = s1[i];
      }
      store[i] = 0;
      s2 = reduce (s2 , s1, n2 , n1);
      n2 = int (strlen(s2));
    } else {
      n_t = n2;
      for (i=0;i<n_t;i++) {
        store[i] = s2[i];
      }
      store[i] = 0;
      s1 = reduce (s1 , s2 , n1 , n2);
      n1 = int (strlen(s1));
    }
    g = compare (s1 , s2 , n1 , n2);
  }

  if (n1 == 1) {
    temp = s1[0] - 48;
  } else {
    temp = s2[0] - 48;
  }

  if (temp == 0)
  {
    res->s = store;
  } else {
    res->s[0] = 49;
    res->s[1] = 0;
  }

  res->sign = true;
  res->n = res->getN();
  return * res;
}

BigNumber&
BigNumber::
operator % (BigNumber& other) {
  BigNumber * res;
  int g;

  * res = * this;
  res->n = res->getN();
  g = compare(res->s , other.s , res->n , other.n);

  while (g == 1) {
    res->s = reduce(res->s , other.s , res->n , other.n);
    res->n = res->getN();
    g = compare(res->s , other.s , res->n , other.n);
  }

  if (this->sign == other.sign) {
    res->sign = true;
  } else {
    res->sign = false;
  }
  return * res;
}

ostream& operator << (ostream& out, BigNumber& obj) {
  cout<<"Le nombre est: ";
  if (obj.sign == true) {
    cout<<"+";
  } else {
    cout<<"-";
  }
  for (int i=0;i<obj.getN();i++) {
    cout<<obj.s[i];
  }
  cout<<endl;
  return out;
}

istream& operator >> (istream& in, BigNumber& obj) {
  cout<<"Le nombre: "<<endl;
  in>>obj.s;
  cout<<"Son signe: "<<endl;
  in>>obj.sign;
  return in;
}

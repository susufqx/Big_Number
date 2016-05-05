//2015-06-08
//Created by Rui
//for test


#include "BigNumber.h"

int main (int argc, char * argv[])
{
    BigNumber a;
    BigNumber b;
    BigNumber c;
    int na, nb, nc;
    int x;
    
    cout<<"****************************************"<<endl;
    cout<<"a = +1011111"<<endl;
    cout<<"b = +10110"<<endl;
    cout<<"a > 0 et b > 0";
    char ta[12]  = "1011111";
    char tb[6]   = "10110";
    a.setS(ta);
    b.setS(tb);
    na = a.getN();
    nb = b.getN();
    a.setBool(true);
    b.setBool(true);
    cout<<"addition:"<<endl;
    c = a + b;
    cout<<c<<endl;
    cout<<"soustraction:"<<endl;
    c = a - b;
    cout<<c<<endl;
    cout<<"multiplier:"<<endl;
    c = a * b;
    cout<<c<<endl;
    cout<<"couverture b^5:"<<endl;
    x  =  5;
    c  =  b^x;
    cout<<c<<endl;
    //cout<<"residu:"<<endl;
    //c = a % b;
    //cout<<c<<endl;
    
    cout<<"****************************************"<<endl;
    cout<<"a = +1100101"<<endl;
    cout<<"b = -110"<<endl;
    cout<<"a > 0 et b < 0";
    char ta1[11]  = "1100101";
    char tb1[4]   = "110";
    a.setS(ta1);
    b.setS(tb1);
    na = a.getN();
    nb = b.getN();
    a.setBool(true);
    b.setBool(false);
    cout<<"addition:"<<endl;
    c = a + b;
    cout<<c<<endl;
    cout<<"soustraction:"<<endl;
    c = a - b;
    cout<<c<<endl;
    cout<<"multiplier:"<<endl;
    c = a * b;
    cout<<c<<endl;
    cout<<"couverture b^5:"<<endl;
    x  =  5;
    c  =  b^x;
    cout<<c<<endl;
    //cout<<"residu:"<<endl;
    //c = a % b;
    //cout<<c<<endl;
    
    cout<<"****************************************"<<endl;
    cout<<"a = -10101101"<<endl;
    cout<<"b = -110"<<endl;
    cout<<"a < 0 et b < 0";
    char ta2[11]  = "10101101";
    char tb2[4]   = "110";
    a.setS(ta2);
    b.setS(tb2);
    na = a.getN();
    nb = b.getN();
    a.setBool(false);
    b.setBool(false);
    cout<<"addition:"<<endl;
    c = a + b;
    cout<<c<<endl;
    cout<<"soustraction:"<<endl;
    c = a - b;
    cout<<c<<endl;
    cout<<"multiplier:"<<endl;
    c = a * b;
    cout<<c<<endl;
    cout<<"couverture b^5:"<<endl;
    x  =  5;
    c  =  b^x;
    cout<<c<<endl;
    //cout<<"residu:"<<endl;
    //c = a % b;
    //cout<<c<<endl;
    
    cout<<"****************************************"<<endl;
    cout<<"a = -11001101"<<endl;
    cout<<"b = +110"<<endl;
    cout<<"a < 0 et b > 0";
    char ta3[11]  = "11001101";
    char tb3[4]   = "110";
    a.setS(ta3);
    b.setS(tb3);
    na = a.getN();
    nb = b.getN();
    a.setBool(false);
    b.setBool(true);
    cout<<"addition:"<<endl;
    c = a + b;
    cout<<c<<endl;
    cout<<"soustraction:"<<endl;
    c = a - b;
    cout<<c<<endl;
    cout<<"multiplier:"<<endl;
    c = a * b;
    cout<<c<<endl;
    cout<<"couverture b^5:"<<endl;
    x  =  5;
    c  =  b^x;
    cout<<c<<endl;
    //cout<<"residu:"<<endl;
    //c = a % b;
    //cout<<c<<endl;
    
    
    return 0;
}




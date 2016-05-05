//2015-06-08
//Created by Rui
//main fonction here


#include "BigNumber.h"

int main (int argc, char * argv[])
{
    //insert code here...
    BigNumber a;
    BigNumber b;
    BigNumber c;
    
    int     ope;
    int     x;
    while (1)
    {
        cout<<"Quel operation vous voulez utiliser? 1 pour plus ,2 pour moin et 3 pour multiplier"<<endl;
        cin>>ope;
    
        if (ope == 1 || ope == 2 || ope == 3 || ope == 5 || ope == 6)
        {
            cout<<"Saisir deux nombre grand et son signe, 1 est plus et 0 est moin."<<endl;
            cout<<"Nombre 1:"<<endl;
            cin>>a;
            cout<<"Nombre 2:"<<endl;
            cin>>b;
        }
        else if (ope == 4)
        {
            cout<<"Nombre:"<<endl;
            cin>>a;
            cout<<"Saisir le indice :";
            cin>>x;
        }
        else if (ope == 0)
        {
            return 0;
        }

        if (ope == 1)
        {
            c = a + b;
            cout<<c<<endl;
        }
        else if (ope == 2)
        {
            c = a - b;
            cout<<c<<endl;
        }
        else if (ope == 3)
        {
            c = a * b;
            cout<<c<<endl;
        }
        else if (ope == 4)
        {
            if (x < 0)
            {
                perror("C'est une erreur!");
                return 0;
            }
            /*
            else if (x = 0)
            {
                char  *  t;
                char  *  r;
                t    =    new char[1];
                t    =    a.getS();
                r    =    new char[1];
                r[0] =    49;
                if (a.getN() == 0 && t[0] == 48)
                {
                    perror("C'est une erreur!");
                    return 0;
                }
                else
                {
                    c.setS(r);
                    c.setBool(true);
                }
            }
            else
            {*/
            c  = a ^ (x);
           // }
            cout<<c<<endl;
        }
        else if (ope == 5)
        {
            c = a.pgcd(b);
            cout<<"Le PGCD de a et b est:"<<endl;
            cout<<c<<endl;
        }
        else if (ope == 6)
        {
            c = a % b;
            cout<<"Le residu de a et b est:"<<endl;
            cout<<c;
        }
        else
        {
            perror("C'est une erreur!");
        }
    }
    return 0;
}




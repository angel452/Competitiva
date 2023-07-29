#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string popString(string cad)
{
    string aux1 = cad.substr(0,cad.length()-1);
    return aux1;
}

void lcs(string cad1, string cad2)
{   
    if(cad1.length() == 0 || cad2.length() == 0)
    {
        cout << "FIN" << endl;
        return ;
    }

    if( cad1[cad1.length()-1] == cad2[cad2.length()-1]) 
    {
        cout << "Iguales +1" <<  endl;
        
        cout << "------- pop(cad1, cad 2) ---------" << endl;

        //string aux1 = cad1.substr(0,cad1.length()-1);
        //cad1 = aux1;
        cad1 = popString(cad1);

        //string aux2 = cad2.substr(0,cad2.length()-1);
        //cad2 = aux2;
        cad2 = popString(cad2);

        cout << cad1 << " - " << cad2 << endl;

        lcs( cad1, cad2 );
    }

    else
    {
        //Repartimos

        // hijo izquierdo
        cout << "------- -cad1 ---------" << endl;
        string aux1 = popString(cad1);
        cout << aux1 << endl;
        cout << cad2 <<  endl;
        cout << "----------------" << endl;
        lcs( aux1, cad2 );

        //hijo derecho
        string aux2 = popString(cad2);
        cout << "------- -cad2 ---------" << endl;
        cout << cad1 << endl;
        cout << aux2 <<  endl;
        cout << "----------------" << endl;
        lcs ( cad1, aux2 );
    }

}

int main(){

    string cad1;
    string cad2;

    cout << "Cadena 1: "; cin >> cad1;
    cout << "Cadena 2: "; cin >> cad2;

    lcs(cad1, cad2);

    return 0; 
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{

    int l1, r1, l2, r2;

    cin >> l1;
    cin >> r1;
    cin >> l2;
    cin >> r2;

    if(l1 > l2)
    {
        int aux1, aux2;
        aux1 = l1;
        aux2 = r1;

        l1 = l2;
        r1 = r2;

        l2 = aux1;
        r2 = aux2;
    }

    if(l1 > l2 && r2 > r1)
    {
        cout << r1 - l1 << endl; 
    }
    else if( l2 > l1 && r1 > r2 )
    {
        cout << r2 - l2 << endl;
    }
    else if(l2 < r1)
    {
        cout << r1 - l2 << endl;
    }
    else{
        cout << "0" << endl;
    }

    return 0;
}
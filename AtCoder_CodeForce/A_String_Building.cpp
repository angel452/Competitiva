#include <iostream>
#include <string>
#include <vector>
using namespace std;

//https://codeforces.com/contest/1671/problem/A

static bool verificador = true;
static int contador = 0;

bool function( vector<char> vec, int inicio)
{
    
    if(verificador==false)
    {
        return false;
    }

    int puntero = inicio;
    vector <char> aux1;
    aux1.push_back(vec[puntero]);
    contador++;

    while ( aux1[0] == vec[puntero+1] && contador < vec.size() )
    {
        puntero++;
        aux1.push_back(vec[puntero]);
        contador++;
    }

    /*
    cout << "AUX: " << endl;
    for(int i=0; i < aux1.size(); i++)
    {
        cout << aux1[i] << " "; 
    }
    cout <<endl << "Fin del aux" << endl;
    */

    if(aux1.size() == 1)
    {
        //cout << "FALSE section" << endl;
        verificador = false;
    }
    else
    {
        if(contador==vec.size())
        {   
            //cout << "Termino str" << endl;
            return true; // ----------------
        }
        function(vec,contador);
    }

    if(verificador==false)
    {
        return false;
    }
}

int main()
{    
    int numVeces; cin >> numVeces;

    for(int i = 0; i < numVeces; i++)
    {
        string str;
        cin>>str;

        // guardamos en un vector
        vector <char> vec;
        for(int i = 0; i < str.length(); i++)
        {
            vec.push_back(str[i]);
        }

        // -----------------------------------------------
        
        bool res = function(vec,0);
        if(res == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        verificador = true;
        contador = 0;

    }

    return 0;
}
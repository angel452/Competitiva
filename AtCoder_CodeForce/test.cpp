#include <iostream>
#include <string>
using namespace std;

int modulo(int a, int b)
{
    int r = a - ((a/b)*b);
    cout << "r: " << r << endl;    
    if (r < 0)
    {
        while(r<0){
            r += b;
        }
        return r;
    }
    cout << "r despues: " << r << endl;
    return r;
}

int main()
{
    long long n;
    cin >> n;

    long long aux = n%998244353;
    //int aux = -5%3;

    long long aux2 = -10980687883%998244353;
    cout << "Prueba: " << aux2 << endl;

    long long aux3 = 150994942-9982443534;
    cout << "Prueba2: " << aux3 << endl;
    long long aux4 = aux2%998244353;
    cout << "Prueba2: " << aux4 << endl;

    cout << "Respuesta: " << aux;
}
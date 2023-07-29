#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    int n ;
    cin>>n;
    
    while(n%4 != 2)
    {
        n = n + 1;
    }
    
    cout<< n << endl;
    
    return 0;
}
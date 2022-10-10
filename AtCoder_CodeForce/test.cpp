#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int,int> mp[10];

    mp[0][0] = 5;
    mp[0][1] = 4;
    mp[0][2] = 3;
    mp[0][3] = 2;
    mp[1][4] = 1;

    map<int,int>::iterator i;
    for(i = mp[0].begin(); i != mp[0].end(); i++)
    {
        cout << i->first  << " -> " << i->second << endl;
    }

    vector<int> adj[5];
    for(int i=0; i<5; i++)
    {
		int m = 0;
		int k = 1;
		adj[m].push_back(k);
		adj[k].push_back(m);
		mp[m][k]=i+1;
		mp[k][m]=i+1;
	}

    for(int i = 5; i >= 0; i--) if(i != 3)
    {
        cout << i << " "; 
    }

    cout << endl;
    for(int i=24; i+1; i--)
    {
        cout << i << " "; 
    }

}
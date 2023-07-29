#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

ll k;
queue<ll> path;
vector<ll> vec[505];

void seeVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++) 
    {
        cout << vec[i] << " ";
    }
}

// ------------------------ Logic --------------------------------------
vector<int> countVisit(vector<int> vec, vector<vector<ll>> uniones, int n, vector<int> res)
{
    //seeVector(vec);

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < vec.size() - 1; j++) 
        {
            if ( (uniones[i][0] == vec[j]+1) && (uniones[i][1] == vec[j+1]+1) ) 
            {
                res[i] = res[i] + 1;
            } 
            
            else if ( (uniones[i][0] == vec[j+1]+1) && (uniones[i][1] == vec[j]+1) ) 
            {
                res[i] = res[i] + 1;
            }
        }
    }

    //cout << endl << "Respuesta Acumulada: " << endl;
    //seeVector(res);

     return res;
}


bool BFS(vector<ll> adj[], int src, int dest, int v, ll pred[], ll dist[]) 
{
    list<ll> queue;
    bool visited[v];

    for (int i = 0; i < v; i++) 
    {
        visited[i] = false;
        dist[i] = 9999999;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) 
    {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) 
        {
            if (visited[adj[u][i]] == false) 
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == dest)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

vector<int> printShortestDistance(vector<ll> adj[], int s, int dest, int v) 
{
    ll pred[v], dist[v];

    if (BFS(adj, s, dest, v, pred, dist) == false) 
    {
        //cout << "Given source and destination" << " are not connected";
        return {};
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) 
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    /*
    //IMPRESION DEL PATH
    
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    } 
    */

    return path;
}

void solve() 
{
    ll n;
    //cout << "Numero de ciudades: ";
    cin >> n;

    vector<vector<ll>> uniones(n-1);
       //uniones.reserve(n - 1);

    // llenado de matriz
    vector<ll> adj[n];
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a;
        cin >> b;

        uniones[i].push_back(a);
        uniones[i].push_back(b);

        a = a - 1;
        b = b - 1;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    /*
    // IMPRESION DE MATRIX MAP
    
    cout << "---- Matrix ------- ";
    cout << endl;
    for (ll i = 0; i < sizeof(adj) / sizeof(adj[0]); i++) 
    {
        for (ll j = 0; j < adj[i].size(); j++) 
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */

    cin >> k;
    vector<int> res(n - 1, 0);

    /*
    //IMPRESION DE LOS CAMINOS DISPONIBLES
    cout << " Uniones " << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 2; j++) {
        cout << uniones[i][j] << " ";
        }
        cout << endl;
    }
    */

    for (int i = 0; i < k; i++) {
        int ini, fin;
        cin >> ini;
        cin >> fin;
        
        res = countVisit(printShortestDistance(adj, ini - 1, fin - 1, n), uniones, n, res);
    }

    seeVector(res);
}

/*
void showq(queue<ll> gq) {
  cout << endl << " --- Entra en funcion 1 ----"  << endl;
  queue<ll> g = gq;
  while (!g.empty()) {
    cout << "->" << g.front() + 1 << " ";
    g.pop();
  }
  cout << '\n';
}
*/

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  // cin >> n;
  solve();
  // showq(path);
  return 0;
}
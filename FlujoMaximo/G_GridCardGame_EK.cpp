#include <iostream>
#include <queue>
#include <cstring>

#define MAX 101

using namespace std;
typedef long long ll;

const ll inf = 1e18;
int h, w;
ll a[105][105];
ll rsum[105], csum[105];

int graph[MAX][MAX];

bool BFS(int ways[MAX][MAX], int* parent, bool* visited, int n, int s, int t) {
	queue<int> q;
	parent[s] = -1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && ways[u][i] > 0) {
				q.push(i);
				parent[i] = u;
				visited[i] = true;
			}
		}
	}
	return visited[t];
}

int FordFulkerson(int n, int s, int t) { 
	
	int rGraph[MAX][MAX];
	int parent[MAX];
	bool visited[MAX];
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			rGraph[i][j] = graph[i][j];
			
			int max_flow = 0;
			
			while (BFS(rGraph, parent, visited, n, s, t)) {
				// while (DFS(rGraph, parent, visited, n, s, t)){
				memset(visited, false, sizeof(visited));
				int path_flow = 0xfffffff; 
				for (int v = t; v != s; v = parent[v]) {
					int u = parent[v];
					path_flow = min(path_flow, rGraph[u][v]);
				}
				for (int v = t; v != s; v = parent[v]) {
					int u = parent[v];
					rGraph[u][v] -= path_flow;
					rGraph[v][u] += path_flow;
				}
				max_flow += path_flow;
			}
			return max_flow;
}

void addEdge(int ini, int fin, int capacidad){
	graph[ini][fin] = capacidad;
}

int main(void)
{
    //cout << "Filas: "; 
    cin >> h;
    //cout << "Columnas: "; 
    cin >> w;
    for(int i = 1; i <= h; i++) 
    {
        for(int j = 1; j <= w; j++) 
        {
            //cout << "Pos [" << i << "][" << j << "]: "; 
            cin >> a[i][j];
        }
    }

	int V = h+w+2;
    //Graph g(h+w+2);
    int S = 0, T = h+w+1; ll ans = 0;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++){
            if(a[i][j] >= 0){
                //cout << "Mayor a 0" << endl;
                addEdge(i, h+j, a[i][j]);
                ans += a[i][j];
            }
            else{ 
                //cout << "Menor a 0" << endl;
                addEdge(h+j, i, 99999);
                rsum[i] -= a[i][j];
                csum[j] -= a[i][j];
            }
        }
    }
    for(int i = 1; i <= h; i++){ 
        addEdge(S, i, rsum[i]);
    }

    for(int j = 1; j <= w; j++){
        addEdge(h+j, T, csum[j]);
    }

	cout << endl << "Utilizando Algoritmo Edmonds Karp: " << endl;
    cout << ans - FordFulkerson(V, S, T) << endl;
    return 0;
}
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int graph[MAX][MAX];

bool DFS(int rGraph[MAX][MAX], int* parent, bool* visited, int n, int x, int t) {
	if (x == t) return true;
	visited[x] = true;
	for (int i = 0; i < n; ++i) {
		if (rGraph[x][i] > 0 && !visited[i]) {
			parent[i] = x;
			if (DFS(rGraph, parent, visited, n, i, t))
				return true;
		}
	}
	return false;
}

int FordFulkerson(int n, int s, int t) { 
	
	int rGraph[MAX][MAX];
	int parent[MAX];
	bool visited[MAX];
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			rGraph[i][j] = graph[i][j];
			
			int max_flow = 0;
			
			while (DFS(rGraph, parent, visited, n, s, t)) {
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

int main (){
	int V = 6;

	addEdge(0, 1, 16);
	addEdge(0, 2, 13);
	addEdge(1, 2, 10);
	addEdge(2, 1, 4);
	addEdge(1, 3, 12);
	addEdge(2, 4, 14);
	addEdge(3, 2, 9);
	addEdge(3, 5, 20);
	addEdge(4, 3, 7);
	addEdge(4, 5, 4);

	int s = 0, t = 5;
	cout << "Max Flow: " << FordFulkerson(V, s, t) << endl;
}

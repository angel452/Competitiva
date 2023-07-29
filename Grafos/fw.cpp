
#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;
 
// Number of vertices in the graph
#define V 4
 
/* Define Infinite as a large enough
  value. This value will be used
  for vertices not connected to each other */
#define INF 99999

void printSolution(int dist[][V])
{
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
void fw(int graph[][V]){

    int dist[V][V], i, j, k;
 
    
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            if (i == k) continue;
            
            for (j = 0; j < V; j++) {
                
                if (k==i || j==k) continue;

                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

 

int main() {
    //N is the number of vertices
    //int N;
    //cin >> N;
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    //vector<int> graph[N];
    //T is the number of edges
    /*int T;
    cin>>T;
    while(T>0){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        T--;
    }*/
    fw(graph);
    
    return 0;
}
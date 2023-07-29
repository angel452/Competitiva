#include <iostream>
#include "maxflow.hpp"
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int h, w;
ll a[105][105];
ll rsum[105], csum[105];
int main(void)
{
cin >> h >> w;
for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >>
a[i][j];
atcoder::mf_graph<ll> g(h+w+2);
int S = 0, T = h+w+1; ll ans = 0;
for(int i = 1; i <= h; i++){
for(int j = 1; j <= w; j++){
if(a[i][j] >= 0) g.add_edge(i, h+j, a[i][j]), ans += a[i][j];
else g.add_edge(h+j, i, inf), rsum[i] -= a[i][j], csum[j] -=
a[i][j];
}
}
for(int i = 1; i <= h; i++) g.add_edge(S, i, rsum[i]);
for(int j = 1; j <= w; j++) g.add_edge(h+j, T, csum[j]);

cout << endl << "Utilizando Algoritmo Dinic: " << endl;
cout << ans - g.flow(S, T) << endl;
return 0;
}
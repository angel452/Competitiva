#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 310
#define INF 0x3f3f3f3f

int n,dp[N*2][N][N],a[N][N];

int Max(int a,int b,int c,int d){
	int p = a > b ? a : b;
	int q = c > d ? c : d;
	return p > q ? p : q;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf("%d",&a[i][j]);

		for(int i = 1; i <= 2*n; i++)
			for(int j = 0; j <= n; j++)
				for(int k = 0; k <= n; k++)
					dp[i][j][k] = -INF;

		dp[1][1][1] = a[1][1];
        
		for(int i = 2; i <= 2*n-1; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= n; k++){
					dp[i][j][k] = Max(dp[i-1][j-1][k],dp[i-1][j-1][k-1],dp[i-1][j][k-1],dp[i-1][j][k]);
					int ca = i + 1 - j;
					int cb = i + 1 - k;
					int cnt = 0;
					if(1 <= ca && ca <= n){
						dp[i][j][k] += a[j][ca]; cnt++;
					}
					if(1 <= cb && cb <= n){
						dp[i][j][k] += a[k][cb]; cnt++;
					}
					if(cnt == 2 && j == k) 
						dp[i][j][k] -= a[j][ca];
				}
		printf("%d\n",dp[2*n-1][n][n]);
		
		cout << "------------ DP --------------"<<  endl;
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 7; j++)
			{
				for(int k = 0; k < 7; k++){
					cout << dp[i][j][k] <<  " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << "-------------------------------" << endl;
	}
	return 0;
}
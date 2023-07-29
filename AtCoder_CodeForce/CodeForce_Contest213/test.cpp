// LUOGU_RID: 90883875
#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,a[N][N];
int dp[N<<1][N][N];
void umax(int &x,int y){x=max(x,y);}
int main(){
    memset(dp,~0x3f,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
    }
    dp[1][1][1]=a[1][1];
    for(int i=2;i<n<<1;i++){
        int l=1,r=n;
        if(i>n) l=i-n+1;
        else r=i;
        for(int j=l;j<=r;j++){
            for(int k=l;k<=r;k++){
                umax(dp[i][j][k],dp[i-1][j-1][k-1]);
                umax(dp[i][j][k],dp[i-1][j-1][k]);
                umax(dp[i][j][k],dp[i-1][j][k-1]);
                umax(dp[i][j][k],dp[i-1][j][k]);
                dp[i][j][k]+=a[i+1-j][j];
                if(j!=k) dp[i][j][k]+=a[i+1-k][k];
            }
        }
    }

    cout << "   DP    "<<  endl;
    for(int i = 0; i < n<<1; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++){
                cout << dp[i][j][k] <<  '\t';
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "RES1: " << dp[(n*2)-1][n][n] << endl;

    printf("%d\n",dp[(n<<1)-1][n][n]);
    return 0;
}
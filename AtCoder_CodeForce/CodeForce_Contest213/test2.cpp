#include <iostream>
using namespace std;

void maxFunc(int &x, int y){
    x = max(x,y);
}

int main()
{
    int n;
    cin >> n;

    int dp[2*n][n][n];
    int matrix[n][n];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    dp[0][0][0] = matrix[0][0];

    for(int i=1; i < n*2; i++)
    {
        int l = 0;
        int r = n;
        
        if( i > n ){
            //l = i-n+1;
            l = i - n;
        } 
        else{
            r = i;
        } 

        for(int j = l; j <= r; j++)
        {
            for(int k = l; k <= r; k++)
            {
                maxFunc(dp[i][j][k],dp[i-1][j-1][k-1]);
                maxFunc(dp[i][j][k],dp[i-1][j-1][k]);
                maxFunc(dp[i][j][k],dp[i-1][j][k-1]);
                maxFunc(dp[i][j][k],dp[i-1][j][k]);

                dp[i][j][k] += matrix[i+1-j][j];
                if(j!=k)
                {
                   dp[i][j][k] += matrix[i+1-k][k]; 
                } 
            }
        }
    }

    cout << "   DP    "<<  endl;
    for(int i = 0; i < n*2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++){
                cout << dp[i][j][k] <<  " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << dp[ (n*2)-1 ][n][n];

    return 0;
}
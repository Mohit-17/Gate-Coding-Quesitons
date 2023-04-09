#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    int dp[n+1][k+1];
    for(int i = 0;i <=n;i++)
        dp[i][0] = 0;
    for(int j = 0;j <= k;j++)
        dp[0][j] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            if(dp[i-1][j])
                dp[i][j] = 1;
            else if( arr[i-1] == j )
                dp[i][j] = 1;
            else if( j - arr[i-1] >= 0 ){
                if(dp[i-1][j - arr[i-1]] == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][k];
}
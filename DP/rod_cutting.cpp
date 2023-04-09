#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int> price,int n,vector<int> &dp){
	if(n == 0){
		dp[n] = 0; 
		return 0;
	}
	if(dp[n] != -1)
		return dp[n];
	int q = INT_MIN;
	for(int i = 1;i <= n;i++){
		q = max(q,price[i-1] + recursive(price,n-i,dp));
	}
	dp[n] = q;
	return q;
}

int topdown(vector<int> price,int n,vector<int> &dp){
	dp[0] = 0;
	for(int j = 1;j <= n;j++){
		int q = INT_MIN;
		for(int i = 1;i <= j;i++)
			q = max(q,price[i-1] + dp[j-i]);
		dp[j] = q;
	}
	return dp[n];
}

int cutRod(vector<int> &price, int n)
{
	// vector<int> dp(n+1,-1);
	// return recursive(price,n,dp);
	vector<int> dp(n + 1,-1);
	return topdown(price,n,dp);
}

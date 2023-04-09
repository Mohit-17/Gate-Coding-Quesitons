#include <bits/stdc++.h> 
using namespace std;

int sum_freq(vector<int> freq,int i,int j){
	int sum = 0;
	for(int k = i;k <= j;k++)
		sum += freq[k];
	return sum;
}

int optimalCost(vector<int>& keys, vector<int>& freq, int n)
{
	int e[n][n];
	for(int l = 1;l <= n;l++){
		for(int i = 0;i <= n - l + 1;i++){
			int j = i + l - 1;
			int cost = INT_MAX;
			int sum = sum_freq(freq,i,j);
			for(int r = i; r <= j;r++){
				int left_subtree = 0,right_subtree = 0;
				if(r > i)
					left_subtree = e[i][r-1];
				if(r < j)
					right_subtree = e[r+1][j];
				int c = left_subtree + right_subtree + sum;
				if(c < cost)
					cost = c;
			}
			e[i][j] = cost;
		}
	}
	return e[0][n-1];
}
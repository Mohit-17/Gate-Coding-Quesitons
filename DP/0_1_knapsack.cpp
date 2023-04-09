#include <bits/stdc++.h> 
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	int arr[n+1][maxWeight+1];
	
	for(int i = 0;i <= n;i++)
		arr[i][0] = 0;
	
	for(int j = 0;j <= maxWeight;j++)
		arr[0][j] = 0;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= maxWeight;j++){
			if(weight[i-1] > j)
				arr[i][j] = arr[i-1][j];
			else 
				if(j - weight[i-1] >= 0)
					arr[i][j] = max(arr[i-1][j],value[i-1] + arr[i-1][j-weight[i-1]]);
				else	
					arr[i][j] = arr[i-1][j];
		}
	}
	return arr[n][maxWeight];

}
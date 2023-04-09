#include<bits/stdc++.h>
using namespace std;
int timer = 0;
void dfs(vector<vector<int>> &adj,int element,vector<bool> &visited
		,set<pair<int,int>,greater<pair<int,int>>> &finish){
	visited[element] = true;
	for(auto it:adj[element]){
		if(!visited[it])
			dfs(adj,it,visited,finish);
	}
	timer++;
	finish.insert({timer,element});
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//prepare adj list
	vector<vector<int>> adj_1(v);
	vector<vector<int>> adj_2(v);
	set<pair<int,int>,greater<pair<int,int>>> finish;
	vector<bool> visited(v,false);
	for(auto it:edges){
		int u = it[0];
		int v = it[1];
		adj_1[u].push_back(v);
		adj_2[v].push_back(u);
	}
	for(int i = 0;i < v;i++){
		if(!visited[i])
			dfs(adj_1,i,visited,finish);
	}
	int components = 0;
	timer = 0;
	for(int i = 0;i < v;i++)
		visited[i] = false;
	for(auto it:finish){
		if(!visited[it.second]){
			dfs(adj_2,it.second,visited,finish);
			components++;
		}
	}
	return components;
}
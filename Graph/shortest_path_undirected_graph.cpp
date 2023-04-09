#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//prepare adj list
	unordered_map<int,list<int>> adjList;
	for(auto it:edges){
		int u = it.first;
		int v = it.second;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	vector<bool> visited(n+1,false);
	queue<int> bfs;
	bfs.push(s);
	visited[s] = true;
	vector<int> parent(n+1);
	while(!bfs.empty()){
		int front = bfs.front();
		bfs.pop();
		for(auto it:adjList[front]){
			if(!visited[it]){
				parent[it] = front;
				if(it == t){
					while(!bfs.empty())
						bfs.pop();
					break;
				}
				visited[it] = true;
				bfs.push(it);
			}
		}
	}
	stack<int> ans;
	vector<int> path;
	int i = t;
	while(i != s){
		ans.push(i);
		i = parent[i];
	}
	path.push_back(s);
	while(!ans.empty()){
		path.push_back(ans.top());
		ans.pop();
	}
	return path;
}

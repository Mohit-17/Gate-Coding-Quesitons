#include <bits/stdc++.h> 
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int,int>>> adj(n + 1);
    for(auto it:g){
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>> > pq;
    
    vector<int> visited(n + 1,0);
    vector<int> key(n + 1,0);
    vector<pair<pair<int, int>, int>> ans;
    
    pq.push({{0,1},-1});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.first.second;
        int wt = it.first.first;
        int parent = it.second;
        if(visited[node]) continue;
        visited[node] = 1;
        if(parent != -1)
            ans.push_back({{parent,node},wt});
        for(auto it2:adj[node]){
            int adjNode = it2.first;
            int weight = it2.second;
            if(!visited[adjNode]){
                pq.push({{weight,adjNode},node});
            }
        }
        
    }
    return ans;

}


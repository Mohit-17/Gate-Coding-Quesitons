#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(vector<vector<int>> &adj,int node,int parent,int discover[],int low[],
            vector<bool> &visited,vector<vector<int>> &bridges)
{
    visited[node] = true;
    discover[node] = timer;
    low[node] = timer;
    timer++;
    for(auto it:adj[node]){
        if(it == parent)
            continue;
        if(!visited[it]){
            dfs(adj,it,node,discover,low,visited,bridges);
            low[node] = min(low[node],low[it]);
            if(low[it] > discover[node])
                bridges.push_back({node,it});
        } else {
            low[node] = min(low[node],low[it]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v);
    for(int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> bridges;
    vector<bool> visited(v);
    int discover[v];
    int low[v];
    dfs(adj,0,-1,discover,low,visited,bridges);
    return bridges;
}
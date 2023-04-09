#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int,vector<int>> &list,
        vector<vector<int>>& edges){
    for(int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        list[u].push_back(v);
        list[v].push_back(u);
    }
}

bool bfs_traversal(unordered_map<int,vector<int>> &list,
        unordered_map<int,bool> &visited,int element)
{
    unordered_map<int,int> parent;
    parent[element] = -1;
    visited[element] = true;
    queue<int> traversal;
    traversal.push(element);
    while(!traversal.empty()){
        int temp = traversal.front();
        traversal.pop();
        for(auto it:list[temp]){
            if(visited[it] && it != parent[temp]){
                return true;
            } else if(!visited[it]){
                    traversal.push(it);
                    visited[it] = true;
                    parent[it] = temp;
                }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,vector<int>> list;
    prepareAdjList(list,edges);
    bool flag = false;
    unordered_map<int,bool> visited;
    for(int i = 0; i < n;i++){
        if(!visited[i] && !flag){
            flag = bfs_traversal(list,visited,i);
        }
    }
    if(flag)
        return "Yes";
    else
        return "No";
}

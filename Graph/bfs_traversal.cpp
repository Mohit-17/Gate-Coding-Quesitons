#include <bits/stdc++.h> 
using namespace std;

vector<int>bfs;

void prepareAdjList(unordered_map<int,set<int>>&adjList,
            vector<pair<int, int>> &edges)
{
    for(int i = 0;i < edges.size();i++){
        int u,v;
        u = edges[i].first;
        v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs_traversal(unordered_map<int,set<int>>&adjList,
        unordered_map<int,bool>&visited, int start)
{
    queue<int>traversal;
    traversal.push(start);
    visited[start] = true;
    while(!traversal.empty()){
        int temp = traversal.front();
        traversal.pop();
        bfs.push_back(temp);
        for(auto it:adjList[temp]){
            if(!visited[it]){
                visited[it] = true;
                traversal.push(it);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>>adjList;
    unordered_map<int,bool>visited;

    prepareAdjList(adjList,edges);    
    for(int i = 0;i < vertex;i++){
        if(!visited[i]){
            bfs_traversal(adjList,visited,i);
        }
    }
    return bfs;
}
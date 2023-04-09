#include <bits/stdc++.h> 
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> adjList(n);
    for(int i = 0;i < n;i++){
        adjList[i].push_back(i);
    }
    for(int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}
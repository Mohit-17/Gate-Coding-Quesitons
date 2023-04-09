#include<bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    //prepare adjacency list
    vector<int> indegree(n + 1, 0);
    unordered_map<int,vector<int>> adjList(n + 1);
    for(auto it:edges){
        int u = it.first;
        int v = it.second;
        adjList[u].push_back(v);
        indegree[v]++;
    }
    bool flag = false;
    queue<int> bfs;
    for(int i = 1;i <= n;i++){
        if(indegree[i] == 0)
            bfs.push(i);
    }
    int count = 0;
    while(!bfs.empty()){
        int front = bfs.front();
        bfs.pop();
        count++;
        for(auto it:adjList[front]){
            indegree[it]--;
            if(indegree[it] == 0)
                bfs.push(it);
        }
    }
    if(count == n)
        return false;
    else return true;
}
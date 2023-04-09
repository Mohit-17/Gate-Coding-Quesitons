#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,vector<int>> adjList(v);
    for(int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }    
    vector<int> indegree(v);
    for(int i = 0;i < adjList.size();i++){
        for(int j = 0;j < adjList[i].size();j++){
            indegree[adjList[i][j]]++;
        }
    } 
    
    vector<bool> visited(v);
    vector<int> ans;

    queue<int> q;

    for(int i = 0;i < v;i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    //bfs

    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto it:adjList[front]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}
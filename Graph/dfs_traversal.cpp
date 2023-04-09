#include<bits/stdc++.h>
using namespace std;

void prepareList(unordered_map<int,set<int>>&list,
        vector<vector<int>> &edges) {
    for(int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        list[u].insert(v);
        list[v].insert(u);
    }
}

vector<int> dfs_traversal(unordered_map<int,set<int>> &list,
        unordered_map<int,bool> &visited,int element,vector<int> &temp){
    visited[element] = true;
    temp.push_back(element);
    for(auto it:list[element]){
        if(!visited[it])
            dfs_traversal(list,visited,it,temp);
    }
    return temp;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    
    //1st -> no of components
    //2nd -> vertices of those components in sorted order
    unordered_map<int,set<int>>list;
    unordered_map<int,bool>visited;
    vector<vector<int>> ans;
    prepareList(list,edges);
    for(int i = 0;i < V;i++){
      if (!visited[i]) {
        vector<int> temp;
        temp = dfs_traversal(list, visited, i, temp);
        ans.push_back(temp);
      }
    }
    return ans;
}
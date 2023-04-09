#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min_heap
    
    vector<vector<pair<int,int>>> adj(vertices); //adjacency List

    //create adjacency list
    for(int i = 0;i < vec.size();i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];
        pair<int,int> p1 = make_pair(v,weight);
        pair<int,int> p2 = make_pair(u,weight);
        adj[u].push_back(p1);
        adj[v].push_back(p2);
    }

    vector<int> distance(vertices);
    
    for(int i = 0;i < vertices;i++)
        distance[i] = INT_MAX;
    
    distance[source] = 0;
    pq.push({0,source});
    
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int weight = it.second;
            int adjNode = it.first;

            if(dis + weight < distance[adjNode]){
                distance[adjNode] = dis + weight;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }
    return distance;
}

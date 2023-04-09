#include <bits/stdc++.h> 

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> distance(n+1,1e9);
    distance[src] = 0;
    for(int i = 1;i < n;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if( (distance[u] != 1e9) && (distance[u] + wt < distance[v]) ){
                distance[v] = distance[u] + wt;
            }
        }
    }
    return distance[dest];
}
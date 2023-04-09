//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {

  private:
  public:
    
    int timer = 1;
    
    void dfs(int node,int parent,vector<int> &vis,int tin[],
              int low[],vector<int> &mark,vector<int> adj[])
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it:adj[node]){
            if(it == parent)
                continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,mark,adj);
                low[node] = min(low[node],low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node],tin[it]);
            }
        }
        if(parent == -1 && child > 1){
            mark[node] = 1;
        }
    }
    
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> visited(n,0);
        int discover[n];
        int low[n];
        vector<int> articulation_points;
        // int mark[n] = {0};
        vector<int> mark(n,0);
        for(int i = 0;i < n;i++){
            if(!visited[i])
                dfs(i,-1,visited,discover,low,mark,adj);
        }
        for(int i = 0;i < n;i++){
            if(mark[i] == 1)
                articulation_points.push_back(i);
        }
        if(articulation_points.size() == 0)
            return {-1};
        return articulation_points;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
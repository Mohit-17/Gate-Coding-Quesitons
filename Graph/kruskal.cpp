#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
            unordered_map<int,list< pair<int,int> > > adj;

    void addEdge(int u, int v,int wt,int direction){
        //direction = 0 -> undirected
        //direction = 1 -> directed

        //create an edge from u to v
        adj[u].push_back({v,wt});
        if(!direction)
            adj[v].push_back({u,wt});
        
    }

    void printAdjList(){
        for(auto it1:adj){
            cout<<it1.first << "-> ";
            for(auto it2:it1.second){
                cout<<it2.first<<" "<<it2.second <<", ";
            }
            cout<<"\n";
        }
    }

    unordered_map<int,list< pair<int,int> > > returnList(){
        return adj;
    }
};

class DisjointSet{
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n + 1,0);
            size.resize(n + 1,0);
            parent.resize(n + 1);
            for(int i = 0;i <= n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
    
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); //path compression
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main(){

    //Graph Creation
    int n;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    int m;
    cout<<"Enter the number of edges\n";
    cin>>m;

    Graph g;

    for(int i = 0;i < m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;

        g.addEdge(u,v,wt,0);
    }

    // g.printAdjList();

    //Computing MST
    unordered_map<int,list< pair<int,int> > > adj = g.returnList();
    vector<pair<int, pair<int,int>>> edges;
    for(int i = 0;i < n;i++){
        for(auto it:adj[i]){
            int adjNode = it.first;
            int wt = it.second;
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    int mstWt = 0;
    
    DisjointSet ds(n);
    for(auto it:edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUPar(u) != ds.findUPar(v)){
            mstWt += wt;
            ds.unionByRank(u,v);
        }
    }
    cout<<"Minumum weight is "<<mstWt<<"\n";
}
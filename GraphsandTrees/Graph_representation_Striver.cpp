#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    // graph reprsentation using adjacency matrix -> SC : O(n^2)
    vector<vector<int>> adj(n+1,vector<int>(m+1));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    // using adjacency list -> space complexity : O(2*E)
    vector<vector<int>> ad(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}
#include<bits/stdc++.h>
using namespace std;
// Depth first search Algorithm
// we will use Adjacency List for representing graph - as global variable
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u){
    // mark as visited
    visited[u]=true;
    cout<<"Visited Node: "<<u<<endl; // Debug print

    // Iterate over neighbours
    for(int i=0;i<adj[u].size();i++){
        if(!visited[adj[u][i]]){
            dfs(adj[u][i]);
        }
    }
}

int main(){
    int n=5; // list of nodes
    adj.resize(n);
    visited.assign(n,false);

    // Edges : 0-1,0-2,1-3,1-4 (Example)
    adj[0]={1,2};
    adj[1]={0,3,4};
    adj[2]={0};
    adj[3]={1};
    adj[4]={1};

    // start DFS from node 0
    dfs(0);
    return 0;
}
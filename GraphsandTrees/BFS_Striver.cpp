#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

vector<int> bfsOGraph(int V,vector<vector<int>> &adj){ // adj is vector of arrays
    // V is the number of nodes and adjasancy list is given;
    // we will start from node 0
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(q.empty()!=1){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            if(vis[adj[node][i]]==0){
                q.push(adj[node][i]);
                vis[adj[node][i]]=1;
            }
        }
    }
    return bfs; // SC: O(3*n) & TC: O(N)+O(2E)
}

int main(){
    int n=5; // list of nodes
    adj.resize(n);
    vis.assign(n,false);

    // Edges : 0-1,0-2,1-3,1-4 (Example)
    adj[0]={1,2};
    adj[1]={0,3,4};
    adj[2]={0};
    adj[3]={1};
    adj[4]={1};

    vector<int> bfs=bfsOGraph(n,adj);
    for(int i=0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
    }
    cout<<endl;
    return 0;
}
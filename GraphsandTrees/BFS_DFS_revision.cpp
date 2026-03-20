#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;

void dfs_basic(vector<vector<int>> &adj,vector<bool> &vis,int start){
    vis[start]=1;
    cout<<start<<" ";
    for(int v:adj[start]){
        if(vis[v]==0){
            dfs_basic(adj,vis,v);
        }
    }
}

vector<int> bfs_basic(vector<vector<int>> &adj,vector<bool> &vis,int start){
    queue<int> q;
    q.push(start);
    vector<int> bfs;
    vis[start]=true;
    while(q.empty()!=1){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(int v:adj[node]){
            if(vis[v]==0){
                q.push(v);
                vis[v]=true;
                // always at bfs, mark visited when pushing into the queue not when popping.....people make this mistake ok
            }
        }
    }
    return bfs;
}


int main(){
    int n=7;
    adj.resize(7);
    vis.assign(7,false);
    adj[0]={1,2};
    adj[1]={0,3,5};
    adj[2]={0,4};
    adj[3]={1};
    adj[4]={2};
    adj[5]={1,6};
    adj[6]={5};
    // dfs_basic(adj,vis,0);

    vector<int> bfss=bfs_basic(adj,vis,0);
    for(int i=0;i<bfss.size();i++){
        cout<<bfss[i]<<" ";
    }
    cout<<endl;


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;


// using bfs
int fun_bfs_check(vector<vector<int>> &adj,vector<bool> &vis,int src){
    // return 1 if there exist a cycle, else 0
    // start with 0
    queue<pair<int,int>> q; // for storing -> {node,parent}
    q.push({src,-1});  // source node has no parent
    vis[src]=true;
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second; // each node would have only 1 parent in bfs
        q.pop();
        for(int v:adj[node]){
            if(v==parent){
                continue;
            }
            if(vis[v]==false){
                q.push({v,node});
                vis[v]=true;
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}


// using dfs
int fun_dfs_check(vector<vector<int>> &adj,vector<bool> &vis,int src,int parent){
    vis[src]=true;
    for(int v:adj[src]){
        if(vis[v]==1 && v!=parent){
            return 1;
        }
        else if(vis[v]==0){
            if(fun_dfs_check(adj,vis,v,src)==1){
                return 1;
            }
        }
        else{
            continue;
        }
    }
    return 0;
}

int main(){
    int n=7;
    adj.resize(n);
    vis.assign(n,false);
    adj[0]={1,2};
    adj[1]={0,4};
    adj[2]={0,5};
    adj[3]={2};
    adj[4]={1,6};
    adj[5]={2,6};
    adj[6]={4,5};

    int res=0;
    for(int i=0;i<n;i++){ // we do this since graph may have disconnected componenets
        if(vis[i]==0){
            res=max(res,fun_dfs_check(adj,vis,i,-1));
        }
        if(res==1){
            break;
        }
    }
    if(res==1){
        cout<<"There exist a cycle"<<endl;
    }
    else{
        cout<<"There doesnt exist a cycle"<<endl;
    }
    return 0;
}
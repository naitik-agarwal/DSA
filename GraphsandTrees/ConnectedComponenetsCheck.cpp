#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

// CODE FOR COUNTING THE NUMBER OF CONNECTED COMPONENTS IN A GRAPH

void dfs(int u){
    visited[u]=true;
    cout<<"Visiting Node: "<<u<<endl;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    int n=19; // 0-17 nodes
    adj.resize(19);
    visited.assign(n,false);
    adj[0]={4,8,14,13};
    adj[1]={5};
    adj[2]={9,15};
    adj[3]={9};
    adj[4]={0,8};
    adj[5]={1,17,16};
    adj[6]={7,11};
    adj[7]={11,6};
    adj[8]={4,0};
    adj[9]={3,15,2};
    adj[10]={15};
    adj[11]={6,7};
    adj[12]={};
    adj[13]={0,14};
    adj[14]={13,0,8};
    adj[15]={9,2,10};
    adj[16]={5};
    adj[17]={5};
    adj[18]={};
    int countComponenets=0;
    vector<int> componentsId(n);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            countComponenets++;
            dfs(i);
        }
    }
    cout<<countComponenets<<endl;
}
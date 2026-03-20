#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int orangesRotting(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){ // if rotten?
                    q.push({{i,j},0});
                    vis[i][j]=2; // means rotten and visited
                }
                else{
                    vis[i][j]=0; // not visited yet
                }
            }
        }
        int tm=0; // time
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();

            for(int i=0;i<4;i++){
                int tempr=r+drow[i];
                int tempc=c+dcol[i];
                if(tempr>=0 && tempr<n && tempc>=0 && tempr<n && vis[tempr][tempc]!=2 && grid[tempr][tempc]==1){
                    q.push({{tempr,tempc},t+1});
                    vis[tempr][tempc]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }

};

int main(){
    
}
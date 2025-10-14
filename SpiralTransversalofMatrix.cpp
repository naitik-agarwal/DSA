#include<bits/stdc++.h>
using namespace std;

void PrintinSpiralOrder(vector<vector<int>> &grid){
    int m=grid.size(); // rows
    int n=grid[0].size(); // columns
    int lasttoprow=-1;
    int lastleftcol=-1;
    int lastrightcol=n;
    int lastbottomrow=m;
    int count=0;
    int i=0,j=0;
    while(count!=m*n){
        // Go right
        while(j<lastrightcol){
            cout<<grid[i][j]<<" ";
            j++;
            count++;
        }
        lasttoprow=i;
        j--;
        i++;
        if(count==m*n){break;}
        // Go bottom
        while(i<lastbottomrow){
            cout<<grid[i][j]<<" ";
            i++;
            count++;
        }
        lastrightcol=j;
        i--;
        j--;
        if(count==n*m){break;}
        //go left
        while(j>lastleftcol){
            cout<<grid[i][j]<<" ";
            j--;
            count++;
        }
        lastbottomrow=i;
        j++;
        i--;
        if(count==m*n){break;}
        //go up
        while(i>lasttoprow){
            cout<<grid[i][j]<<" ";
            i--;
            count++;
        }
        i++;
        lastleftcol=j;
        j++;
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m);
    for(int i=0;i<m;i++){
        grid[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    PrintinSpiralOrder(grid);
    return 0;
}
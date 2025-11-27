#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> PascalTraingle(int n){
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        ans[i].resize(i+1);
        ans[i][0]=1;
        ans[i][i]=1;
        if(i>1){
            for(int j=1;j<=i/2;j++){
                int tem=ans[i-1][j-1]+ans[i-1][j];
                ans[i][j]=tem;
                ans[i][i-j]=tem;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> pas=PascalTraingle(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<pas[i].size();j++){
            cout<<pas[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
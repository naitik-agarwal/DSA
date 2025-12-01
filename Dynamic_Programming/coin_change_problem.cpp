#include<bits/stdc++.h>
using namespace std;

// coin change problem

int fun(int sum,vector<int> &a,int m){
    if(sum==0){
        return 1;
    }
    if(m==0){
        return 0;
    }
    if(a[m-1]<=sum){
        return fun(sum-a[m-1],a,m)+fun(sum,a,m-1);
    }
    else{
        return fun(sum,a,m-1);
    }
}
int f(int sum,vector<int> &a,int m){
    vector<vector<int>> dp(m+1,vector<int>(sum+1));
    for(int i=0;i<sum+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<m+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i][j-a[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[m][sum];
}

int main(){
    int sum,m;
    cin>>sum>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    int ans=f(sum,a,m);
    cout<<ans<<endl;
    return 0;
}
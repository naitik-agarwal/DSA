#include<bits/stdc++.h>
using namespace std;
// Subset Sum Problem
int func(vector<int> &a,int n,int sum){
    if(sum==0){
        return 1; // yes
    }
    if(n==0){
        return 0; // no
    }
    if(a[n-1]<=sum){
        return max(func(a,n-1,sum-a[n-1]),func(a,n-1,sum));
    }
    else{
        return func(a,n-1,sum);
    }
}
// Lets memoise this
int dp[101][100001];
int fun(vector<int> &a,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(a[n-1]<=sum){
        return dp[n][sum]=max(fun(a,n-1,sum-a[n-1]),fun(a,n-1,sum));
    }
    else{
        return dp[n][sum]=fun(a,n-1,sum);
    }
}
// Lets now try to write top-down approach
int f(vector<int> &a,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }
        }
    }
    // We need to calculate dp[n][sum]
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=max(dp[i-1][j-a[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,sum;
    cin>>n>>sum;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=f(a,n,sum);
    cout<<ans<<endl;
    return 0;
}
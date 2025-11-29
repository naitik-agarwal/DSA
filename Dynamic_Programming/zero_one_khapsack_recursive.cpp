#include<bits/stdc++.h>
using namespace std;

// Firstly only recursive
int knapsack_recursive(vector<int> &wt,vector<int> &cost,int W,int n){
    if(W==0 || n==0){
        return 0;
    }
    if(wt[n-1]<=W){
        return max(cost[n-1]+knapsack_recursive(wt,cost,W-wt[n-1],n-1),knapsack_recursive(wt,cost,W,n-1));
    }
    else{
        return knapsack_recursive(wt,cost,W,n-1);
    }
}
// Using memoization
int dp[101][1001];

int knapsack_memoization(vector<int> &wt,vector<int> &cost,int W,int n){
    if(W==0 || n==0){
        return 0;
    }
    if(dp[W][n]!=-1){
        return dp[W][n];
    }
    if(wt[n-1]<=W){
        return dp[W][n]=max(cost[n-1]+knapsack_memoization(wt,cost,W-wt[n-1],n-1),knapsack_memoization(wt,cost,W,n-1));
    }
    else{
        return dp[W][n]=knapsack_memoization(wt,cost,W,n-1);
    }
}

// Top down approach  -> NO recursive calls

int knapsack_Top_Down(vector<int> &wt,vector<int> &cost,int W,int n){
    int dp[n+1][W+1];
    // Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    // n->i & W->j
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(cost[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}


int main(){
    memset(dp,-1,sizeof(dp));  // Always initialise this inside a function
    int W,n;
    cin>>W>>n;
    vector<int> wt(n),cost(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    int ans=knapsack_Top_Down(wt,cost,W,n);
    cout<<ans<<endl;
    return 0;
}
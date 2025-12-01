#include<bits/stdc++.h>
using namespace std;

// Rod cutting problem : unbounded knapsack
// first write the recursive code:
int func(vector<int> &price,int n,int len){
    if(n==0 || len<=0){
        return 0;
    }
    if(n<=len){
        return max(price[n-1]+func(price,n,len-n),func(price,n-1,len));
    }
    else{
        return func(price,n-1,len);
    }
}
// Lets code top-down approach now
int f(vector<int> &price,int n,int len){
    vector<vector<int>> dp(n+1,vector<int>(len+1));
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<len+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<len+1;j++){
            if(i<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}


int main(){
    int n;
    cin>>n;
    int ans=0;
    vector<int> price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int len=n;
    ans=f(price,n,len);
    cout<<ans<<endl;
    return 0;
}
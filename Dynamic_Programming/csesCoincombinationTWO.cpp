#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

ll fn(vector<int> &c,int n,int x){
    vector<vector<ll>> dp(n+1,vector<ll>(x+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<x+1;j++){
            if(j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<x+1;j++){
            if(j>=c[i-1]){
                dp[i][j]=(dp[i][j-c[i-1]]%MOD+dp[i-1][j]%MOD)%MOD;
            }
            else{
                dp[i][j]=dp[i-1][j]%MOD;
            }
        }
    }
    return dp[n][x]%MOD;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    ll ans=fn(c,n,x);
    cout<<ans%MOD<<endl;
    return 0;
}
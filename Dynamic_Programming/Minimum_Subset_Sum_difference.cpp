#include<bits/stdc++.h>
using namespace std;

vector<bool> S_S(vector<int> &a,int target,int n){
    vector<vector<bool>> dp(n+1,vector<bool>(target+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(a[i-1]<=j){
                dp[i][j]=(dp[i-1][j-a[i-1]]||dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n];
} 
int func(vector<int> &a,int n,int sum){ // Main function (ans)
    if(n==0){
        return 0;
    }
    int ans=INT_MAX;
    vector<bool> reqV=S_S(a,sum,n);
    for(int i=1;i<=sum/2;i++){
        if(reqV[i]==true){
            ans=min(ans,abs(sum-2*i));
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int ans=func(a,n,sum);
    cout<<ans<<endl;
    return 0;
}
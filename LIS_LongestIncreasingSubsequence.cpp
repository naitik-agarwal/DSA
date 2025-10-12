#include<bits/stdc++.h>
using namespace std;
// This only calculates the length of the longest increasing subsequence
// Give a good try, try to understand the core concept behind these algos and understand them crystal clear
int lis(int ind,int prev_ind,vector<vector<int>> &dp,int n,vector<int> &a){ // O(n^2)
    if(ind==n){
        return 0;
    }
    else{
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        else{
            int nottake=0+lis(ind+1,prev_ind,dp,n,a);
            int take=0;
            if(prev_ind==-1 || a[ind]>a[prev_ind]){
                take=1+lis(ind+1,ind,dp,n,a);
            }
            dp[ind][prev_ind+1]=max(take,nottake);
            return dp[ind][prev_ind+1];
        }
    }
}
int LIS(vector<int> &a){ // Optimized approach O(nlog(n))
    vector<int> sub;
    if(a.empty()){
        return 0;
    }
    sub.push_back(a[0]);
    for(int i=1;i<a.size();i++){
        if(a[i]>sub.back()){
            sub.push_back(a[i]);
        }
        else{
            auto it=lower_bound(sub.begin(),sub.end(),a[i]);
            *it=a[i];
        }
    }
    return sub.size();
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++){
        dp[i].resize(n+1);
        for(int j=0;j<n+1;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b=a;
    int anss=LIS(b);
    int ans=lis(0,-1,dp,n,a);
    cout<<ans<<endl;
    cout<<anss<<endl;
    cout<<endl;
    return 0;
}
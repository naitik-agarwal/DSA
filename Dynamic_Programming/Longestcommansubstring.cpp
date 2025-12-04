#include<bits/stdc++.h>
using namespace std;
// Longest comman substring
int func(string s1,string s2,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    // here dp[i][j] means length of the longest comman substring that ends at s1[i] or s2[j];
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int ans=func(s1,s2,s1.size(),s2.size());
    cout<<ans<<endl;
    return 0;
}
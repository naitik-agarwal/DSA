#include<bits/stdc++.h>
using namespace std;

// LCS -> longest comman subsequence recursive code
int LCS_recursive(string x,string y,int n,int m){
    // n-> size of x (we will check from last)
    // same as m
    // Base case :
    if(n==0 || m==0){
        return 0;
    }
    // main code:
    if(x[n-1]==y[m-1]){
        return 1+LCS_recursive(x,y,n-1,m-1);
    }
    else{
        return max(LCS_recursive(x,y,n,m-1),LCS_recursive(x,y,n-1,m));
    }
}

// using memoization or top-down
int dp[1001][1001];
int LCS_Memoised(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    // dp[n][m] -> ans when size of strings are n & m
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(x[n-1]==y[m-1]){
        return dp[n][m]=1+LCS_Memoised(x,y,n-1,m-1);
    }
    else{
        return dp[n][m]=max(LCS_Memoised(x,y,n-1,m),LCS_Memoised(x,y,n,m-1));
    }
}
// bottom-up approach
int LCS_top_down(string x,string y,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
// Printing longest comman subsequence
// first write the normal code for length of lcs
string printLCS(string x,string y,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans;
    int i=n,j=m;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
            i--;j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    string ans=printLCS(x,y,n,m);
    cout<<ans<<endl;
    return 0;   
}
#include<bits/stdc++.h>
using namespace std;

// agbcba
// abcbga

// abcba
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
    while(i!=0 && j!=0){
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
// Longest Palindromic Subsequence -> take LCS of s and reverse of s,
string func(string s,int n){
    if(n==0){
        return "";
    }
    else{
        string tem=s;
        reverse(s.begin(),s.end());
        string ans=printLCS(tem,s,n,n);
        return ans;
    }
}

int main(){
    string s;
    cin>>s;
    string ans=func(s,s.size());
    cout<<ans<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

// shortest comman supersequence 

string printLCA(string x,string y,int n,int m){
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
// AGGTAB 
// GXTXAYB 
// GTAB
// AGGXTXAYB 
string func(string x,string y,int n,int m){
    if(n==0 || m==0){
        return x+y;
    }
    else{
        string ans;
        string temp=printLCA(x,y,n,m);
        int i=n,j=m,k=temp.size();
        while(i>0 && j>0 && k>0){
            if(x[i-1]==y[j-1] && x[i-1]==temp[k-1]){
                ans.push_back(x[i-1]);
                i--;j--;k--;
            }
            else if(x[i-1]==temp[k-1]){
                ans.push_back(y[j-1]);
                j--;
            }
            else if(y[j-1]==temp[k-1]){
                ans.push_back(x[i-1]);
                i--;
            }
            else{
                ans.push_back(x[i-1]);
                ans.push_back(y[j-1]);
                i--;
                j--;
            }
        }
        while(i>0){
            ans.push_back(x[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(y[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
}

int main(){
    string x,y;
    cin>>x>>y;
    string ans=func(x,y,x.size(),y.size());
    cout<<ans<<endl;
    return 0;
}


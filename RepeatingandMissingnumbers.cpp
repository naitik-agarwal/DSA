#include<bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> &a,int n){
    int sum=0;
    int sumsqr=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        sumsqr+=(a[i]*a[i]);
    }
    int alpha=(n*(n+1))/2-sum;
    int gama=(n*(n+1)*(2*n+1))/6-sumsqr;
    int B=((gama/alpha)+alpha)/2;
    int A=((gama/alpha)-alpha)/2;
    vector<int> ans={A,B};
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> res=func(a,n);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
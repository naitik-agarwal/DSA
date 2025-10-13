#include<bits/stdc++.h>
using namespace std;

vector<int> kadane(vector<int> &a){
    int sum=a[0];
    int maxsum=a[0];
    int l=0,r=0,letl=0,letr=0;
    for(int i=1;i<a.size();i++){
        if(a[i]>a[i]+sum){
            letl=i;
        }
        sum=max(a[i]+sum,a[i]); // Means we should start a subarray from a[i] right.......
        if(sum>maxsum){
            l=letl;
            r=i;
        }
        maxsum=max(maxsum,sum);
    }
    vector<int> ans;
    for(int i=l;i<=r;i++){
        ans.push_back(a[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans=kadane(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
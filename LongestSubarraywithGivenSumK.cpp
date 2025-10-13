#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &a,int k){
    map<int,int> b;
    b[0]=-1;
    int prefixsum=0;
    int ans=-1;
    for(int i=0;i<a.size();i++){
        prefixsum+=a[i];
        if(b.count(prefixsum-k)){
            ans=max(ans,i-b[prefixsum-k]);
        }
        if(!b.count(prefixsum)){
            b[prefixsum]=i;
        }
    }
    return ans;
}
// Using the two pointer approach
int func2(vector<int> &a,int k){
    int l=0,r=0;
    int sum=0;
    int ans=-1;
    for(r=0;r<a.size();r++){
        sum+=a[r];
        while(sum>k){
            sum-=a[l];
            l++;
        }
        if(sum==k){
            ans=max(ans,r-l+1);
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=func2(a,k);
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// If it contain positives only
int func(int *a,int n,int k){
    int sum=0;
    int cnt=0;
    int l=0,r=0;
    while(r<n){
        sum+=a[r++];
        while(sum>k && l<=r){
            sum-=a[l];
            l++;
        }
        if(sum==k){
            cnt++;
            sum-=a[l];
            l++;
        }
    }
    return cnt;
}
// if there exist non-negatives also
int fun(int *a,int n,int k){
    map<int,int> helper;
    int ans=0;
    helper[0]=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        int diff=sum-k;
        ans+=helper[diff];
        helper[sum]++;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=fun(a,n,k);
    cout<<ans<<endl;
    return 0;
}
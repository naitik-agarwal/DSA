#include<bits/stdc++.h>
using namespace std;

int maxprosub(vector<int> &a){
    int maxprod=a[0];
    int ans=a[0];
    for(int i=1;i<a.size();i++){
        maxprod=max(a[i],maxprod*a[i]);
        ans=max(ans,maxprod);
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
    int ans=maxprosub(a);
    cout<<ans<<endl;
    return 0;
}
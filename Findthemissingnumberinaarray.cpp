#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> a(n-1);
    vector<int> b(n);
    int ans=0;
    for(int i=0;i<n;i++){
        b[i]=i+1;
        ans=(ans^b[i]);
    }
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        ans=(ans^a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
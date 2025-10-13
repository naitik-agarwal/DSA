#include<bits/stdc++.h>
using namespace std;

int SBS(vector<int> &a){
    vector<int> max_afterthis(a.size());
    int num=a.back();
    max_afterthis[a.size()-1]=num;
    for(int i=a.size()-2;i>=0;i--){
        num=max(num,a[i]);
        max_afterthis[i]=num;
    }
    int ans=-1;
    for(int i=0;i<a.size();i++){
        ans=max(ans,max_afterthis[i]-a[i]);
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
    int profit=SBS(a);
    cout<<profit<<endl;
    return 0;
}
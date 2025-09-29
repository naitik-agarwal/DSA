#include<bits/stdc++.h>
using namespace std;

void movezerosatend(vector<int> &a){
    vector<int> b;
    int zerocount=count(a.begin(),a.end(),0);
    for(int i=0;i<a.size();i++){
        if(a[i]!=0){b.push_back(a[i]);}
        else{
            continue;
        }
    }
    for(int i=1;i<=zerocount;i++){
        b.push_back(0);
    }
    a=b;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    movezerosatend(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
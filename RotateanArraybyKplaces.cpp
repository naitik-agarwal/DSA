#include<bits/stdc++.h>
using namespace std;

void leftrotate(vector<int> &a,int k){
    vector<int> b(a.size());
    for(int i=0;i<a.size();i++){
        int num=a[i];
        b[(i+(a.size()-k))%a.size()]=num;
    }
    a=b;
}

void rightrotate(vector<int> &a,int k){
    vector<int> b(a.size());
    for(int i=0;i<a.size();i++){
        int num=a[i];
        b[(i+k)%a.size()]=num;
    }
    a=b;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b=a;
    leftrotate(a,k);
    rightrotate(b,k);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
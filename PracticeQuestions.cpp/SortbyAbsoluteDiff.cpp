#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &a,int x){
    for(int i=0;i<a.size()-1;i++){
        int num=abs(x-a[i]);
        int r=i;
        for(int j=i+1;j<a.size();j++){
            if(abs(a[j]-x)<num){
                r=j;
                num=abs(a[j]-x);
            }
        }
        swap(a[i],a[r]);
    }
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    func(a,x);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
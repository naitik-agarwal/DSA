#include<bits/stdc++.h>
using namespace std;

int binser(vector<int> &a,int x){
    int n=a.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int idx=binser(a,x);
    cout<<idx<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &a,int target,int n){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==target){
            return mid+1; //found
        }
        else if(a[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cin>>target;
    int target_index=binary_search(a,target,n);
    cout<<target_index<<endl;
    return 0;
}
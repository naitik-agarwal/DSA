#include<bits/stdc++.h>
using namespace std;

void recursiveBubble_sort(vector<int> &a,int low,int high){
    if(low>=high){
        return;
    }
    for(int i=low;i<high;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    recursiveBubble_sort(a,low,high-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    recursiveBubble_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void recursiveInsertion_sort(vector<int> &a,int high){
    if(high==a.size()){
        return;
    }
    if(high==0){
        recursiveInsertion_sort(a,high+1);
        return;
    }
    int j=high,i=high-1;
    while(i>=0 && j>=0 && a[i]>a[j]){
        swap(a[i],a[j]);
        j=i;
        i--;
    }
    recursiveInsertion_sort(a,high+1);
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    recursiveInsertion_sort(a,0);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
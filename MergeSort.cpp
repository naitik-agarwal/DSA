#include<bits/stdc++.h>
using namespace std;

void mergeRanges(vector<int> &a,int low,int mid,int high){
    vector<int> temp;
    temp.reserve(high-low+1);
    int i=low;
    int j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(a[i++]);
    }
    while(j<=high){
        temp.push_back(a[j++]);
    }
    for(int k=0;k<temp.size();k++){
        a[low+k]=temp[k];
    }
}

void MergeSort(vector<int> &a,int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);
    mergeRanges(a,low,mid,high);
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
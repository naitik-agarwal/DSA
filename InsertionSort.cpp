#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &a){
    int size=1;
    while(size<a.size()){
        int r=size;
        for(int j=r-1;j>=0;j--){
            if(a[r]<a[j]){
                swap(a[r],a[j]);
                r=j;
            }
        }
        size++;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    InsertionSort(a);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
    return 0;
}
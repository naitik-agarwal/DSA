#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &a){  // thats pass by reference
    for(int i=0;i<a.size()-1;i++){
        int r=i;
        for(int j=i+1;j<a.size();j++){
            if(a[j]<a[r]){
                r=j;
            }
        }
        swap(a[i],a[r]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
    SelectionSort(a);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
}
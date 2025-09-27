#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &a){
    int flag=0;
    int t=0;
    while(flag==0){
        int swp=0;
        for(int i=0;i<a.size()-1-t;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                swp++;
            }
        }
        t++;
        if(swp==0){
            flag=1;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    BubbleSort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
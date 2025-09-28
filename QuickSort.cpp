#include<bits/stdc++.h>
using namespace std; // Have patience

void quickSort(vector<int> &a,int low,int high){
    if(low>=high){
        return;
    }
    int pivot=a[(low+high)/2];
    int i=low,j=high;
    while(i<=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(low<j){ // because correct recursion ranges are Left half: [low...j]
        quickSort(a,low,j);
    }
    if(i<high){   // Right half : [i....high]
        quickSort(a,i,high);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<int> APAN(vector<int> &a){
    if(a.size()==0){
        return a;
    }
    int l=1;
    int n=a.size();
    int r=n-1;
    while(l<=r){
        if(a[l-1]>0 && a[l]<0 || a[l-1]<0 && a[l]>0){
            l++;
        }
        else{
            if(a[l-1]>0){
                while(r>l && a[r]>0){
                    r--;
                }
                swap(a[l],a[r]);
                l++;
            }
            else{
                while(r>l && a[r]<0){
                    r--;
                }
                swap(a[l],a[r]);
                l++;
            }
        }
    }
    return a;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    a=APAN(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
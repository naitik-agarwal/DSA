#include<bits/stdc++.h>
using namespace std;

// Brute Force approach
int countinv(vector<int> &a){
    int n=a.size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                ans++;
            }
        }
    }
    return ans;
}

// Better approach
int cntinv(vector<int> &a){
    int n=a.size();
    int ans=0;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res=cntinv(a);
    cout<<res<<endl;
    return 0;
}
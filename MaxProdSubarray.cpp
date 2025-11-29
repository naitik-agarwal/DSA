#include<bits/stdc++.h>
using namespace std;
#define int long long

int mp(vector<int> &a){
    int n=a.size();
    int noofneg=0;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            noofneg++;
        }
    }
    if(noofneg%2==0){
        int ans=1;
        for(int i=0;i<n;i++){
            ans*=a[i];
        }
        return ans;
    }
    else{
        int firstneg=0;
        int lastneg=n-1;
        while(a[firstneg]>0){
            firstneg++;
        }
        while(a[lastneg]>0){
            lastneg--;
        }
        int ans1=1,ans2=1;
        for(int i=firstneg+1;i<n;i++){
            ans1*=a[i];
        }
        for(int i=0;i<lastneg;i++){
            ans2*=a[i];
        }
        return max(ans1,ans2);
    }
}

int maxprodsubarrprod(vector<int> &a){
    int n=a.size();
    if(count(a.begin(),a.end(),0)==0){
        return mp(a);
    }
    else{
        int ans=LONG_LONG_MIN;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                continue;
            }
            int l=i;
            while(i<n && a[i]!=0){
                i++;
            }
            vector<int> temp;
            for(int j=l;j<i;j++){
                temp.push_back(a[j]);
            }
            ans=max(ans,mp(temp));   
        }
        return ans;
    }
}

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=maxprodsubarrprod(a);
    cout<<ans<<endl;
    return 0;
}
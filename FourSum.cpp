#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fun(vector<int> &arr,int n,int target){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> seen;
            for(int k=j+1;k<n;k++){
                long long required = (long long)target-arr[i]-arr[j]-arr[k];
                if(seen.count(required)){
                    vector<int> temp={arr[i],arr[j],arr[k],(int)required};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                else{
                    seen.insert(arr[k]);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cin>>target;
    vector<vector<int>> res=fun(a,n,target);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
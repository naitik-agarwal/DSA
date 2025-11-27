#include<bits/stdc++.h>
using namespace std;

// brute force method:
vector<vector<int>> threesum(vector<int> &arr,int n){
    set<vector<int>> st;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> tem={arr[i],arr[j],arr[k]};
                    sort(tem.begin(),tem.end());
                    st.insert(tem);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// Better approach:
vector<vector<int>> three_b_sum(vector<int> &arr,int n){
    set<vector<int>> st;

    map<int,int> checker;
    for(int i=0;i<n;i++){
        checker[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int tsum=arr[i]+arr[j];
            int neg=(-1)*tsum;
            checker[arr[i]]--;
            checker[arr[j]]--;
            if(checker[neg]>0){
                vector<int> tem = {arr[i],arr[j], neg};
                sort(tem.begin(), tem.end());
                st.insert(tem);
            }
            checker[arr[i]]++;
            checker[arr[j]]++;
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// Best approach:
vector<vector<int>> ThrEE__B_Summ(vector<int> &a,int n){
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]){
            continue;
        }
        int l=i+1;
        int r=n-1;
        while(l<r){
            int sum=a[l]+a[r]+a[i];
            if(sum==0){
                ans.push_back({a[l],a[r],a[i]});
                l++;
                r--;
                while(l<r && a[l]==a[l-1]){l++;}
                while(l<r && a[r]==a[r+1]){r--;}
            }
            else if(sum<0){
                l++;
            }
            else{
                r--;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> res=ThrEE__B_Summ(a,n);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<3;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
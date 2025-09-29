#include<bits/stdc++.h>
using namespace std;

vector<int> unioon(vector<int> &a,vector<int> &b){
    vector<int> c;
    int l=0;
    int r=0;
    while(l<a.size() && r<b.size()){
        if(a[l]<=b[r]){c.push_back(a[l]);l++;}
        else{c.push_back(b[r]);r++;}
    }
    while(l<a.size()){c.push_back(a[l]);l++;}
    while(r<b.size()){c.push_back(b[r]);r++;}
    return c;
}
void remove_duplicates(vector<int> &a){
    vector<int> b;
    for(int i=0;i<a.size();i++){
        int num=a[i];
        b.push_back(a[i]);
        while(i<a.size() && a[i]==num){
            i++;
        }
        i--;
    }
    a=b;
}
vector<int> union2(vector<int> &a,vector<int> &b){
    set<int> ans;
    for(int i=0;i<a.size();i++){
        ans.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){
        ans.insert(b[i]);
    }
    vector<int> an;
    for(auto &it:ans){
        an.push_back(it);
    }
    return an;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> c=union2(a,b);
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    return 0;
}
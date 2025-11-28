#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    // Assuming a is sorted
    auto lb=lower_bound(a.begin(),a.end(),x); // lb points to i first element >= x
    auto ub=upper_bound(a.begin(),a.end(),x); // up points to first element > x
    cout<<"lb = "<<distance(a.begin(),lb)<<endl; // distance(it1,it2)= index(it2)-index(it1)
    cout<<"ub = "<<distance(a.begin(),ub)<<endl;
    return 0;
}
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,unroll-loops")

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

vector<int> SieveofEratosthenes(int n){
    vector<int> hash(n+1,1);
    hash[0]=0;
    hash[1]=0;
    for(int i=2;i*i<=n;i++){
        int j=i;
        if(hash[i]==1){
            while(i*j<=n){
                hash[i*j]=0;
                j++;
            }
        }
        else{
            continue;
        }
    }
    vector<int> sol;
    for(int i=0;i<hash.size();i++){
        if(hash[i]==1){
            sol.push_back(i);
        }
    }
    return sol;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> primes=SieveofEratosthenes(n);
    for(int i=0;i<primes.size();i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl;

    return 0;
}
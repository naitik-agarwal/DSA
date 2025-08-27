#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,unroll-loops")

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

// First we would get prime factorization using sieve:
// so lets get the SPF of each number upto n

vector<int> spf;

void sieve(int n){
    spf.assign(n+1,0);
    for(int i=0;i<spf.size();i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){ // means i is prime
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}
vector<int> primefactorization(int n){
    vector<int> fact;
    while(n!=1){
        fact.push_back(spf[n]);
        n/=spf[n];
    }
    return fact;
}
vector<pair<int,int>> primefac(int n){
    vector<int> divs=primefactorization(n);
    vector<pair<int,int>> nums;
    for(int i=0;i<divs.size();i++){
        int current=divs[i];
        int cnt=0;
        while(i<divs.size() && divs[i]==current){
            cnt++;
            i++;
        }
        i--;
        nums.push_back({current,cnt});
    }
    return nums;
}

int EulerTotient(int n){
    int num=n;
    vector<pair<int,int>> primef=primefac(n);
    for(int i=0;i<primef.size();i++){
        int p=primef[i].first;
        num=num/p*(p-1);
    }
    return num;
}

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // used to determine the number of int btw 1 and n that are coprime with n
    int t;
    cin>>t;
    sieve(1000001);
    vector<int> answers(t);
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        cout<<EulerTotient(n)<<endl;
    }
    return 0;
}
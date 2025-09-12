#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b,c;
    cin>>a>>b>>c;
    // To compare multiple values we can do :
    cout<<"Min of these values: "<<min({a,b,c})<<endl;
    cout<<"Max of these values: "<<max({a,b,c})<<endl;
    return 0;   
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;


int main(){
   long long int n,k,x,a,b,c;
   cin>>n>>k>>x>>a>>b>>c;
   // x(i)=(x(i-1)*a+b)%c
   long long int sum=x;
   long long int currentlen=1;
   long long int prev=x;
   long long int ans=0;
   a=a%c;
   b=b%c;
   vector<long long int> nums;
   nums.push_back(prev);
   while(currentlen<k){
      long long int next=((prev*a)%c+b)%c;
      nums.push_back(next);
      sum+=next;
      currentlen++;
      prev=next;
   }
   // cout<<sum<<" ";
   ans=(ans^sum);
   long long int totaliterleft=n-k;
   long long int left=0;
   while(totaliterleft--){
      sum-=nums[left];
      long long int next=((prev*a)%c+b)%c;
      nums.push_back(next);
      sum+=next;
      //totaliterleft--;
      ans=(ans^sum);
      prev=next;
      left++;
      // cout<<sum<<" ";
   }
   // for(int i=0;i<nums.size();i++){
   //    cout<<nums[i]<<" ";
   // }
   // cout<<endl;
  // ans=(ans^sum);
   cout<<ans<<endl;
}
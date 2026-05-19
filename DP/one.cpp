#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int x) {
  if (x == 0 || x == 1) {
    return x;
  } else {
    return Fibonacci(x - 1) + Fibonacci(x - 2);
  }
}

int fibDP(int n, vector<int> &dp) {
  if (n == 0 || n == 1) {  // BASE CASE
    return n;
  }
  if (dp[n] != -1) {
    return dp[n];
  }
  dp[n] = fibDP(n - 1, dp) + fibDP(n - 2, dp);
  return dp[n];
}

int fibTab(int n) {
  vector<int> fib(n + 1, 0);
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib[n];
}

int ClimbingStairs(int n, vector<int> &dp) {
  if (n == 1 || n == 2) {
    return n;
  }
  if (dp[n] != -1) {
    return dp[n];
  }
  dp[n] = ClimbingStairs(n - 1, dp) + ClimbingStairs(n - 2, dp);
  return dp[n];
}

int ClimbingStairsVariation(int n) {
  // person can take 1,2,3 jumps
  if (n == 1 || n == 2) {
    return n;
  }
  vector<int> dp(n + 1, -1);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
  return dp[n];
}

int main() {
  int n = 6;
  vector<int> f(n + 1, -1);
  cout << fibDP(n, f) << endl;
  cout << fibTab(n) << endl;
}
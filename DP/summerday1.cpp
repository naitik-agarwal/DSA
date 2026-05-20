#include <bits/stdc++.h>
using namespace std;

int ClimbingStairs(int n) {
  if (n < 1) {
    return 0;
  } else if (n == 1 || n == 2) {
    return n;
  } else {
    return ClimbingStairs(n - 1) + ClimbingStairs(n - 2);
  }
}

// memoized version:
int climbingStairsMemoized(int n, vector<int> &dp) {
  if (n < 1) {
    return 0;
  } else if (n == 1 || n == 2) {
    return n;
  } else if (dp[n] != 0) {
    return dp[n];
  } else {
    dp[n] =
        climbingStairsMemoized(n - 1, dp) + climbingStairsMemoized(n - 2, dp);
    return dp[n];
  }
}

// Tabular version:
int ClimbingStairsTabular(int n) {
  if (n == 2) {
    return 2;
  }
  vector<int> dp(n + 1);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int FrogJumpwithKDistances(vector<int> &heights, int k) {
  int n = heights.size();
  if (n == 1) {
    return 0;
  }
  vector<int> dp(
      n + 1);  // dp[i] means the minimum energy required to reach ith stair

  for (int i = 2; i <= n; i++) {
    // so we will calculate dp[i] first;
    int temp = INT_MAX;
    for (int j = 1; j <= k; j++) {
      if (i - j > 0) {
        temp = min(temp, dp[i - j] + abs(heights[i - 1] - heights[i - j - 1]));
      }
    }
    dp[i] = temp;
  }
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }
  int k;
  cin >> k;
  cout << FrogJumpwithKDistances(heights, k) << endl;
  return 0;
}
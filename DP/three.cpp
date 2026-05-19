#include <bits/stdc++.h>
using namespace std;

int FrogJump(vector<int> &heights, int n) {
  if (n == 1) {
    return 0;
  }
  vector<int> dp(n + 1);  // dp[i] = minimum enegry needed to reach ith stair
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = abs(heights[1] - heights[0]);
  for (int i = 3; i <= n; i++) {
    dp[i] = min(dp[i - 1] + abs(heights[i - 1] - heights[i - 2]),
                dp[i - 2] + abs(heights[i - 1] - heights[i - 3]));
  }
  return dp[n];
}

int FrogJumpwithKDistances(vector<int> &heights, int n, int k) {
  if (heights.empty() || n == 1) {
    return 0;
  }
  vector<int> dp(n + 1,
                 1e9);  // dp[i] = minimum energy needed to reach ith stair
  dp[1] = dp[0] = 0;
  for (int i = 2; i <= n; i++) {
    // we will find dp[i] first
    int temp = dp[i];
    int j = 1;
    while (j <= k && i - j > 0) {
      temp = min(temp, dp[i - j] + abs(heights[i - 1] - heights[i - j - 1]));
      j++;
    }
    dp[i] = temp;
  }
  return dp[n];
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }
  //   cout << FrogJump(heights, n) << endl;
  cout << FrogJumpwithKDistances(heights, n, k) << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Rod cutting problem

int RodCutting(vector<int> &price, vector<int> &length, int RLen, int n) {
  vector<vector<int>> dp(length.size() + 1, vector<int>(RLen + 1));
  // since everything already 0, therefore base case already covered
  for (int i = 1; i < length.size() + 1; i++) {
    for (int j = 1; j < RLen + 1; j++) {
      if (i <= j) {
        dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[length.size()][RLen];
}

int main() {}
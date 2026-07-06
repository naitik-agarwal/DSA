#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    if (m == 1 && n == 1) {
      return grid[0][0];
    }
    vector<vector<int>> dp(
        m + 1,
        vector<int>(n +
                    1));  // dp[i][j] => minimum path sum if we start from i,j
    dp[m][n] = grid[m - 1][n - 1];
    for (int i = m - 1; i >= 1; i--) {
      dp[i][n] += dp[i + 1][n] + grid[i - 1][n - 1];
    }
    for (int i = n - 1; i >= 1; i--) {
      dp[m][i] += dp[m][i + 1] + grid[m - 1][i - 1];
    }
    for (int i = m - 1; i >= 1; i--) {
      for (int j = n - 1; j >= 1; j--) {
        dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i - 1][j - 1];
      }
    }
    return dp[1][1];
  }
};

int main() {}
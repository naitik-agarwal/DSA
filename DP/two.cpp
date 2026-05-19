#include <bits/stdc++.h>
using namespace std;
// Topic: 0-1 knapsack

int knapsackRec(vector<int> &val, vector<int> &wt, int W,
                int n) {  // TC: O(2^n)
  if (n == 0 || W == 0) {
    return 0;
  }
  if (wt[n - 1] <= W) {
    return max(val[n - 1] + knapsackRec(val, wt, W - wt[n - 1], n - 1),
               knapsackRec(val, wt, W, n - 1));
  } else {
    return knapsackRec(val, wt, W, n - 1);
  }
}

int KnapsackMemo(vector<int> &val, vector<int> &wt, int W, int n,
                 vector<vector<int>> &dp) {
  if (n == 0 || W == 0) {
    return 0;
  }
  if (dp[n][W] != -1) {
    return dp[n][W];
  }
  if (wt[n - 1] <= W) {
    dp[n][W] = max(val[n - 1] + KnapsackMemo(val, wt, W - wt[n - 1], n - 1, dp),
                   KnapsackMemo(val, wt, W, n - 1, dp));
  } else {
    dp[n][W] = KnapsackMemo(val, wt, W, n - 1, dp);
  }
  return dp[n][W];
}

int KnapsackTab(vector<int> &val, vector<int> &wt, int W, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(W + 1));
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < W + 1; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
      if (wt[i - 1] <= j) {
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][W];
}

bool TargetSumSubset(vector<int> &nums, int targetSum, int n) {
  if (targetSum == 0) {
    return true;
  }
  if (n == 0) {
    return false;
  }
  if (nums[n - 1] <= targetSum) {
    return TargetSumSubset(nums, targetSum - nums[n - 1], n - 1) ||
           TargetSumSubset(nums, targetSum, n - 1);
  } else {
    return TargetSumSubset(nums, targetSum, n - 1);
  }
}

bool TargetSumSubsetMemoized(vector<int> &nums, int targetSum, int n,
                             vector<vector<int>> &dp) {
  if (targetSum == 0) {
    return true;
  }
  if (n == 0) {
    return false;
  }
  if (dp[n][targetSum] != -1) {
    return dp[n][targetSum];
  }
  if (nums[n - 1] <= targetSum) {
    dp[n][targetSum] =
        TargetSumSubsetMemoized(nums, targetSum - nums[n - 1], n - 1, dp) ||
        TargetSumSubsetMemoized(nums, targetSum, n - 1, dp);
  } else {
    dp[n][targetSum] = TargetSumSubsetMemoized(nums, targetSum, n - 1, dp);
  }
  return dp[n][targetSum];
}

bool TargetSumSubsetTabular(vector<int> &nums, int targetSum, int n) {
  vector<vector<bool>> dp(
      n + 1,
      vector<bool>(targetSum + 1));  // dp[i][j] -> means is it possible to make
                                     // a subset with sum j and with i elements
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < targetSum + 1; j++) {
      if (i == 0) {
        dp[i][j] = false;
      }
      if (j == 0) {
        dp[i][j] = true;
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < targetSum + 1; j++) {
      if (nums[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][targetSum];
}

// Unbounded Knapsack
int UnboundedKnapsack(vector<int> &val, vector<int> &wt, int W, int n) {
  if (n == 0 || W == 0) {
    return 0;
  }
  if (wt[n - 1] <= W) {
    return max(val[n - 1] + UnboundedKnapsack(val, wt, W - wt[n - 1], n),
               UnboundedKnapsack(val, wt, W, n - 1));
  } else {
    return UnboundedKnapsack(val, wt, W, n - 1);
  }
}

int KnapsackMemoUnbounded(vector<int> &val, vector<int> &wt, int W, int n,
                          vector<vector<int>> &dp) {
  if (n == 0 || W == 0) {
    return 0;
  }
  if (dp[n][W] != -1) {
    return dp[n][W];
  }
  if (wt[n - 1] <= W) {
    dp[n][W] =
        max(val[n - 1] + KnapsackMemoUnbounded(val, wt, W - wt[n - 1], n, dp),
            KnapsackMemoUnbounded(val, wt, W, n - 1, dp));
  } else {
    dp[n][W] = KnapsackMemoUnbounded(val, wt, W, n - 1, dp);
  }
  return dp[n][W];
}

int UnboundedKnapsackTab(vector<int> &val, vector<int> &wt, int W, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(W + 1));
  // dp[i][j] = max profit we can get with knapsack of size j and i coins
  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j < W + 1; j++) {
    dp[0][j] = 0;
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
      if (wt[i - 1] <= j) {
        dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][W];
}

int main() {
  vector<int> val = {15, 14, 10, 45, 30};
  vector<int> wt = {2, 5, 1, 3, 4};
  int W = 7;
  int n = 5;

  vector<vector<int>> dp(n + 1, vector<int>(W + 1, (-1)));
  int ans = knapsackRec(val, wt, W, n);
  int ansunbounded = KnapsackMemoUnbounded(val, wt, W, n, dp);
  //   int ans2 = KnapsackMemo(val, wt, W, n, dp);
  int ans3 = KnapsackTab(val, wt, W, n);
  cout << ans << endl;
  //   cout << ans2 << endl;
  cout << ans3 << endl;
  cout << ansunbounded << endl;
  cout << UnboundedKnapsackTab(val, wt, W, n) << endl;
  return 0;
}
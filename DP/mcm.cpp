#include <bits/stdc++.h>
using namespace std;

int mcmRec(vector<int> &arr, int i, int j) {
  if (i == j) {
    return 0;
  }
  int ans = INT_MAX;
  for (int k = i; k < j; k++) {
    int cost1 = mcmRec(arr, i, k);
    int cost2 = mcmRec(arr, k + 1, j);

    int curr_cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
    ans = min(ans, curr_cost);
  }
  return ans;
}

vector<vector<int>> dp(5, vector<int>(5, INT_MAX));
int mcmMemo(vector<int> &arr, int i, int j) {
  if (i == j) {
    dp[i][j] = 0;
    return dp[i][j];
  }
  if (dp[i][j] != INT_MAX) {
    return dp[i][j];
  }
  for (int k = i; k < j; k++) {
    int cost1 = mcmMemo(arr, i, k);
    int cost2 = mcmMemo(arr, k + 1, j);
    int currCost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
    dp[i][j] = min(dp[i][j], currCost);
  }
  return dp[i][j];
}

int mcmTab(vector<int> &arr, int i, int j) {
  if (i == j) {
    return 0;
  }
  vector<vector<int>> dp(i + 1, vector<int>(j + 1, INT_MAX));
  for (int i = 0; i <= min(i, j); i++) {
    dp[i][i] = 0;
  }
  for (int m = 1; m <= i; m++) {
    for (int n = 1; n <= j; n++) {
      for (int k = m; k < n; k++) {
        int cost1 = dp[m][k];
        int cost2 = dp[k + 1][n];
        int currCost = cost1 + cost2 + arr[m - 1] * arr[k] * arr[n];
        dp[m][n] = min(dp[m][n], currCost);
      }
    }
  }
  return dp[i][j];
}

int main() {
  vector<int> arr = {1, 3, 5, 4};
  int n = arr.size();
  cout << mcmRec(arr, 1, n - 1) << endl;
  cout << mcmMemo(arr, 1, n - 1) << endl;
  cout << mcmTab(arr, 1, n - 1) << endl;
  return 0;
}
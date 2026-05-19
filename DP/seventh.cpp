#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr) {
  int n = arr.size();
  vector<int> dp(n, 1);  // dp[i] -> length of lis ending in index i-1
  int ans = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }

  return ans;
}

int EditDistance(string &s1, string &s2, int p, int q) {
  // p-> s1.size()-1, q-> s2.size()-1
  if (p < 0) {
    return q + 1;
  } else if (q < 0) {
    return p + 1;
  }
  if (s1[p] == s2[q]) {
    return EditDistance(s1, s2, p - 1, q - 1);
  } else {
    return min(1 + EditDistance(s1, s2, p - 1, q),
               min(1 + EditDistance(s1, s2, p - 1, q - 1),
                   1 + EditDistance(s1, s2, p, q - 1)));
  }
}

// tabular
int EditDistanceTabular(string &s1, string &s2) {
  int n1 = s1.size(), n2 = s2.size();
  vector<vector<int>> dp(
      n1 + 1,
      vector<int>(n2 +
                  1));  // dp[i][j] -> minimum number of operations needed to
                        // convert first i char of s1 into first j char of s2

  // BASE CASE
  for (int i = 1; i <= n1; i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= n2; i++) {
    dp[0][i] = i;
  }

  // MAIN CASE
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
        continue;
      } else {
        dp[i][j] =
            min(1 + dp[i - 1][j], min(1 + dp[i - 1][j - 1], 1 + dp[i][j - 1]));
      }
    }
  }

  return dp[n1][n2];
}

int main() {
  vector<int> arr = {50, 3, 10, 7, 40, 80};
  cout << longestIncreasingSubsequence(arr) << endl;
  string s1 = "horse", s2 = "ros";
  cout << EditDistance(s1, s2, s1.size() - 1, s2.size() - 1) << endl;
  cout << EditDistanceTabular(s1, s2) << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// LCS -> longest common subsequence & longest common substring

// recursive
int LCS(string a, string b, int x, int y) {
  if (x == 0 || y == 0) {
    return 0;
  }
  if (a[x - 1] == b[y - 1]) {
    return 1 + LCS(a, b, x - 1, y - 1);
  } else {
    return max(LCS(a, b, x, y - 1), LCS(a, b, x - 1, y));
  }
}

// Tabular
int LCS_tab(string a, string b) {
  int x = a.size(), y = b.size();
  vector<vector<int>> dp(
      x + 1,
      vector<int>(y + 1));  // dp[i][j] - lcs of string a(len i), b(len j)

  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[x][y];
}

int LCSubstringTab(string a, string b) {
  int x = a.size(), y = b.size();
  vector<vector<int>> dp(x + 1, vector<int>(y + 1));
  // dp[i][j] -> max length of lcs ending at pos i of a and j of b

  int ans = 0;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      if (a[i - 1] != b[j - 1]) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      }
    }
  }

  return ans;
}

int main() {
  string a = "abcdge", b = "abedg";
  cout << LCS(a, b, a.size(), b.size()) << endl;
  cout << LCS_tab(a, b) << endl;
  cout << LCSubstring(a, b, a.size(), b.size()) << endl;
  cout << LCSubstringTab(a, b) << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// DP -> WEEK 5

bool WildCardMatching(string &text, string &pattern) {
  int n1 = text.size(), n2 = pattern.size();
  vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));

  // BASE CASE
  dp[0][0] = true;
  for (int i = 1; i <= n1; i++) {
    dp[i][0] = false;
  }
  int lastptr = -1;
  for (int i = 1; i <= n2; i++) {
    if (pattern[i - 1] == '*') {
      dp[0][i] = true;
    } else {
      lastptr = i;
      break;
    }
  }
  for (int i = lastptr; i <= n2 && i >= 1; i++) {
    dp[0][i] = false;
  }

  // TRANSITIONS
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (text[i - 1] == pattern[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (pattern[j - 1] == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (pattern[j - 1] == '*') {
        dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
      } else {
        dp[i][j] = false;
      }
    }
  }
  return dp[n1][n2];
}

int CatalanNumber(int n) {
  if (n < 2) {
    return 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (CatalanNumber(i) * CatalanNumber(n - i - 1));
  }
  return ans;
}

int CatalanNumberTab(int n) {
  vector<int> dp(n + 1);  // dp[i]-> catalan(i);
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] += (dp[j] * dp[i - j - 1]);
    }
  }
  return dp[n];
}

int countBST(int n) {}

int main() {
  string text = "baaabab", pattern = "a*ab";
  cout << WildCardMatching(text, pattern) << endl;
  cout << CatalanNumber(4) << endl;
  cout << CatalanNumberTab(3) << endl;
  return 0;
}
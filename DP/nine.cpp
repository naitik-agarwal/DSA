#include <bits/stdc++.h>
using namespace std;

// topic: LCA -> longest common subsequence, not just length

string LCS(string s1, string s2) {
  int n1 = s1.size(), n2 = s2.size();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  string ans;
  if (dp[n1][n2] == 0) {
    return ans;
  } else {
    int i = n1, j = n2;
    while (dp[i][j] != 0) {
      if (s1[i - 1] == s2[j - 1]) {
        // we found a match then it should be in ans
        ans.push_back(s1[i - 1]);
        i--;
        j--;
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          i--;
        } else {
          j--;
        }
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
}

int main() {
  string s1 = "bbbaaaba";
  string s2 = "bbababbb";
  cout << LCS(s1, s2) << endl;
  return 0;
}

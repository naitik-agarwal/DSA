#include<bits/stdc++.h>
using namespace std;

int subset_count(vector<int> &a, int target, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= target; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (a[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    int diff;
    cin >> diff;

    if ((sum + diff) % 2 != 0 || diff > sum) {
        cout << 0 << endl;
    } else {
        int req = (sum + diff) / 2;
        cout << subset_count(a, req, n) << endl;
    }

    return 0;
}
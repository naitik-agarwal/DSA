#include <bits/stdc++.h>
using namespace std;
// Brute force approach
int func(vector<int> &a, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == 0)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}
// Optimal approach
int funOpt(vector<int> &a, int n)
{
    // We will use hashmap for this
    int sum = 0;
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
        {
            ans = i + 1;
            continue;
        }
        else
        {
            // Check if this sum was seen before
            if (mp.find(sum) != mp.end())
            {
                ans = max(ans, i - mp[sum]);
                // we dont update value of mp[sum] now since we need the maximum ans
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = funOpt(a, n);
    cout << res << endl;
    return 0;
}
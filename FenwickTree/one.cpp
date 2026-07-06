#include <bits/stdc++.h>
using namespace std;

// Topic: Fenwick Tree
/*Theory:
Rightmost Set bit of x : (x & -x)
so to remove rightmost set bit of a num x : x-(x&-x)

*/

class Fenwick {
  vector<long long> bit;
  int n;

 public:
  Fenwick(int size) {
    n = size;
    bit.assign(n + 1, 0);  // 1 based indexing
  }
  void update(int idx, long long val) {  // idx is 1 based indexing
    while (idx <= n) {
      bit[idx] += val;
      idx += (idx & -idx);
    }
  }
  // Return the sum from 1 to idx
  long long query(int idx) {
    long long sum = 0;
    while (idx > 0) {
      sum += bit[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
  // Return sum from l to r
  long long query(int l, int r) { return query(r) - query(l - 1); }
};

int main() {
  vector<int> a = {0, 1, 2, 3, 4, 5};  // 1-based , 0 at start is dummy num
  Fenwick ft(5);
  for (int i = 1; i <= 5; i++) {
    ft.update(i, a[i]);
  }
  cout << ft.query(1, 3) << endl;
  cout << ft.query(1, 5) << endl;

  return 0;
}
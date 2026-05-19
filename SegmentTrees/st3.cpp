#include <bits/stdc++.h>
using namespace std;

#define int long long

class SegmentTree {
  vector<int> tree;
  int n;

  void BuildTree(vector<int> &arr, int start, int end, int node) {
    if (start == end) {
      tree[node] = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    BuildTree(arr, start, mid, 2 * node + 1);
    BuildTree(arr, mid + 1, end, 2 * node + 2);
    tree[node] = (tree[2 * node + 1] ^ tree[2 * node + 2]);
  }

  int rangeXor(int qi, int qj, int si, int sj, int node) {
    // case 1
    if (qi > sj || qj < si) {
      return 0;
    }
    // case 2
    else if (si >= qi && sj <= qj) {
      return tree[node];
    } else {
      int mid = si + (sj - si) / 2;
      return (rangeXor(qi, qj, si, mid, 2 * node + 1) ^
              rangeXor(qi, qj, mid + 1, sj, 2 * node + 2));
    }
  }
  void RangeMinUpdate(int idx, int val, int si, int sj, int node) {
    if (si == sj) {
      tree[node] = val;
      return;
    }
    int mid = si + (sj - si) / 2;
    if (idx <= mid) {
      RangeMinUpdate(idx, val, si, mid, 2 * node + 1);
    } else {
      RangeMinUpdate(idx, val, mid + 1, sj, 2 * node + 2);
    }
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
  }

 public:
  SegmentTree(vector<int> &arr) {
    n = arr.size();
    tree.resize(4 * n);
    BuildTree(arr, 0, n - 1, 0);
  }
  void printTree() {
    for (int i = 0; i < n; i++) {
      cout << tree[i] << " ";
    }
    cout << endl;
  }
  int rangeXorquery(int qi, int qj) { return rangeXor(qi, qj, 0, n - 1, 0); }
  void updateQuery(int idx, int val) { RangeMinUpdate(idx, val, 0, n - 1, 0); }
};

signed main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  SegmentTree st(x);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << st.rangeXorquery(a - 1, b - 1) << endl;
  }
  return 0;
}
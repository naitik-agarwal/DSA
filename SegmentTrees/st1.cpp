#include <bits/stdc++.h>
using namespace std;

#define int long long

class SegmentTree {
  vector<int> tree;  // 4*n
  int n;

  void buildTree(vector<int> &arr, int start, int end, int node) {  // TC = O(n)
    if (start == end) {
      tree[node] = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, start, mid, 2 * node + 1);
    buildTree(arr, mid + 1, end, 2 * node + 2);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }

  int rangeSum(int qi, int qj, int si, int sj, int node) {
    // case 1
    if (qi > sj || qj < si) {
      return 0;
    }
    // case 2
    if (si >= qi && sj <= qj) {
      return tree[node];
    }
    // case 3
    else {
      int mid = si + (sj - si) / 2;
      return rangeSum(qi, qj, si, mid, 2 * node + 1) +
             rangeSum(qi, qj, mid + 1, sj, 2 * node + 2);
    }
  }

  void rangeUpdate(int idx, int val, int start, int end, int node) {
    if (start == end) {
      tree[node] = val;
      return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) {
      rangeUpdate(idx, val, start, mid, 2 * node + 1);
    } else {
      rangeUpdate(idx, val, mid + 1, end, 2 * node + 2);
    }
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }

 public:
  SegmentTree(vector<int> &arr) {
    n = arr.size();
    tree.resize(4 * n);
    buildTree(arr, 0, n - 1, 0);
  }

  int rangeQuery(int qi, int qj) { return rangeSum(qi, qj, 0, n - 1, 0); }

  void updateQuery(int idx, int val) { rangeUpdate(idx, val, 0, n - 1, 0); }

  void printTree() {
    for (int i = 0; i < tree.size(); i++) {
      cout << tree[i] << " ";
    }
    cout << endl;
  }
};

signed main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  SegmentTree s(x);
  while (q--) {
    int f;
    cin >> f;
    if (f == 1) {
      int k, u;
      cin >> k >> u;
      s.updateQuery(k - 1, u);
    } else {
      int a, b;
      cin >> a >> b;
      cout << s.rangeQuery(a - 1, b - 1) << endl;
    }
  }
  return 0;
}
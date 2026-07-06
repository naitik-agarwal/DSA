#include <bits/stdc++.h>
using namespace std;

// Topic: Heap Sort

void heapify(int i, vector<int> &arr, int n) {  // T.c: O(log(n))
  int lchild = 2 * i + 1;
  int rchild = 2 * i + 2;
  int maxid = i;
  if (lchild < n && arr[lchild] > arr[maxid]) {
    maxid = lchild;
  }
  if (rchild < n && arr[rchild] > arr[maxid]) {
    maxid = rchild;
  }
  if (maxid != i) {
    swap(arr[maxid], arr[i]);
    heapify(maxid, arr, n);
  }
}

void heapSort(vector<int> &arr) {  // T.c : O(nlog(n))
  int n = arr.size();

  // Step 1: build a heap
  for (int i = n / 2 - 1; i >= 0; i--) {  // would heapify only non-leaf nodes
    heapify(i, arr, n);
  }

  // Step 2: Sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(0, arr, i);
  }
}

int main() {
  vector<int> arr = {0, 4, 6, 2, 1, 67, 32, 24, 3};
  heapSort(arr);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
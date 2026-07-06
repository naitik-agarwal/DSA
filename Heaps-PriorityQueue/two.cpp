#include <bits/stdc++.h>
using namespace std;
// Topic: Push in Heap

class Heap {
  vector<int> vec;  // CBT
 public:
  void push(int val) {
    vec.push_back(val);
    int childid = vec.size() - 1;  // 0 based indexing
    int parentidx = (childid - 1) / 2;
    while (parentidx >= 0 && vec[childid] > vec[parentidx]) {
      swap(vec[parentidx], vec[childid]);
      childid = parentidx;
      parentidx = (childid - 1) / 2;
    }
  }
  void heapify(int parent) {
    if (parent >= vec.size()) {  // would happen if size of heap is 1 and we pop
      return;
    }
    int lchild = 2 * parent + 1;
    int rchild = 2 * parent + 2;
    int maxIdx = parent;
    if (lchild < vec.size() && vec[lchild] > vec[maxIdx]) {
      maxIdx = lchild;
    }
    if (rchild < vec.size() && vec[rchild] > vec[maxIdx]) {
      maxIdx = rchild;
    }
    swap(vec[maxIdx], vec[parent]);
    if (maxIdx != parent) {
      heapify(maxIdx);
    }
  }
  void
  pop() {  // would remove the max priority element (obviously its a heap/pq)
    if (vec.empty()) {
      return;
    }
    swap(vec[0], vec[vec.size() - 1]);
    vec.pop_back();
    heapify(0);
  }
  int top() {
    if (vec.empty()) {
      return -1;
    }
    return vec[0];
  }
  bool empty() { return vec.size() == 0 ? true : false; }
  void buildHeap(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      vec.push_back(arr[i]);
    }
  }
};

int main() {
  Heap hp;
  hp.push(50);
  hp.push(10);
  hp.push(100);
  hp.push(5);
  cout << "Top element: " << hp.top() << endl;
  hp.pop();
  cout << "Top element: " << hp.top() << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node(int data) {
    this->val = data;
    left = right = nullptr;
  }
};

int maxx = 0;
void maxWidthofBT(Node *root) {
  if (root == nullptr) {
    return;
  }
  deque<pair<Node *, int>> q;
  q.push_front({root, 0});
  while (!q.empty()) {
    maxx = max(maxx, q.back().second - q.front().second + 1);
    int sze = q.size();
    for (int i = 0; i < sze; i++) {
      Node *curr = q.front().first;
      int id = q.front().second;
      q.pop_front();
      if (curr->left) {
        q.push_back({curr->left, 2 * id + 1});
      }
      if (curr->right) {
        q.push_back({curr->right, 2 * id + 2});
      }
    }
  }
}

// Top view of a binary tree:
map<int, int> mp;
void topView(Node *root, int d) {
  if (root == nullptr) {
    return;
  }
  if (mp[d] == 0) {
    mp[d] = root->val;
    topView(root->left, d - 1);
    topView(root->right, d + 1);
  }
}

// Build Tree from preorder
int idx = -1;
Node *buildTreefromPreorder(vector<int> &v) {
  idx++;
  if (v[idx] == -1) {
    return nullptr;
  }
  Node *curr = new Node(v[idx]);
  curr->left = buildTreefromPreorder(v);
  curr->right = buildTreefromPreorder(v);
  return curr;
}

int main() {
  vector<int> preorder = {1, 2, 4, -1, -1, -1, 3, -1, 5, -1, -1};
  Node *root = buildTreefromPreorder(preorder);
  topView(root, 0);
  for (auto &it : mp) {
    cout << it.second << " ";
  }
  cout << endl;
  return 0;
}
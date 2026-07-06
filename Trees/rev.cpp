#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    this->data = value;
    left = right = nullptr;
  }
};

void preorder(Node *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root) {
  if (root == nullptr) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root) {
  if (root == nullptr) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

vector<vector<int>> LevelOrder(Node *root) {
  vector<vector<int>> ans;
  if (root == nullptr) {
    return;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++) {
      Node *node = q.front();
      q.pop();
      if (node->left != nullptr) {
        q.push(node->left);
      }
      if (node->right != nullptr) {
        q.push(node->right);
      }
      level.push_back(node->data);
    }
    ans.push_back(level);
  }
  return ans;
}

int height(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }
  return 1 + max(height(root->left), height(root->right));
}

pair<int, int> diameterofTree(Node *root) {
  if (root == nullptr) {
    return {0, 0};
  }
  pair<int, int> lef = diameterofTree(root->left);
  pair<int, int> rig = diameterofTree(root->right);
  int lh = lef.second, ld = lef.first;
  int rh = rig.second, rd = rig.first;
  return {max({ld, rd, lh + rh + 1}), 1 + max(lh, rh)};
}

int main() {}
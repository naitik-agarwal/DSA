#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node(int data) {
    this->val = data;
    left = right = nullptr;
  }
};

Node* insert(Node* root, int data) {  // TC: O(log(n))
  if (root == nullptr) {
    root = new Node(data);
    return root;
  }
  if (root->val > data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

Node* buildBST(vector<int>& arr, int n) {
  Node* root = nullptr;

  for (int i = 0; i < n; i++) {
    root = insert(root, arr[i]);
  }
  return root;
}

void inOrder(Node* root) {
  if (root == nullptr) {
    return;
  }
  inOrder(root->left);
  cout << root->val << " ";
  inOrder(root->right);
}

Node* SearchinBST(Node* root, int key) {  // TC: O(height)
  if (root == nullptr) {
    return nullptr;
  }
  if (root->val == key) {
    return root;
  } else if (root->val < key) {
    return SearchinBST(root->right, key);
  } else {
    return SearchinBST(root->left, key);
  }
}

int main() {
  vector<int> arr = {5, 1, 3, 4, 2, 7};
  vector<int> arr2 = {8, 5, 3, 1, 4, 6, 10, 11, 14};
  Node* root = nullptr;
  root = buildBST(arr2, 9);
  inOrder(root);
  cout << endl;

  Node* find6 = SearchinBST(root, 2);
  if (find6 != nullptr) {
    cout << find6->val << endl;
  } else {
    cout << "Not Found" << endl;
  }

  return 0;
}
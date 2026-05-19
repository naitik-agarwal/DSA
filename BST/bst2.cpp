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

Node* insert(Node* root, int data) {
  if (root == nullptr) {
    return new Node(data);
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
  for (int i = 0; i < arr.size(); i++) {
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

Node* SearchinBST(Node* root, int key) {
  // TC: O(height)
  if (root == nullptr) {
    return nullptr;
  }
  if (root->val == key) {
    return root;
  }
  if (root->val < key) {
    return SearchinBST(root->right, key);
  } else {
    return SearchinBST(root->left, key);
  }
}

Node* IS(Node* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

Node* delNode(Node* root, int val) {
  if (root == nullptr) return nullptr;

  if (val < root->val) {
    root->left = delNode(root->left, val);
  } else if (val > root->val) {
    root->right = delNode(root->right, val);
  } else {
    // Node found

    // Case 1: no child
    if (root->left == nullptr && root->right == nullptr) {
      return nullptr;
    }

    // Case 2: one child
    else if (root->left == nullptr) {
      return root->right;
    } else if (root->right == nullptr) {
      return root->left;
    }

    // Case 3: two children
    else {
      Node* inordersucc = IS(root->right);
      root->val = inordersucc->val;
      root->right = delNode(root->right, inordersucc->val);
    }
  }
  return root;
}

void PrintInRange(Node* root, int l, int r) {
  if (root == nullptr) {
    return;
  }
  if (root->val <= r && root->val >= l) {
    PrintInRange(root->left, l, r);
    cout << root->val << " ";
    PrintInRange(root->right, l, r);
  } else if (root->val < l) {
    PrintInRange(root->right, l, r);
  } else {
    PrintInRange(root->left, l, r);
  }
}

vector<int> path;
void RoottoLeafPath(Node* root) {
  if (root == nullptr) {
    return;
  }
  path.push_back(root->val);
  if (root->left == nullptr && root->right == nullptr) {
    for (int i = 0; i < path.size(); i++) {
      cout << path[i] << " ";
    }
    cout << endl;
  }
  RoottoLeafPath(root->left);
  RoottoLeafPath(root->right);
  path.pop_back();
}

int main() {
  vector<int> arr = {5, 1, 3, 4, 2, 7};
  vector<int> arr2 = {8, 5, 3, 1, 4, 6, 10, 11, 14};
  vector<int> arr3 = {1, 3, 4, 5, 6, 8, 10, 11, 14};
  Node* root = nullptr;
  Node* root2 = nullptr;
  root = buildBST(arr2, arr2.size());
  root2 = buildBST(arr3, arr3.size());
  //   PrintInRange(root2, 5, 12);
  //   cout << endl;
  RoottoLeafPath(root);
  return 0;
}
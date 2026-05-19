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

static int idx = -1;
Node *buildTreeFromPreorder(vector<int> &nodes) {
  idx++;
  if (nodes[idx] == -1) {
    return nullptr;
  }
  Node *curr = new Node(nodes[idx]);
  curr->left = buildTreeFromPreorder(nodes);
  curr->right = buildTreeFromPreorder(nodes);
  return curr;
}

// LCA
bool rootToNodePath(Node *root, int n, vector<int> &path) {
  if (root == nullptr) {
    return false;
  }
  path.push_back(root->data);
  if (root->data == n) {
    return true;
  }
  bool isLeft = rootToNodePath(root->left, n, path);
  bool isRight = rootToNodePath(root->right, n, path);
  if (isLeft || isRight) {
    return true;
  }
  path.pop_back();
  return false;
}

int LCA(Node *root, int n1, int n2) {
  vector<int> path1, path2;
  bool found1 = rootToNodePath(root, n1, path1);
  bool found2 = rootToNodePath(root, n2, path2);

  // if any node is not part of tree:
  if (!found1 || !found2) {
    return -1;
  }
  int ans = root->data;
  for (int i = 0; i < min(path1.size(), path2.size()); i++) {
    if (path1[i] != path2[i]) {
      return ans;
    } else {
      ans = path1[i];
    }
  }
  return ans;
}

Node *LCA_optimized(Node *root, int n1, int n2) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->data == n1 || root->data == n2) {
    return root;
  }
  Node *leftLCA = LCA_optimized(root->left, n1, n2);
  Node *rightLCA = LCA_optimized(root->right, n1, n2);
  if (leftLCA != nullptr && rightLCA != nullptr) {
    return root;
  }
  return leftLCA == nullptr ? rightLCA : leftLCA;
}
int LCA_to_node_path_length(Node *lca, Node *node) {
  if (lca == nullptr) {
    return -1;
  }
  if (lca == node) {
    return 0;
  }
  int left = LCA_to_node_path_length(lca->left, node);
  int right = LCA_to_node_path_length(lca->right, node);
  if (left == -1 && right == -1) {
    return -1;
  }
  if (left != -1) {
    return left + 1;
  } else {
    return right + 1;
  }
}

int KthAncestorOfNode(Node *root, int node, int k) {  // TC: O(n)
  if (root == nullptr) {
    return -1;
  }
  if (root->data == node) {
    return 0;
  }
  int leftDist = KthAncestorOfNode(root->left, node, k);
  int rightDist = KthAncestorOfNode(root->right, node, k);
  if (leftDist == -1 && rightDist == -1) {
    return -1;
  }
  int validVal = leftDist == -1 ? rightDist : leftDist;
  if (validVal + 1 == k) {
    cout << "Kth Ancestor: " << root->data << endl;
  }
  return validVal + 1;
}

Node *TransformtoSumTree(Node *root) {
  if (root == nullptr) {
    return nullptr;
  }
  Node *curr = new Node(0);
  curr->left = TransformtoSumTree(root->left);
  curr->right = TransformtoSumTree(root->right);
  int left = curr->left ? curr->left->data : 0;
  int right = curr->right ? curr->right->data : 0;
  curr->data = left + right;
  return curr;
}

int main() {
  vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node *root = buildTreeFromPreorder(nodes);

  int n1 = 6, n2 = 5;
  Node *no1 = root->right->right;
  Node *no2 = root->left->right;
  int lcaa = LCA(root, n1, n2);
  Node *lcaaopt_mind = LCA_optimized(root, n1, n2);
  int lcaaopt = lcaaopt_mind->data;
  int d1 = LCA_to_node_path_length(lcaaopt_mind, no1);
  int d2 = LCA_to_node_path_length(lcaaopt_mind, no2);
  cout << lcaa << " " << lcaaopt << endl;
  cout << "Minimum distance between n1 & n2 : " << d1 + d2 << endl;
  int sevenThAnc = KthAncestorOfNode(root, no1->data, 3);
  Node *last = TransformtoSumTree(root);
  cout << last->data << endl;
  return 0;
}
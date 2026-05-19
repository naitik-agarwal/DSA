#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    left = right = nullptr;
  }
};

// build tree from preorder -> root-left-right
static int idx = -1;
Node *buildTree(vector<int> &nodes) {
  idx++;
  if (nodes[idx] == -1) {
    return nullptr;
  }
  Node *curr = new Node(nodes[idx]);
  curr->left = buildTree(nodes);
  curr->right = buildTree(nodes);
  return curr;
}

void preorder(Node *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

vector<vector<int>> kevelOrder(Node *root) {
  // this is bfs
  vector<vector<int>> ans;
  if (root == nullptr) {
    return ans;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    int sze = q.size();
    vector<int> level;
    for (int i = 0; i < sze; i++) {
      Node *c = q.front();
      q.pop();
      if (c->left != nullptr) {
        q.push(c->left);
      }
      if (c->right != nullptr) {
        q.push(c->right);
      }
      level.push_back(c->data);
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

int diameterofTree(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  int currdia = height(root->left) + 1 + height(root->right);
  return max(currdia,
             max(diameterofTree(root->left), diameterofTree(root->right)));
}

pair<int, int> diameterofTreeOptimized(Node *root) {
  // pair<int,int> => {diameter,height}
  if (root == nullptr) {
    return {0, 0};
  }
  pair<int, int> lef = diameterofTreeOptimized(root->left);
  pair<int, int> rig = diameterofTreeOptimized(root->right);
  int lh = lef.second, ld = lef.first;
  int rh = rig.second, rd = rig.first;
  return {max(ld, max(rd, 1 + lh + rh)), 1 + max(lh, rh)};
}

bool isIdentical(Node *root1, Node *root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }
  if (root1->data != root2->data) {
    return false;
  }
  return (isIdentical(root1->left, root2->left) &&
          isIdentical(root1->right, root2->right));
}

bool isSubtree(Node *root1, Node *root2) {
  // is root2 a subtree of root1???
  if (root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr) {
    return false;
  }
  if (root1->data == root2->data) {
    if (isIdentical(root1, root2)) {
      return true;
    }
  }
  return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

int main() {
  vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node *root = buildTree(nodes);
  cout << diameterofTree(root) << endl;
  cout << diameterofTreeOptimized(root).first << endl;
  Node *root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(3);
  root2->left->right = new Node(4);
  root2->left->right->right = new Node(5);
  cout << isSubtree(root, root2) << endl;
  vector<vector<int>> lo = kevelOrder(root);
  for (int i = 0; i < lo.size(); i++) {
    cout << "level " << i + 1 << ": ";
    for (int j = 0; j < lo[i].size(); j++) {
      cout << lo[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
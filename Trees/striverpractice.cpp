#include <bits/stdc++.h>
using namespace std;

struct Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node(int data) {
    this->val = data;
    left = right = nullptr;
  }
};

vector<int> ans;
bool RoottoLeafNodePath(Node* root, int node) {
  if (root == nullptr) {
    return false;
  }
  ans.push_back(root->val);
  if (root->val == node) {
    return true;
  }
  bool l = RoottoLeafNodePath(root->left, node);
  if (l) {
    return true;
  }
  bool r = RoottoLeafNodePath(root->right, node);
  if (r) {
    return true;
  }
  ans.pop_back();
  return false;
}

// void TopViewofBT(Node* root) {
//   if (root == nullptr) {
//     return;
//   }
//   map<int, int> mp;
//   queue<pair<Node*, int>> q;
//   q.push({root, 0});
//   while (!q.empty()) {
//     auto front = q.front();
//     q.pop();
//     Node* curr = front.first;
//     int hd = front.second;
//     if (mp.find(hd) == mp.end()) {
//       mp[hd] = curr->val;
//     }
//     if (curr->left) {
//       q.push({curr->left, hd - 1});
//     }
//     if (curr->right) {
//       q.push({curr->right, hd + 1});
//     }
//   }
//   for (auto& it : mp) {
//     cout << it.second << " ";
//   }
//   cout << endl;
// }

// void BottomViewofBT(Node* root) {
//   if (root == nullptr) {
//     return;
//   }
//   map<int, vector<int>> mp;
//   queue<pair<Node*, int>> q;
//   q.push({root, 0});
//   while (!q.empty()) {
//     auto front = q.front();
//     q.pop();
//     Node* curr = front.first;
//     int hd = front.second;
//     mp[hd].push_back(curr->val);
//     if (curr->left) {
//       q.push({curr->left, hd - 1});
//     }
//     if (curr->right) {
//       q.push({curr->right, hd + 1});
//     }
//   }
//   for (auto& it : mp) {
//     cout << it.second.back() << " ";
//   }
//   cout << endl;
// }

// vector<vector<int>> levelordertraversal(Node* root) {
//   vector<vector<int>> v;
//   if (root == nullptr) {
//     return v;
//   }
//   queue<Node*> q;
//   q.push(root);
//   while (!q.empty()) {
//     int sze = q.size();
//     vector<int> level;
//     for (int i = 0; i < sze; i++) {
//       Node* curr = q.front();
//       q.pop();
//       if (curr->left) {
//         q.push(curr->left);
//       }
//       if (curr->right) {
//         q.push(curr->right);
//       }
//       level.push_back(curr->val);
//     }
//     v.push_back(level);
//   }
//   return v;
// }
// void rightView(Node* root) {
//   vector<vector<int>> lot = levelordertraversal(root);
//   for (int i = 0; i < lot.size(); i++) {
//     cout << lot[i].back() << " ";
//   }
//   cout << endl;
// }

class Solution {
 public:
  vector<vector<int>> lotwithhd(TreeNode* root) {}
  vector<vector<int>> verticalTraversal(TreeNode* root) {}
};

int main() {}
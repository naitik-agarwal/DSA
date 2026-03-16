#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;
   Node(int val)
   {
      data = val;
      left = right = nullptr;
   }
};

int height(Node *root)
{ // Time Complexity : O(n) because ham har node pe eak baar jate hai
   if (root == nullptr)
   {
      return 0;
   }
   if (root->left == nullptr && root->right == nullptr)
   {
      return 1;
   }
   return 1 + max(height(root->left), height(root->right));
}

int countofnodes(Node *root) // time complexity : O(n)
{
   if(root==nullptr){
      return 0;
   }
   return 1+countofnodes(root->left)+countofnodes(root->right);
}

int main()
{
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->right = new Node(6);
   root->left->right->left = new Node(7);
   cout << height(root) << endl;
   cout << countofnodes(root) << endl;
   return 0;
}
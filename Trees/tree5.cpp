#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;

   Node(int val)
   {
      data = val;
      left = right = nullptr;
   }
};

// build tree from preorder -> root, left, right
static int idx = -1;
Node *buildTree(vector<int> nodes)
{
   idx++;
   if (nodes[idx] == -1)
   {
      return nullptr;
   }
   Node *currNode = new Node(nodes[idx]);
   currNode->left = buildTree(nodes);
   currNode->right = buildTree(nodes);

   return currNode;
}
int height(Node *root)
{
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

int diameterofTree(Node *root)
{
   if (root == nullptr)
   {
      return 0;
   }
   int currdia = height(root->left) + 1 + height(root->right);
   return max(currdia, max(diameterofTree(root->left), diameterofTree(root->right)));
}

int diameterofTreeOptimized(Node *root){
   if(root==nullptr){
      return 0;
   }
   
}

int main()
{
   vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; // preorder of tree given
   Node *root = buildTree(nodes);
   cout<<root->data<<endl;
   cout<<height(root)<<endl;
   cout<<diameterofTree(root)<<endl;
   return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;
   // constructor
   Node(int val)
   {
      this->data = val;
      left = right = nullptr;
   }
};

// build tree from preorder
static int idx = -1;
Node *buildTree(vector<int> nodes) // time complexity : O(n)
{                                  // would return the ptr to the root of our tree
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
{ // time complexity: O(n^2)
   if (root == nullptr)
   {
      return 0;
   }
   if (root->left == nullptr && root->right == nullptr)
   {
      return 1;
   }
   // lets first calculate height of left subtree lheight
   int lheight = height(root->left);
   int rheight = height(root->right);
   int currdia = 1 + lheight + rheight;
   return max(currdia, max(diameterofTree(root->left), diameterofTree(root->right)));
}
pair<int, int> diameterOptimized(Node *root)
{
   if (root == nullptr)
   {
      return {0, 0};
   }
   pair<int, int> lef = diameterOptimized(root->left);
   pair<int, int> rig = diameterOptimized(root->right);
   int lh = lef.second, ld = lef.first;
   int rh = rig.second, rd = rig.first;
   return {max(ld, max(rd, lh + rh + 1)), 1 + max(lh, rh)};
}

// Checking subtree:
// first implement isIdentical function
bool isIdentical(Node *root1, Node *root2)
{
   if (root1 == nullptr && root2 == nullptr)
   {
      return true;
   }
   if (root1 == nullptr || root2 == nullptr)
   {
      return false;
   }
   if (root1->data != root2->data)
   {
      return false;
   }
   return (isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}
bool isSubtree(Node *root1, Node *root2)
{
   if (root2 == nullptr)
   {
      return true;
   }
   if (root1 == nullptr)
   {
      return false;
   }
   if (root1->data == root2->data)
   {
      if (isIdentical(root1, root2))
      {
         return true;
      }
   }

   return isSubtree(root1->left,root2)||isSubtree(root1->right,root2);
}
vector<pair<int,int>> horizontalDistanceMapping(Node *root){
   vector<pair<int,int>> hd;
   if(root==nullptr){
      return hd;
   }
   queue<pair<Node *,int>> q;
   q.push({root,0});
   while(q.empty()!=1){
      int sze=q.size();
      for(int i=0;i<sze;i++){
         Node *curr=q.front().first;
         int hdis=q.front().second;
         hd.push_back({hdis,curr->data});
         q.pop();
         if(curr->left!=nullptr){
            q.push({curr->left,hdis-1});
         }
         if(curr->right!=nullptr){
            q.push({curr->right,hdis+1});
         }
      }
   }
   return  hd;
}
void topViewofTree(Node *root){
   vector<pair<int,int>> hdis=horizontalDistanceMapping(root);
   
   map<int,int> topView;
   for(int i=0;i<hdis.size();i++){
      if(topView.find(hdis[i].first)==topView.end()){
         topView[hdis[i].first]=hdis[i].second;
      }
   }
   for(auto &p:topView){
      cout<<p.second<<" ";
   }
   cout<<endl;
}
void levelorderTraversal(Node *root){
   if(root==nullptr){
      return;
   }
   queue<Node *> q;
   q.push(root);
   while(q.empty()!=1){
      int sze=q.size();
      for(int i=0;i<sze;i++){
         Node *curr=q.front();
         q.pop();
         if(curr->left!=nullptr){
            q.push(curr->left);
         }
         if(curr->right!=nullptr){
            q.push(curr->right);
         }
         cout<<curr->data<<" ";
      }
      cout<<endl;
   }
}

int main()
{
   vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; // preorder of tree given
   Node *root = buildTree(nodes);
   cout << root->data << endl;
   cout << diameterofTree(root) << endl;
   cout << diameterOptimized(root).first << endl;
   Node *root2 = new Node(1);
   root2->left = new Node(2);
   root2->right = new Node(3);
   root2->left->right = new Node(4);
   root2->left->right->right = new Node(5);
   cout << isSubtree(root, root2) << endl;
   levelorderTraversal(root);

   topViewofTree(root);
   topViewofTree(root2);
   return 0;
}
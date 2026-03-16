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

void preorder(Node *node)
{
   if (node == nullptr)
   {
      return;
   }
   cout << node->data << " ";
   preorder(node->left);
   preorder(node->right);
}

void inorder(Node *node)
{
   if (node == nullptr)
   {
      return;
   }
   inorder(node->left);
   cout << node->data << " ";
   inorder(node->right);
}

void postorder(Node *node)
{
   if (node == nullptr)
   {
      return;
   }
   postorder(node->left);
   postorder(node->right);
   cout << (node->data) << " ";
}

vector<vector<int>> levelorder(Node *node)
{
   vector<vector<int>> ans;
   if(node==nullptr){
      return ans;
   }
   ans.push_back({node->data});
   queue<Node *> q;
   q.push(node);
   while (q.empty() != 1)
   {
      vector<int> temp;
      int sze = q.size();
      for (int i = 0; i < sze; i++)
      {
         Node *nde = q.front();
         q.pop();
         if (nde->left != nullptr)
         {
            temp.push_back(nde->left->data);
            q.push(nde->left);
         }
         if (nde->right != nullptr)
         {
            temp.push_back(nde->right->data);
            q.push(nde->right);
         }
      }
      ans.push_back(temp);
   }
   return ans;
}
void IterativePreorder(Node *node){ // root left right
   if(node==nullptr){
      return;
   }
   stack<Node *> s;
   s.push(node);
   while(s.empty()!=1){
      Node *nde=s.top();
      s.pop();
      cout<<nde->data<<" ";
      if(nde->right!=nullptr){
         s.push(nde->right);
      }
      if(nde->left!=nullptr){
         s.push(nde->left);
      }
   }
}

void IterativeInorder(Node *root){
   if(root==nullptr){
      return;
   }
   stack<Node *> s;
   Node *node=root;
   while(true){
      if(node!=nullptr){
         s.push(node);
         node=node->left;
      }
      else{
         if(s.empty()==1){
            break;
         }
         node=s.top(); 
         s.pop();
         cout<<node->data<<" ";
         node=node->right;
      }
   }
}

void IterativePostorderusingtwoStacks(Node *root){
   if(root==nullptr){
      return;
   }
   stack<Node *> s1,s2;
   s1.push(root);
   while(s1.empty()!=1){
      Node *nde=s1.top();
      s2.push(nde);
      s1.pop();
      if(nde->left!=nullptr){
         s1.push(nde->left);
      }
      if(nde->right!=nullptr){
         s1.push(nde->right);
      }
   }
   while(s2.empty()!=1){
      cout<<s2.top()->data<<" ";
      s2.pop();
   }
}

int main()
{
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);
   preorder(root);
   cout << endl;
   inorder(root);
   cout << endl;
   postorder(root);
   cout << endl;
   cout << "Level-order" << " ";
   vector<vector<int>> ass = levelorder(root);
   for (int i = 0; i < ass.size(); i++)
   {
      for (int j = 0; j < ass[i].size(); j++)
      {
         cout << ass[i][j] << " ";
      }
      cout << endl;
   }
   IterativePreorder(root);
   cout<<endl;
   IterativeInorder(root);
   cout<<endl;
   IterativePostorderusingtwoStacks(root);
   cout<<endl;
   return 0;
}
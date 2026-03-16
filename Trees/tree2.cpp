#include<bits/stdc++.h>
using namespace std;
// Tree Traversal Techniques

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

void preorder(Node *node){
    if(node==nullptr){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node){
    if(node==nullptr){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void postorder(Node *node){
    if(node==nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

vector<vector<int>> levelorderr(Node *node){
    vector<vector<int>> ans;
    if(node==nullptr){
        return ans;
    }
    queue<Node*> q;
    q.push(node);
    while(q.empty()!=1){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node *nde=q.front();
            q.pop();
            if(nde->left!=nullptr){
                q.push(nde->left);
            }
            if(nde->right!=nullptr){
                q.push(nde->right);
            }
            level.push_back(nde->data);
        }
        ans.push_back(level);
    }
    return ans;
}
void IterativePreorder(Node *root){
    if(root==nullptr){
        return;
    }
    stack<Node *> stk;
    stk.push(root);
    while(!stk.empty()){
        Node *node=stk.top();
        stk.pop();
        if(node->right!=nullptr){
            stk.push(node->right);
        }
        if(node->left!=nullptr){
            stk.push(node->left);
        }
        cout<<node->data<<" ";
    }
}
// void IterativeInorder(Node *root){ // left -> root -> right
//     if(root==nullptr){
//         return;
//     }
//     stack<Node *> stk;
//     stk.push(root);
//     while(stk.empty()!=1){
//         Node *node=stk.top();
//         if(node->right!=nullptr){
//             stk.push(node->right);
//         }
//         if(node->left!=nullptr){
//             stk.push(node->left);
//         }
//     }
// }







void IterativeInorder(Node *root){
    if(root==nullptr){
        return;
    }
    stack<Node *> stk;
    stk.push(root);
    while(!stk.empty()){
        Node *node=stk.top();
        stk.pop();
        if(node->right!=nullptr){
            stk.push(node->right);
        }
        if(node->left!=nullptr){
            stk.push(node->left);
        }
        
    }
}

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder : ";
    postorder(root);
    cout<<endl;
    vector<vector<int>> levelorderans=levelorderr(root);
    for(int i=0;i<levelorderans.size();i++){
        cout<<"Level "<<i+1<<" : ";
        for(int j=0;j<levelorderans[i].size();j++){
            cout<<levelorderans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Iterative Preorder : ";
    IterativePreorder(root);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left,*right;
        node(int data){
            this->data=data;
            left=right=NULL;
        }
};
void getLeft(node* root,vector<int>& ans){
    if(root==NULL)  return ;
    if(root->left== NULL && root->right==NULL)  return ;

    ans.push_back(root->data);
    if(root->left)
        getLeft(root->left,ans);
    else
        getLeft(root->right,ans);
}
void getLeaf(node* root,vector<int>& ans){
    if(root==NULL)  return;
    if(root->left== NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    getLeaf(root->left ,ans);
    getLeaf(root->right ,ans);
}
void getRight(node* root,vector<int>& ans){
    if(root==NULL)  return ;
    if(root->left== NULL && root->right==NULL)  return ;

    if(root->right)
        getRight(root->right,ans);
    else
        getRight(root->left,ans);
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(node* root){
    vector<int> ans;
    ans.push_back(root->data);
    getLeft(root->left,ans);
    getLeaf(root,ans);
    getRight(root->right,ans);
    return ans;
}
int main(){
        
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->right->right->right = new node(7);

    vector<int> boundary = boundaryTraversal(root);
    
    
    for (int value : boundary) {
        cout << value << " ";
    }

    
    delete root; 

    return 0;
}
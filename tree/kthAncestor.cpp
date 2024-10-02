#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left,* right;
        node(int data){
            this->data=data;
            left=right=NULL;
        }
};
node* solve(node* root,int &k,int target){
    if(root==NULL)  return NULL;
    if(root->data==target)  return root;

    node* left= solve(root->left,k,target);
    node* right= solve(root->right,k,target);

    if(left!=NULL){
        k--;
        if(k==0)    return root;
        return left;
    }
    if(right!=NULL){
        k--;
        if(k==0)    return root;
        return right;
    }
    return NULL;
}
int kthAncestor(node* root, int k, int target){
    node* ans=solve(root,k,target);
    return (k>0)?-1:ans->data;
}
int main(){
    // Creating a sample binary tree
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    int k = 2;
    int target = 4;

    int result = kthAncestor(root, k, target);
    
    if(result != -1)
        cout << "The " << k << "th ancestor of " << target << " is: " << result << endl;
    else
        cout << "No such ancestor exists." << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left, *right;
        node(int data){
            this->data=data;
            left=right=NULL;
        }
};
class info{
    public:
        int maxi;
        int mini;
        bool isBst;
        int size;
};
info solve(node* root, int & maxSize){
    if(root==NULL){
        return {INT_MIN,INT_MAX, true, 0};
    }

    info left=solve(root->left,maxSize);
    info right=solve(root->right,maxSize);

    info curr;
    curr.size=left.size+right.size+1;
    curr.maxi=max(root->data,right.maxi);
    curr.mini=min(root->data,left.mini);
    curr.isBst=(left.isBst && right.isBst&&(root->data < right.mini && root->data > left.maxi));
    if(curr.isBst)
        maxSize=max(maxSize,curr.size);
    return curr;
}
int largestBst(node*root){
    int maxSize=0;
    solve(root,maxSize);
    return maxSize;
}
int main() {
    // You can create your binary tree here and call largestBst(root)
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(1);
    root->left->right = new node(8);
    root->right->right = new node(7);

    cout << "Size of largest BST is: " << largestBst(root) << endl;

    return 0;
}
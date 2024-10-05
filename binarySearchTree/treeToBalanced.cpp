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

node* buildTree(){
    int data;
    cin>>data;
    if(data==-1)    return NULL;
    node* root=new node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void inorder(node* root,vector<int> &traverse){
    if(root==NULL)  return;
    inorder(root->left,traverse);
    // cout<<root->data<<" ";
    traverse.push_back(root->data);
    inorder(root->right,traverse);
}
void traverse(node* root){
    if(root==NULL)  return;
    traverse(root->left);
    cout<<root->data<<" ";
    traverse(root->right);
}
node* insert(vector<int> arr,int s, int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node* root=new node( arr[mid]);
    root->left=insert(arr,s,mid-1);
    root->right=insert(arr,mid+1,e);
    return root;
}
node* newTree(node* root){
    vector<int> arr;
    inorder(root,arr);
    return insert(arr,0,arr.size()-1);
}
int main() {
    // Build the original tree
    cout << "Enter the tree nodes in preorder (use -1 for null):\n";
    node* root = buildTree();

    // Create a new balanced tree
    node* balancedRoot = newTree(root);

    // Print inorder traversal of the new balanced tree
    cout << "Inorder traversal of the new balanced tree:\n";
    traverse(balancedRoot);

    return 0;
}
//10 5 1 -1 -1 7 -1 -1 15 12 -1 -1 20 -1 -1
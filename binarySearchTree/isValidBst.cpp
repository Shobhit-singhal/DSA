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


bool isValid(node* root, int min=INT_MIN, int max=INT_MAX){
    if(root==NULL)  return true;
    if(root->data >= min && root->data <= max){
        bool left=isValid(root->left,min,root->data);
        bool right=isValid(root->right,root->data,max);
        return left && right;
    }
    return false;
}
node* buildTree(){
    int data;
    cin>>data;
    if(data==-1)    return NULL;
    node* root=new node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void inorder(node* root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node* root=buildTree();
    
    cout<< "bst or not: "<<isValid(root)<<endl;
    inorder(root);
}
//3 1 -1 2 -1 -1 5 -1 -1
//4 2 1 -1 -1 0 -1 -1 5 -1 -1
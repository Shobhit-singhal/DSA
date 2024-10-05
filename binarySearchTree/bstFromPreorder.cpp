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
node* solve(vector<int>& preorder, int min, int max, int& i){
    if(i>=preorder.size())  return NULL;
    if(preorder[i]> max || preorder[i]< min)    return NULL;
    node* root=new node(preorder[i++]);
    root->left=solve(preorder,min,preorder[i-1],i);
    root->right=solve(preorder,preorder[i-1],max,i);
    return root;
}
node* createdBST(vector<int> preorder){
    int i=0;
    return solve(preorder,INT_MIN, INT_MAX,i);
}
void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    vector<int> preorder={20, 10, 5, 15, 13, 35, 30, 42};
    node* root=createdBST(preorder);
    inorder(root);
    
    
}
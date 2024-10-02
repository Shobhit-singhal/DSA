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
void createMap(vector<int> inorder, map<int , int > & m1){
    for(int i=0;i<inorder.size();i++){
        m1[inorder[i]]=i;
    }
}
node* solve(vector<int>& inorder, vector<int>& postorder,int &idx,int s,int e, int n,map<int,int>& m1){
    if(idx<0 || s>e)   return NULL;
    int el=postorder[idx--];
    int pos=m1[el];
    node* root=new node(el);
    root->right=solve(inorder,postorder,idx,pos+1,e,n,m1);
    root->left=solve(inorder,postorder,idx,s,pos-1,n,m1);
    return root;
}
node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=inorder.size();
    int idx=n-1;
    map<int,int> m1;
    createMap(inorder,m1);
    return solve(inorder,postorder,idx,0,n-1,n,m1);
}
void printInorder(node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {
    // Example usage of the buildTree function
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    node* root = buildTree(inorder, postorder);
    printInorder(root);
    return 0;
}
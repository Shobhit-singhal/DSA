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
int find(vector<int> arr, int el,int n){
    for( int i=0;i<n;i++){
        if(arr[i]==el)  return i;
    }
    return -1;
}
node* solve(vector<int> preorder, vector<int> inorder, int& idx, int s,int e,int n){
    if(idx>=n || s>e)   return NULL;
    int el=preorder[idx++];
    int pos=find(inorder,el,n);
    node* root=new node(el);
    root->left=solve(preorder,inorder,idx,s,pos-1,n);
    root->right=solve(preorder,inorder,idx,pos+1,e,n);
    return root;

}
node* buildTree(vector<int> preorder, vector<int> inorder, int n){
    int idx=0;
    node* ans= solve(preorder,inorder,idx,0,n-1,n);
    return ans;
}
void printInorder(node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main(){
        // Example input: Preorder and Inorder traversals
    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    vector<int> inorder = {4, 2, 5, 1, 6, 3};

    int n = preorder.size();

    // Build the tree
    node* root = buildTree(preorder, inorder, n);

    // Output the inorder traversal of the constructed tree
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
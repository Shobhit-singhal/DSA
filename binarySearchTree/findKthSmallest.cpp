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
int solve(node* root,int k, int& i){
    if(root==NULL)  return -1;
    int left=solve(root->left,k,i);
    if(left!=-1)    return left;
    i++;
    if(i==k)    return root->data;
    return solve(root->right,k,i);
}
int kthSmallest(node* root, int k){
    int i=0;
    return solve(root,k,i);
}
int main(){
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->left->left->left = new node(1);

    int k = 3;
    cout << "The " << k << "-th smallest element is " << kthSmallest(root, k) << endl;

    return 0;
}
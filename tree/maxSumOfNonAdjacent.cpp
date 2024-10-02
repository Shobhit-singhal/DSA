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
pair<int,int> solve(node* root){
    if(root==NULL)  return make_pair(0,0);
    pair<int,int> left=solve(root->left);
    pair<int,int> right=solve(root->right);
    pair<int,int> ans;
    ans.first=root->data+left.second+right.second;
    ans.second=max(left.first, left.second) + max(right.first, right.second);
    return ans;
}
int maxSum(node* root){
    pair<int , int > ans=solve(root);
    return max(ans.first,ans.second);
}
int main(){
     // Creating a sample binary tree
    /*
            1
           / \
          2   3
         /   / \
        4   5   6
    */

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);

    // Output the result
    cout << "Maximum sum of non-adjacent nodes: " << maxSum(root) << endl;

    return 0;
}
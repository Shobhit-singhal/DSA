#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left, *right;
        node(int d){
            data=d;
            right=left=NULL;
        }
};
pair<int,bool> getAll(node* root){
    if(root==NULL){
        pair<int,bool> p=make_pair(0,1);
        return p;
    }
    pair<int,bool> left=getAll(root->left);
    pair<int,bool> right=getAll(root->right);
    pair<int,bool> ans;
    ans.first=max(left.first,right.first)+1;
    ans.second=left.second && right.second && abs(left.first-right.first)<=1;
    return ans;
}
bool isBalanced(node* root){
    return getAll(root).second;
}
int main(){
        node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);

    cout << "Is the tree balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;

    
    

    return 0;
}
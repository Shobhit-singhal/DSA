#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left, *right;
        node(int d){
            data=d;
            left=right=NULL;
        }
};
pair<int,int> getAll(node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=getAll(root->left);
    pair<int,int> right=getAll(root->right);
    pair<int,int> ans;
    ans.first=max(left.first, right.first)+1;
    ans.second=max(left.second,max(right.second,(left.first+right.first+1)));
    return ans;
}
int getDiameter(node* root){
    return getAll(root).second;
}
int main(){
        
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);

    cout << "Diameter of the tree: " << getDiameter(root) << endl;

    
    

    return 0;

}
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
void solve(node* root, int k, int& count, vector<int>& path){
    if(root==NULL)  return ;
    path.push_back(root->data);
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    int size=path.size();
    int sum=0;
    for( int i=size-1;  i>=0 ; i--){
        sum+=path[i];
        if(sum==k)  count++;
    }
    path.pop_back();
}
int kSumPath(node* root,int k){
    int count=0;
    vector<int> path;
    solve(root,k, count ,path);
    return count;
}
int main(){
        // Creating a binary tree
    node* root = new node(1);
    root->left = new node(3);
    root->right = new node(-1);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);

    // Find the number of paths with sum equal to k
    int k = 5;
    int result = kSumPath(root, k);
    cout << "Number of paths with sum " << k << " is: " << result << endl;

    return 0;
}
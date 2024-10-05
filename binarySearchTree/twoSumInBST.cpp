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


bool twoSumInBST(node* root,int target){
    vector<int> traverse;
    inorder(root,traverse);
    int sum=0;
    int i=0;
    int j=traverse.size()-1;
    while(i<j){
        sum=traverse[i]+traverse[j];
        if(sum>target){
            j--;
        }else if(sum<target){
            i++;
        }else{
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Enter the tree nodes in preorder (use -1 for null):\n";
    node* root = buildTree();

    int target;
    cout << "Enter the target sum:\n";
    cin >> target;

    if (twoSumInBST(root, target)) {
        cout << "There are two elements in the BST that sum to " << target << ".\n";
    } else {
        cout << "No two elements in the BST sum to " << target << ".\n";
    }

    return 0;
}

//10 6 2 -1 -1 8 -1 -1 12 11 -1 -1 15 -1 -1 
//20
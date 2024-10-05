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
void inorder(node* root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void getArr(node* root,vector<node*>& arr){
    if(root==NULL)  return;
    getArr(root->left,arr);
    arr.push_back(root);
    getArr(root->right,arr);
}
node* flatten(node* root)
{
    vector<node*> arr;
    getArr(root,arr);
    for(int i=0; i<arr.size()-1;i++){
        arr[i]->right=arr[i+1];
        arr[i]->left=NULL;
    }
    arr[arr.size()-1]->right=arr[arr.size()-1]->left=NULL;
    return arr[0];
}
int main(){
     cout << "Enter the tree nodes in preorder (use -1 for null):\n";
    node* root = buildTree();

    root=flatten(root);
    node* temp=root;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    

    return 0;
}

//10 6 2 -1 -1 8 -1 -1 12 11 -1 -1 15 -1 -1 
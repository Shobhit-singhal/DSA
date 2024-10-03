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


node* findPre(node* root){
    node* pre=root->left;
    while(pre->right!=NULL && pre->right!=root){
        pre=pre->right;
    }
    return pre;
}
void morrisTraversal(node* root){
    node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            node* pre=findPre(curr);
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                cout<<curr->data<<" ";
                pre->right=NULL;
                curr=curr->right;
            }
        }
    }
}
void inorder(node* root){
    if(root==NULL)  return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* buildTree(){
    int data;
    cin>>data;
    if(data==-1)    return NULL;
    node* root=new node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
int main(){
    node* root=buildTree();
    cout<<"By inorder traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<endl;
    cout<<"By morris traversal"<<endl;
    morrisTraversal(root);
}

// 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1
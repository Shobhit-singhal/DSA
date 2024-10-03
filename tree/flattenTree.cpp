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
    while (pre->right!=NULL && pre->right!=root)
    {
        pre=pre->right;
    }
    return pre;
    
}
void flattenTree(node* root){
    node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            node* pre=findPre(curr);
            pre->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
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
    node* root= buildTree();
    flattenTree(root);
    node* curr=root;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}
// 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1
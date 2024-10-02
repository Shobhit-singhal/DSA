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
node* lca( node* root, node* p, node* q){
    if(root==NULL) return NULL;
    if(root==p || root==q)  return root;

    node* left=lca(root->left,p,q);
    node* right=lca(root->right,p,q);

    if(left != NULL && right!=NULL )    return root;
    if(left == NULL && right!=NULL )    return right;
    if(left != NULL && right==NULL )    return left;
    else  return NULL;
}
int main(){
    node* root = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
    node* node6 = new node(6);
    
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;

    
    node* ancestor = lca(root, node4, node5);
    if (ancestor != NULL) {
        cout << "LCA of " << node4->data << " and " << node5->data << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    
    ancestor = lca(root, node4, node6);
    if (ancestor != NULL) {
        cout << "LCA of " << node4->data << " and " << node6->data << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    
    

    return 0;
}
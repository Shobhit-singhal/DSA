#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node* right;
        node(int data){
            this->data=data;
            left=right=NULL;
        }
};
int countNodes(node* root){
    if(root==NULL)  return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
bool isCBT(node* root, int idx, int nodeCnt){
    if(root==NULL)  return true;
    if(idx>=nodeCnt)    return false;
    else{
        bool left=isCBT(root->left,idx*2+1,nodeCnt);
        bool right=isCBT(root->right,2*idx+2,nodeCnt);
        return left&& right;
    }
}
bool isMaxOrder(node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right == NULL){
        return root->data>=root->left->data;
    }else{
        bool left=isMaxOrder(root->left);
        bool right=isMaxOrder(root->right);
        return left&&right && (root->data>=root->left->data)&&(root->data>=root->right->data);
    }
}
bool isTreeAHeap(node* root){
    if(root==NULL)  return true;
    int nodes=countNodes(root);
    return (isCBT(root,0,nodes)&& isMaxOrder(root));
}
int main() {
    // Example usage
    node* root = new node(10);
    root->left = new node(9);
    root->right = new node(8);
    // root->left->left = new node(7);
    root->left->right = new node(6);

    if (isTreeAHeap(root)) {
        cout << "The tree is a binary heap." << endl;
    } else {
        cout << "The tree is not a binary heap." << endl;
    }

    return 0;
}
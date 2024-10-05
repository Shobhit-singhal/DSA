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

node* lca(node* root, node* p, node* q){
    if(root==NULL)  return NULL;
    if(root->data > p->data && root->data > q->data ){
        return lca(root->left,p,q);
    }
    if(root->data < p->data&& root->data < q->data){
        return lca(root->right,p,q);
    }
    return root;
}

int main() {
    cout << "Enter the data to build the tree (-1 for NULL nodes):\n";
    node* root = buildTree();

    cout << "\nInorder traversal of the tree:\n";
    inorder(root);
    cout << endl;

    // Taking inputs for p and q to find LCA
    int pData, qData;
    cout << "\nEnter the values of the two nodes to find LCA:\n";
    cin >> pData >> qData;

    // Creating nodes for p and q
    node* p = new node(pData);
    node* q = new node(qData);

    node* ancestor = lca(root, p, q);
    if (ancestor != NULL) {
        cout << "\nLowest Common Ancestor of " << pData << " and " << qData << " is: " << ancestor->data << endl;
    } else {
        cout << "\nLCA not found!" << endl;
    }

    return 0;
}
//2 1 -1 -1 4 3 -1 -1 -1 1 3
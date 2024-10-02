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

void solveLft(node* root, vector<int>& ans, int lvl){
    if(root==NULL)  return ;
    if(lvl==ans.size()) ans.push_back(root->data);
    solveLft(root->left, ans, lvl+1);
    solveLft(root->right, ans, lvl+1);
}
vector<int> getLeftView(node* root){
    vector<int> ans;
    solveLft(root,ans,0);
    return ans;
}

void solveRt(node* root, vector<int>& ans, int lvl){
    if(root==NULL)  return ;
    if(lvl==ans.size()) ans.push_back(root->data);
    solveRt(root->right, ans, lvl+1);
    solveRt(root->left, ans, lvl+1);
}
vector<int> getRightView(node* root){
    vector<int> ans;
    solveRt(root,ans,0);
    return ans;
}
int main() {
    // Example usage
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> leftView = getLeftView(root);
    vector<int> rightView = getRightView(root);

    // Print left view
    cout << "Left View: ";
    for (int i : leftView) {
        cout << i << " ";
    }
    cout << endl;

    // Print right view
    cout << "Right View: ";
    for (int i : rightView) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
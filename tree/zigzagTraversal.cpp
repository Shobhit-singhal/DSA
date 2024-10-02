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
vector<vector<int>> zigzag(node* root){
    vector<vector<int>> ans;
    if(root==NULL)  return ans;
    queue<node*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> op(size);
        for(int i=0; i<size; i++){
            node* temp=q.front();
            q.pop();
            int idx=leftToRight? i:size-i-1;
            op[idx]=temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        leftToRight=!leftToRight;
        ans.push_back(op);
    }
    return ans;
}
int main(){
        // Example Usage:
    // Constructing a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    vector<vector<int>> result = zigzag(root);

    // Printing the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
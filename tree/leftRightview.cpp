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

vector<int> getLeftView(node* root){
    vector<int> ans;
    queue<pair<int, node*>> q;
    map<int,node*> nodes;
    if(root== NULL) return ans;
    q.push(make_pair(0,root));
    while (!q.empty())
    {
        pair<int, node*> temp=q.front();
        q.pop();
        node* curr= temp.second;
        int lvl=temp.first;
        if(nodes.find(lvl)==nodes.end())    nodes[lvl]=curr;
        if(curr->left) q.push(make_pair(lvl+1, curr->left));
        if(curr->right) q.push(make_pair(lvl+1, curr->right));
    }
    for(auto i: nodes){
        ans.push_back(i.second->data);
    }
    return ans;
    
}

vector<int> getRightView(node* root){
    vector<int> ans;
    queue<pair<int, node*>> q;
    map<int,node*> nodes;
    if(root== NULL) return ans;
    q.push(make_pair(0,root));
    while (!q.empty())
    {
        pair<int, node*> temp=q.front();
        q.pop();
        node* curr= temp.second;
        int lvl=temp.first;
        nodes[lvl]=curr;
        if(curr->left) q.push(make_pair(lvl+1, curr->left));
        if(curr->right) q.push(make_pair(lvl+1, curr->right));
    }
    for(auto i: nodes){
        ans.push_back(i.second->data);
    }
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
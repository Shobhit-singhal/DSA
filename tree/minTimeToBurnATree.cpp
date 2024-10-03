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
void createMap(node* root, map<node*,node*>& nodeToParent){
    queue<node*> q;
    q.push(root);
    nodeToParent[root]=NULL;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            node* temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                nodeToParent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                nodeToParent[temp->right]=temp;
            }
        }
    }
    
}
node* findNode(node* root,int target){
    if(root==NULL)  return NULL;
    if(root->data==target)  return root;

    node* left=findNode(root->left, target);
    node* right=findNode(root->right, target);

    if(left!=NULL)  return left;
    if(right!=NULL)  return right;
    return NULL;
}
int minTimeToBurn(node* root, int target){
    if (root == NULL) return 0; 
    map<node*,node*> nodeToParent;
    createMap(root,nodeToParent);
    map<node*,bool> visited;
    node* start=findNode(root,target);
    queue<node*> q;
    q.push(start);
    visited[start]=true;
    int  time=0;
    while(!q.empty()){
        bool inserted=false;
        int size=q.size();
        for(int i=0;i<size;i++){
            node* temp=q.front();
            q.pop();
            node* parent=nodeToParent[temp];
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
                inserted=true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
                inserted=true;
            }
            if(parent && !visited[parent]){
                q.push(parent);
                visited[parent]=true;
                inserted=true;
            }
        }
        if(inserted)    time++;
    }
    return time;

}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Target node to start burning from
    int target = 5;

    // Call the minTimeToBurn function
    int result = minTimeToBurn(root, target);

    // Output the result
    cout << "Minimum time to burn the tree starting from node " << target << " is: " << result << endl;

    return 0;
}
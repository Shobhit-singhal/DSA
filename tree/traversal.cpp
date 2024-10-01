#include<iostream>
#include<queue>
#include<stack>
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

node* buildTree(node* root){
    cout<<"Enter data"<<endl;
    int val;
    cin>>val;
    root=new node(val);
    if(val==-1) return NULL;

    cout<<"For left of: "<<root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"For right of: "<<root->data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }else{
            cout<<endl;
            if(!q.empty())  q.push(NULL);
        }
    }
}
void reverseTravel(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            s.push(temp);
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }else{
            s.push(NULL);
            if(!q.empty())  q.push(NULL);
        }
    }
    while(!s.empty()){
        node* temp=s.top();
        s.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
        }else
            cout<<endl;
    }
}
void dfs(node* root){
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
}
void inOrder(node* root){
    if(root==NULL)  return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(node* root){
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root){
    if(root==NULL)  return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root=buildTree(NULL);
    cout<<"BFS: "<<endl;
    bfs(root);
    cout<<endl<<"reverse order traversal"<<endl;
    reverseTravel(root);
    cout<<endl<<"DFS"<<endl;
    dfs(root);
    cout<<endl<<"In-order traversal"<<endl;
    inOrder(root);
    cout<<endl<<"pre-order traversal"<<endl;
    preOrder(root);
    cout<<endl<<"post-order traversal"<<endl;
    postOrder(root);
}
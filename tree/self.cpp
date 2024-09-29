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
int main(){
    node* root=buildTree(NULL);
    cout<<"BFS: "<<endl;
    bfs(root);
    cout<<endl<<"reverse order traversal"<<endl;
    reverseTravel(root);
}
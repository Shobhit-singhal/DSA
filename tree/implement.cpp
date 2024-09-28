#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};
node* buildTree(node* root){
    int val;
    cout<<"Enter the data: "<<endl;;
    cin>>val;
    root=new node(val);

    if(val==-1)
        return NULL;

    cout<<"For left of "<< root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"For right of "<< root->data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty())  q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
int main(){
    node* root=NULL;
    root=buildTree(root);
    bfs(root);
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
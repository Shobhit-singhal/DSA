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


void buildTreeFromTraversal(node* &root){
    queue<node*> q;
    int val;
    cout<<"Enter data: ";
    cin>>val;
    root=new node(val);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        int leftData;
        cout<<"Enter data for left of "<<temp->data<<" :";
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        int rightData;
        cout<<"Enter data for right of "<<temp->data<<" :";
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
        cout<<endl;
    }
}
int getHeight(node* root){
    if(root==NULL)  
        return 0;
    int left=getHeight(root->left);
    int right=getHeight(root->right);
    int ans=max(left,right)+1;
    return ans;
}
int main(){
    node* root=NULL;
    // root=buildTree(root);
    buildTreeFromTraversal(root);
    bfs(root);
    cout<<"Height of tree is: "<<getHeight(root);
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
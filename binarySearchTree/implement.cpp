#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left,*right;
        node(int data){
            this->data=data;
            left=right=NULL;
        }
};

node* insert(node* root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
    if(val>root->data)
        root->right=insert(root->right,val);
    else    
        root->left=insert(root->left,val);
    return root;
}
void buildTree(node* &root){
    int data;
    cin>>data;
    while (data!=-1)
    {
        root= insert(root,data);
        cin>>data;
    }
}

void inorder(node* root){
    if(root==NULL)  return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


bool isPresent(node* root,int data){
    if(root==NULL)  return false;
    if(root->data==data) return true;
    bool ans;
    if(root->data>data)
        ans=isPresent(root->left,data);
    else
        ans=isPresent(root->right,data);
    return ans;
}

bool isPresentIterative(node* root,int x){
    node* curr=root;
    while(curr!=NULL){
        if(curr->data==x)   return true;
        if(curr->data<x)    curr=curr->right;
        else    curr=curr->left;
    }
    return false;
}

pair<int,int> getMinMax(node* root){
    pair<int,int> ans;
    node* curr;
    curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    ans.first=curr->data;
    curr=root;
    while (curr->right!=NULL)
    {
        curr=curr->right;
    }
    ans.second=curr->data;
    return ans;
    
}

void findPreSuc(node* root,int x, node*& pre, node*& suc){
    if(root==NULL)  return;
    findPreSuc(root->left,x,pre,suc);

    if(root->data>x){
        if((!suc) || (suc->data>root->data))    
            suc=root;
    }
    else if(root->data < x){
        if(!pre || (pre->data < root->data))
            pre=root;
    }
    findPreSuc(root->right,x,pre,suc);
}

int getMin(node* root){
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
    
}
node* remove(node* root,int x){
    if(root==NULL)  return NULL;
    node* temp=NULL;
    if(root->data==x){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left==NULL && root->right!=NULL)  { 
            temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right==NULL)   { 
            temp=root->left;
            delete root;
            return temp;
        }
        else{
            int min=getMin(root->right);
            root->data=min;
            root->right=remove(root->right,min);
            return root;

        }

        
    }
    else if(root->data<x){
        root->right=remove(root->right,x);
    }
    else{
        root->left=remove(root->left,x);
    }

    return root;
}
int main(){
    node* root=NULL;
    buildTree(root);
    inorder(root);

    int x=100;
    cout<<endl<<x<<" present or not: "<<isPresent(root,x)<<endl;
    cout<<endl<<x<<" present or not: "<<isPresentIterative(root,x);
    pair<int,int> ans=getMinMax(root);
    cout<<endl<<"Min: "<<ans.first<<" Max: "<<ans.second<<endl;
    node* pre=NULL, *suc=NULL;
    findPreSuc(root,30,pre,suc);
    cout<<"Pre: "<<pre->data<<" Suc: "<<suc->data<<endl;
    
    root=remove(root,20);
    inorder(root);
}
//50 30 20 40 70 60 80 -1
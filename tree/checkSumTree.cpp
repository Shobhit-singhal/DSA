#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left,* right;
        node(int data){
            this->data=data;
            left=right=NULL;
        }
};
pair<int,bool> check(node* root){
    if(root==NULL)  return make_pair(0,true);
    if(root->left == NULL && root->right== NULL)
        return make_pair(root->data, true);
    
    pair<int,bool> left=check(root->left);
    pair<int,bool> right=check(root->right);
    pair<int,bool> ans;
    ans.first=left.first+ right.first+ root->data;
    ans.second=left.second && right.second &&(left.first+right.first==root->data);
    return ans;
}
bool isSumtree(node* root){
    return check(root).second;
}
int main(){
    node* root= new node(3);
    root->left= new node(1);
    root->right= new node(2);
    cout<<isSumtree(root);

}
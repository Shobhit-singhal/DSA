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
void solve( node* root, int sum, int& maxSum, int len, int& maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }
        else if(len==maxLen){
            maxSum=max( maxSum, sum);
        }
        return ;
    }
    sum+=root->data;
    len++;
    solve(root->left,sum,maxSum,len,maxLen);
    solve(root->right,sum,maxSum,len,maxLen);
}
int longestSum(node* root){
    int sum=0,maxSum=0,len=0,maxLen=0;
    solve(root,sum,maxSum,len,maxLen);
    return maxSum;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    
    
    int result = longestSum(root);
    cout << "The maximum sum of the longest path is: " << result << endl;

    
    

    return 0;
}
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
void insert(vector<int>& dists,int dist){
    for(int i:dists){
        if( i== dist )
            return;
    }
    dists.push_back(dist);
}
vector<vector<int>> verticalTraversal(node* root) {
        vector<vector<int>> ans;
        map<int, map<int,vector<int>> >nodes;
        if(root==NULL)  return ans; 
        queue<pair<node*, pair<int , int> > > q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<node*, pair<int , int> > temp;
            temp=q.front();
            q.pop();
            node* curr= temp.first;
            int lvl=temp.second.first;
            int dist=temp.second.second;
            nodes[dist][lvl].push_back(curr->data);
            if(curr->left)  q.push(make_pair(curr->left, make_pair(lvl+1,dist-1)));
            if(curr->right)  q.push(make_pair(curr->right, make_pair(lvl+1,dist+1)));
        }
        for(auto& p : nodes) {
            vector<int> col;
            for(auto& q : p.second) {
                // Sort nodes at the same level by their values
                sort(q.second.begin(), q.second.end());
                // Add sorted nodes to the current column
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right=new node(3);
    root->right->left=new node(6);
    root->right->right=new node(7);

    
    vector<vector<int>> ans=verticalTraversal(root);
    for(int i=0;i<ans.size();i++){  
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    
    
}
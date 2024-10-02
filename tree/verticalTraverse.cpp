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
vector<vector<int>> vertical(node* root){
    vector<vector<int>> ans;
    vector<int> dists;
    queue<pair<node*, int>> q;
    map<int, vector<int>> nodes;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*, int> temp=q.front();
        q.pop();
        node* curr=temp.first;
        int dist=temp.second;
        insert(dists,dist);
        nodes[dist].push_back(curr->data);
        if(curr->left)  q.push(make_pair(curr->left,dist-1));
        if(curr->right)  q.push(make_pair(curr->right,dist+1));
    }
    sort(dists.begin(),dists.end());
    for(int dist: dists){
        ans.push_back(nodes[dist]);
    }
    // for (auto it = nodes.begin(); it != nodes.end(); ++it) {
    //     ans.push_back(it->second); // Add values corresponding to each distance
    // }

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

    
    vector<vector<int>> ans=vertical(root);
    for(int i=0;i<ans.size();i++){  
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    
    
}
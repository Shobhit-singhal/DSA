#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left, *right;
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

vector<vector<int>> vertical(node* root) {
    vector<vector<int>> ans;           // Resulting vertical order
    if (root == nullptr) return ans;   // Handle empty tree case

    queue<pair<node*, int>> q;         // Pair of node and its horizontal distance
    map<int, vector<int>> nodes;        // Map to store nodes at each horizontal distance

    q.push(make_pair(root, 0)); // Start with the root at distance 0

    while (!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();
        node* curr = temp.first;    // Current node
        int dist = temp.second;      // Horizontal distance

        nodes[dist].push_back(curr->data); // Store current node's data

        // Push left and right children with updated distances
        if (curr->left) q.push(make_pair(curr->left, dist - 1));
        if (curr->right) q.push(make_pair(curr->right, dist + 1));
    }

    // Collect results in vertical order based on distance
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        ans.push_back(it->second); // Add values corresponding to each distance
    }

    return ans; // Return the final vertical order
}

int main() {
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
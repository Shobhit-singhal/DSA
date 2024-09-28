#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> mat,int a,int b){
    return(mat[a][b]);
}

int find(vector<vector<int>> mat, int n){
    stack<int> s;
    for(int i=0;i<n;i++)
        s.push(i);

    while(s.size()!=1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();

        if(knows(mat,a,b))
            s.push(b);
        else
            s.push(a);
    }
    int el=s.top();
    bool potential=false;
    for(int i=0;i<n;i++){
        if(i==el || (knows(mat,i,el) && !knows(mat, el,i) ))
            potential=true;
        else{
            potential=false;
            break;
        }
    }
    return potential?el:-1;
}
int main(){
    vector<vector<int>> mat={{0,1},{1,0}};
    // vector<vector<int>> mat={{0,1,0},{0,0,0},{0,1,0}};
    cout<<find(mat,mat.size());
}
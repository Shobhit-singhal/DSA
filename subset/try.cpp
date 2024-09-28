#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,int n,vector<vector<int>>& m,vector<vector<int>>& visited){
    if((x>=0 && x<n) && (y>=0 && y<n) && !visited[x][y] && m[x][y])
        return 1;
    return 0;
}


void solve(int x,int y,int n,vector<vector<int>>&m, vector<vector<int>>& visited,vector<string>& ans,string path){
    // vector<vector<int>> ans;
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;

    int newx,newy;

    newx=x+1;
    newy=y;
    if(isSafe(newx,newy,n,m,visited)){
        path.push_back('D');
        solve(newx,newy,n,m,visited,ans,path);
        path.pop_back();
    }


    newx=x;
    newy=y+1;
    if(isSafe(newx,newy,n,m,visited)){
        path.push_back('R');
        solve(newx,newy,n,m,visited,ans,path);
        path.pop_back();
    }


    newx=x-1;
    newy=y;
    if(isSafe(newx,newy,n,m,visited)){
        path.push_back('U');
        solve(newx,newy,n,m,visited,ans,path);
        path.pop_back();
    }


    newx=x;
    newy=y-1;
    if(isSafe(newx,newy,n,m,visited)){
        path.push_back('L');
        solve(newx,newy,n,m,visited,ans,path);
        path.pop_back();
    }
    visited[x][y]=0;

}

vector<string> getAns(vector<vector<int>> m){
    vector<vector<int>> visited(m);
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m.size();j++){
            visited[i][j]=0;
        }
    }
    vector<string> ans;
    string path="";

    solve(0,0,m.size(),m,visited,ans,path);
    return ans;
}
int main(){
    vector<vector<int>> m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans=getAns(m);
    for(string st:ans)
        cout<<st<<endl;
}
#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>> &m,int n,vector<vector<int>> &visited,int x,int y){
    if((x>=0 && x<n) && (y>=0 && y<n) && !visited[x][y] && m[x][y]){
        return 1;
    }
    return 0;
}

void solve(vector<vector<int>> &m,int n,vector<string> &ans,vector<vector<int>> &visited,string &output,int x,int y){
    // cout<<"j"<<endl;
    if(x==n-1 && y==n-1){
        ans.push_back(output);
        return;
    }
    visited[x][y]=1;

    //you can go 4 ways so:
    int newx,newy;

    //going down
    newx=x+1,newy=y;
    if(isSafe(m,n,visited,newx,newy)){
        output.push_back('D');
        solve(m,n,ans,visited,output,newx,newy);
        output.pop_back();
    }

    //going right
    newx=x,newy=y+1;
    if(isSafe(m,n,visited,newx,newy)){
        output.push_back('R');
        solve(m,n,ans,visited,output,newx,newy);
        output.pop_back();
    }
    //going up
    newx=x-1,newy=y;
    if(isSafe(m,n,visited,newx,newy)){
        output.push_back('U');
        solve(m,n,ans,visited,output,newx,newy);
        output.pop_back();
    }

    //going left
    newx=x,newy=y-1;
    if(isSafe(m,n,visited,newx,newy)){
        output.push_back('R');
        solve(m,n,ans,visited,output,newx,newy);
        output.pop_back();
    }


    visited[x][y]=0;
}
vector<string> getAns(vector<vector<int>> &m,int n){
    vector<string> ans;
    vector<vector<int>> visited=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    string output;
    int x=0;    
    int y=0;
    solve(m,n,ans,visited,output,x,y);
    return ans;
}
int main(){
    vector<vector<int>> m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans=getAns(m,m.size());
    for(string st:ans)
        cout<<st<<endl;

}
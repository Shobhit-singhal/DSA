#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmall(vector<int>& arr,int n){
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int el=arr[i];
        while(stack.top()!=-1 && arr[stack.top()]>=el)
            stack.pop();
        ans[i]=stack.top();
        stack.push(i);
    }
    return ans;
}
vector<int> nextSmall(vector<int>& arr,int n){
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int el=arr[i];
        while(stack.top()!=-1 && arr[stack.top()]>=el)
            stack.pop();
        ans[i]=(stack.top()==-1)?n:stack.top();
        stack.push(i);
    }
    return ans;
}


int getMaxArea(vector<int>& heights,int n){
    // int n=heights.size();
    vector<int> next=nextSmall(heights,n);
    vector<int> prev=prevSmall(heights,n);
    int maxi=-1;
    for(int i=0;i<n;i++){
        int l=heights[i];
        int b=next[i]-prev[i]-1;
        int area=l*b;
        maxi=max(maxi,area);
    }
    return maxi;
}

int maximalRectangle(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> arr(m);
    int maxa=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0)
                arr[j]=0;
            else    
                arr[j]+=matrix[i][j];
        }
        int area=getMaxArea(arr,m);
        maxa=max(maxa,area);
    }
    return maxa;
}
int main(){
    vector<vector<int>> matrix={{1,1},{1,1}};
    // vector<vector<int>> matrix={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout<<"Max area: "<<maximalRectangle(matrix);
    return 0;
}
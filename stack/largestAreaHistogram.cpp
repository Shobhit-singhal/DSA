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


int getMaxArea(vector<int>& heights){
    int n=heights.size();
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
int main(){
    vector<int> heights={2,4};
    cout<<"Max area: "<<getMaxArea(heights);
    return 0;
}
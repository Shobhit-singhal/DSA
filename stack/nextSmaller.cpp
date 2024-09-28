#include<bits/stdc++.h>
using namespace std;


vector<int> getSmaller(vector<int>& arr,int n){
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int el=arr[i];
        while(stack.top()>=el)
            stack.pop();
        ans[i]=stack.top();
        stack.push(el);
    }
    return ans;
}
int main(){
    vector<int> arr={1,3,2};
    int n=arr.size();
    vector<int> ans=getSmaller(arr,n);
    for(int el: ans)
        cout<<el<<" ";
}
#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int> arr,int n,int k){
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<k;i++)
        if(arr[i]<0)
            dq.push_back(i);

    if(dq.empty()){
        ans.push_back(0);
    }else{
        ans.push_back(arr[dq.front()]);
    }

    for(int i=k;i<n;i++){
        if(!dq.empty() && dq.front()<=(i-k))
            dq.pop_front();
        if(arr[i]<0)
            dq.push_back(i);
        if(dq.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
int main(){
    vector<int> arr={-1,8,7,5,-3,4,-2};
    vector<int> ans=firstNegative(arr,arr.size(),2);
    for(int el:ans)
        cout<<el<<" ";
    cout<<endl;
}
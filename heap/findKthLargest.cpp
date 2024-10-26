#include<bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> nums, int k){
    priority_queue<int,vector<int>, greater<int>> q;
    int n=nums.size();
    for(int i=0; i<k; i++){
        q.push(nums[i]);
    }
    for(int i=k;i<n;i++){
        if(nums[i]>q.top()){
            q.pop();
            q.push(nums[i]);
        }
    }
    return q.top();
}
int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    int result = getKthLargest(nums, k);
    cout << "The " << k << "-th largest element is: " << result << endl;
    
    return 0;
}
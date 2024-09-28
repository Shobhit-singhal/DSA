#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int> arr1,int size1,vector<int> arr2,int size2){
    vector<int> ans;
    int sum,carry=0,temp;
    int ptr1=size1-1,ptr2=size2-1;
    while(ptr1>=0 && ptr2>=0){
        temp=arr1[ptr1--]+arr2[ptr2--]+carry;
        sum=temp%10;
        cout<<sum<<endl;
        carry=temp/10;
        ans.push_back(sum);
    }
    while(ptr1>=0){
        temp=arr1[ptr1--]+carry;
        sum=temp%10;
        cout<<sum<<endl;
        carry=temp/10;
        ans.push_back(sum);
    }
    while(ptr2>=0){
        temp=arr2[ptr2--]+carry;
        sum=temp%10;
        cout<<sum<<endl;
        carry=temp/10;
        ans.push_back(sum);
    }
    while(carry!=0){
        temp=carry;
        sum=temp%10;
        cout<<sum<<endl;
        carry=temp/10;
        ans.push_back(sum);
    }
    return ans;
}
int main(){
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);


    vector <int> ans=add(arr1,3,arr2,3);
    for (int i:ans){
        cout<<i<< " ";
    }
}
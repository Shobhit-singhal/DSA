#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1="{([])}";
    stack<char> st;
    for(char ch:s1){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty())
                return 0;
            char el=st.top();
            if((ch==')' && el=='(') || (ch=='}' && el=='{')  || (ch==']' && el=='[') ){
                st.pop();
                
            }
            else{
                    return 0;
            }
        }
    }
    return st.empty();
}